#include "..\..\..\Header\GameFramework\GameObject\GameObject.h"
#include "..\..\..\Header\GameFramework\Component\Component.h"

GE::DefineComponentManager* GE::GameObject::engineDefineComponentManager = nullptr;
GE::DefineComponentManager* GE::GameObject::userDefineComponentManager = nullptr;

GE::GameObject::GameObject(const std::string& name, const std::string& tag)
	: gameObjectManager(nullptr)
	, name(name)
	, tag(tag)
	, isEnable(false)
	, isDestroy(false)
{
}

GE::GameObject::~GameObject()
{
	for (auto& component : components)
	{
		delete component;
	}
	for (auto& behaviour : scriptComponents)
	{
		delete behaviour;
	}
}

void GE::GameObject::Awake()
{
	for (auto& component : components)
	{
		component->Awake();
	}
	for (auto& behaviour : scriptComponents)
	{
		behaviour->Awake();
	}
}

void GE::GameObject::Start()
{
	for (auto& component : components)
	{
		component->Start();
	}
	for (auto& behaviour : scriptComponents)
	{
		behaviour->Start();
	}
}

void GE::GameObject::Update(float deltaTime)
{
	for (auto& component : components)
	{
		if (component->IsEnabled() == false)continue;
		component->Update(deltaTime);
	}
	for (auto& behaviour : scriptComponents)
	{
		if (behaviour->IsEnabled() == false)continue;
		behaviour->Update(deltaTime);
	}
}

void GE::GameObject::Draw()
{
	for (auto& component : components)
	{
		if (component->IsEnabled() == false)continue;
		component->Draw();
	}
	for (auto& behaviour : scriptComponents)
	{
		if (behaviour->IsEnabled() == false)continue;
		behaviour->Draw();
	}
}

void GE::GameObject::LateDraw()
{
	for (auto& component : components)
	{
		if (component->IsEnabled() == false)continue;
		component->LateDraw();
	}
	for (auto& behaviour : scriptComponents)
	{
		if (behaviour->IsEnabled() == false)continue;
		behaviour->LateDraw();
	}
}

void GE::GameObject::OnCollision(GameObject* other, bool enter, bool stay, bool exit)
{
	for (auto& behaviour : scriptComponents)
	{
		if (enter)behaviour->OnCollisionEnter(other);
		if (stay)behaviour->OnCollisionStay(other);
		if (exit)behaviour->OnCollisionExit(other);
	}
}

GE::IGameObjectManager* GE::GameObject::GetManager()
{
	return gameObjectManager;
}

const std::string& GE::GameObject::GetName()
{
	return name;
}

const std::string& GE::GameObject::GetTag()
{
	return tag;
}

const std::string& GE::GameObject::GetLayer()
{
	return layer;
}

void GE::GameObject::SetManager(IGameObjectManager* manager)
{
	gameObjectManager = manager;
}

void GE::GameObject::SetName(const std::string& setName)
{
	name = setName;
}

void GE::GameObject::SetTag(const std::string& setTag)
{
	std::string beforeTag = tag;
	tag = setTag;

	if (gameObjectManager == nullptr)return;
	gameObjectManager->ResetTagGameObject(this, beforeTag);
}

void GE::GameObject::SetLayer(const std::string& setLayer)
{
	layer = setLayer;
}

void GE::GameObject::SetEnabled(bool flag)
{
	isEnable = flag;
}

GE::Component* GE::GameObject::AddComponent(const std::string& componentName)
{
	if (engineDefineComponentManager == nullptr || userDefineComponentManager == nullptr)return nullptr;

	// engine側で定義されているコンポーネントから探す
	Component* component = static_cast<Component*>(engineDefineComponentManager->GetComponent(componentName));
	Behaviour* behaviour = dynamic_cast<Behaviour*>(component);

	// 見つからなかった場合はuser側で定義されているか再度探す
	if (component == nullptr && behaviour == nullptr)
	{
		component = static_cast<Component*>(userDefineComponentManager->GetComponent(componentName));
		behaviour = dynamic_cast<Behaviour*>(component);
		// user側でも定義されていない場合は即リターン
		if (component == nullptr && behaviour == nullptr)return nullptr;
	}

	// どちらかで見つかったらコンポーネントなのかビヘイビアなのかを確認
	if (behaviour)scriptComponents.push_back(behaviour);
	else if (component)components.push_back(component);

	component->SetGameObject(this);

	return component;
}

void GE::GameObject::OnDestroy()
{
	for (auto& component : components)
	{
		component->OnDestroy();
	}
	for (auto& behaviour : scriptComponents)
	{
		behaviour->OnDestroy();
	}
}

void GE::GameObject::OnSerialize()
{
	for (auto& component : components)
	{
		component->OnSerialize();
	}
	for (auto& behaviour : scriptComponents)
	{
		behaviour->OnSerialize();
	}
}

bool GE::GameObject::IsEnabled()
{
	return isEnable;
}

bool GE::GameObject::IsDestroy()
{
	return isDestroy;
}

GE::Math::Transform* GE::GameObject::GetTransform()
{
	return &transform;
}

void GE::GameObject::Destroy()
{
	isDestroy = true;
	gameObjectManager->DestroyGameObject(this);
}

void GE::GameObject::SetDefineComponentManager(DefineComponentManager* engineDefine, DefineComponentManager* userDefine)
{
	engineDefineComponentManager = engineDefine;
	userDefineComponentManager = userDefine;
}
