#include "..\..\..\Header\GameFramework\GameObject\GameObject.h"
#include "..\..\..\Header\GameFramework\Component\Component.h"

GE::GameFramework::GameObject::GameObject(const std::string& name, const std::string& tag)
	: gameObjectManager(nullptr)
	, name(name)
	, tag(tag)
	, isEnable(false)
	, isDestroy(false)
{
}

GE::GameFramework::GameObject::~GameObject()
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

void GE::GameFramework::GameObject::Awake()
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

void GE::GameFramework::GameObject::Start()
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

void GE::GameFramework::GameObject::Update(float deltaTime)
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

void GE::GameFramework::GameObject::LateUpdate(float deltaTime)
{
	for (auto& component : components)
	{
		if (component->IsEnabled() == false)continue;
		component->LateUpdate(deltaTime);
	}
	for (auto& behaviour : scriptComponents)
	{
		if (behaviour->IsEnabled() == false)continue;
		behaviour->LateUpdate(deltaTime);
	}
}

void GE::GameFramework::GameObject::Draw()
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

void GE::GameFramework::GameObject::LateDraw()
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

void GE::GameFramework::GameObject::OnCollision(GameObject* other, bool enter, bool stay, bool exit)
{
	for (auto& behaviour : scriptComponents)
	{
		if (enter)behaviour->OnCollisionEnter(other);
		if (stay)behaviour->OnCollisionStay(other);
		if (exit)behaviour->OnCollisionExit(other);
	}
}

GE::GameFramework::IGameObjectManager* GE::GameFramework::GameObject::GetManager()
{
	return gameObjectManager;
}

const std::string& GE::GameFramework::GameObject::GetName()
{
	return name;
}

const std::string& GE::GameFramework::GameObject::GetTag()
{
	return tag;
}

const std::string& GE::GameFramework::GameObject::GetLayer()
{
	return layer;
}

void GE::GameFramework::GameObject::SetManager(IGameObjectManager* manager)
{
	gameObjectManager = manager;
}

void GE::GameFramework::GameObject::SetName(const std::string& setName)
{
	name = setName;
}

void GE::GameFramework::GameObject::SetTag(const std::string& setTag)
{
	std::string beforeTag = tag;
	tag = setTag;

	if (gameObjectManager == nullptr)return;
	gameObjectManager->ResetTagGameObject(this, beforeTag);
}

void GE::GameFramework::GameObject::SetLayer(const std::string& setLayer)
{
	layer = setLayer;
}

void GE::GameFramework::GameObject::SetEnabled(bool flag)
{
	isEnable = flag;
}

GE::GameFramework::Component* GE::GameFramework::GameObject::AddComponent(const std::string& componentName)
{
	return nullptr;
}

void GE::GameFramework::GameObject::OnDestroy()
{
	for (auto& component : components)
	{
		component->OnDestroy();
	}
	for (auto& behaviour : scriptComponents)
	{
		behaviour->OnDestroy();
	}

	delete this;
}

void GE::GameFramework::GameObject::OnSerialize()
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

bool GE::GameFramework::GameObject::IsEnabled()
{
	return isEnable;
}

bool GE::GameFramework::GameObject::IsDestroy()
{
	return isDestroy;
}

GE::Math::Transform* GE::GameFramework::GameObject::GetTransform()
{
	return &transform;
}

void GE::GameFramework::GameObject::Destroy()
{
	isDestroy = true;
	gameObjectManager->DestroyGameObject(this);
}