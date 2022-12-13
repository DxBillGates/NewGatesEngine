#include "..\..\..\Header\GameFramework\GameObject\GameObject.h"
#include "..\..\..\Header\GameFramework\Component\Component.h"

GE::DefineComponentManager* GE::GameObject::engineDefineComponentManager = nullptr;
GE::DefineComponentManager* GE::GameObject::userDefineComponentManager = nullptr;

GE::GameObject::GameObject()
	: name("GameObject")
	, tag("none")
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
		component->Update(deltaTime);
	}
	for (auto& behaviour : scriptComponents)
	{
		behaviour->Update(deltaTime);
	}
}

GE::Component* GE::GameObject::AddComponent(const std::string& componentName)
{
	if (engineDefineComponentManager == nullptr || userDefineComponentManager == nullptr)return nullptr;

	// engine���Œ�`����Ă���R���|�[�l���g����T��
	Component* component = static_cast<Component*>(engineDefineComponentManager->GetComponent(componentName));
	Behaviour* behaviour = dynamic_cast<Behaviour*>(component);

	// ������Ȃ������ꍇ��user���Œ�`����Ă��邩�ēx�T��
	if (component == nullptr && behaviour == nullptr)
	{
		component = static_cast<Component*>(userDefineComponentManager->GetComponent(componentName));
		behaviour = dynamic_cast<Behaviour*>(component);
		// user���ł���`����Ă��Ȃ��ꍇ�͑����^�[��
		if (component == nullptr && behaviour == nullptr)return nullptr;
	}

	// �ǂ��炩�Ō���������R���|�[�l���g�Ȃ̂��r�w�C�r�A�Ȃ̂����m�F
	if (behaviour)scriptComponents.push_back(behaviour);
	else if (component)components.push_back(component);

	component->SetGameObject(this);

	return component;
}

void GE::GameObject::Destroy()
{
	isDestroy = true;
}

void GE::GameObject::SetDefineComponentManager(DefineComponentManager* engineDefine, DefineComponentManager* userDefine)
{
	engineDefineComponentManager = engineDefine;
	userDefineComponentManager = userDefine;
}
