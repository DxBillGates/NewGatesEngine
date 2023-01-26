#pragma once
#include "..\Component\Component.h"
#include "..\Component\Behaviour.h"
#include "..\Component\DefineComponentManager.h"
#include "IGameObjectManager.h"
#include <vector>

namespace GE
{
	class GameObject
	{
	private:
		// �o�^����Ă���}�l�[�W���[
		IGameObjectManager* gameObjectManager;

		std::string name;
		std::string tag;
		std::string layer;
		bool isEnable;
		bool isDestroy;
		std::vector<Component*> components;
		std::vector<Behaviour*> scriptComponents;

		static DefineComponentManager* engineDefineComponentManager;
		static DefineComponentManager* userDefineComponentManager;
	public:
		GameObject(const std::string& name = "unknown",const std::string& tag = "none");
		~GameObject();
		void Awake();
		void Start();
		void Update(float deltaTime);
		void Draw();
		void LateDraw();
		void OnCollision(GameObject* other, bool enter = false, bool stay = false, bool exit = false);
		void OnDestroy();
		void OnSerialize();

		bool IsEnabled();
		bool IsDestroy();

		IGameObjectManager* GetManager();
		const std::string& GetName();
		const std::string& GetTag();
		const std::string& GetLayer();

		void SetManager(IGameObjectManager* manager);
		void SetName(const std::string& setName);
		void SetTag(const std::string& setTag);
		void SetLayer(const std::string& setLayer);
		void SetEnabled(bool flag);

		// �ێ����Ă���R���|�[�l���g����T�^�ƈ�v����R���|�[�l���g��Ԃ�
		template<typename T>
		const T* GetComponent() const;
		// T�^�̃R���|�[�l���g��ǉ����Ԃ�
		template<typename T>
		T* AddComponent();
		// �S�R���|�[�l���g���o�^����Ă���N���X���疼�O����v����R���|�[�l���g�̌^���擾
		Component* AddComponent(const std::string& componentName);
		// T�^�̃R���|�[�l���g���f�^�b�`����
		template<typename T>
		void RemoveComponent();

		// ���̃t���[���J�n���ɓo�^����Ă���Ǘ��N���X����폜����
		void Destroy();

		static void SetDefineComponentManager(DefineComponentManager* engineDefine, DefineComponentManager* userDefine);
	};

	template<typename T>
	inline const T* GameObject::GetComponent() const
	{
		for (auto& component : components)
		{
			T* t = dynamic_cast<T*>(component);
			if (t == nullptr)continue;

			return t;
		}
		for (auto& behaviour : scriptComponents)
		{
			T* t = dynamic_cast<T*>(behaviour);
			if (t == nullptr)continue;

			return t;
		}

		return nullptr;
	}

	template<typename T>
	inline T* GameObject::AddComponent()
	{
		T* t = new T();
		//Component�N���X����h���������̂��`�F�b�N
		Component* pComponent = static_cast<Component*>(t);
		Behaviour* pBehaviour = static_cast<Behaviour*>(t);

		// ���[�U�[����`�����R���|�[�l���g�̏ꍇ
		if (pBehaviour != nullptr)
		{
			scriptComponents.push_back(pBehaviour);
			pBehaviour->SetGameObject(this);
			return t;
		}
		// �G���W�������̃R���|�[�l���g�̏ꍇ
		if (pComponent != nullptr)
		{
			components.push_back(pComponent);
			pComponent->SetGameObject(this);
			return t;
		}
		delete t;
		return nullptr;
	}

	template<typename T>
	inline void GameObject::RemoveComponent()
	{
		for (auto& component : components)
		{
			T* t = dynamic_cast<T*>(component);
			if (t == nullptr)continue;

			std::swap(component, components.back());
			components.pop_back();
		}
		for (auto& behaviour : scriptComponents)
		{
			T* t = dynamic_cast<T*>(behaviour);
			if (t == nullptr)continue;

			std::swap(behaviour, scriptComponents.back());
			scriptComponents.pop_back();
		}
	}
}
