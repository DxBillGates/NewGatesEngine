#pragma once
#include "..\Component\Component.h"
#include "..\Component\Behaviour.h"
#include "..\Component\DefineComponentManager.h"
#include <vector>

namespace GE
{
	class GameObject
	{
	private:
		std::string name;
		std::string tag;
		bool isEnable;
		bool isDestroy;
		std::vector<Component*> components;
		std::vector<Behaviour*> scriptComponents;

		static DefineComponentManager* engineDefineComponentManager;
		static DefineComponentManager* userDefineComponentManager;
	public:
		GameObject();
		~GameObject();
		void Awake();
		void Start();
		void Update(float deltaTime);

		template<typename T>
		const T* GetComponent() const;
		template<typename T>
		T* AddComponent();
		// 全コンポーネントが登録されているクラスから名前が一致するコンポーネントの型を取得
		Component* AddComponent(const std::string& componentName);
		template<typename T>
		void RemoveComponent();

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
		//Componentクラスから派生したものかチェック
		Component* pComponent = static_cast<Component*>(t);
		Behaviour* pBehaviour = static_cast<Behaviour*>(t);

		// ユーザーが定義したコンポーネントの場合
		if (pBehaviour != nullptr)
		{
			scriptComponents.push_back(pBehaviour);
			pBehaviour->SetGameObject(this);
			return t;
		}
		// エンジン実装のコンポーネントの場合
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
