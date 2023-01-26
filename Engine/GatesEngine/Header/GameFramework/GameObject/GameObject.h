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
		// 登録されているマネージャー
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

		// 保持しているコンポーネントからT型と一致するコンポーネントを返す
		template<typename T>
		const T* GetComponent() const;
		// T型のコンポーネントを追加＆返す
		template<typename T>
		T* AddComponent();
		// 全コンポーネントが登録されているクラスから名前が一致するコンポーネントの型を取得
		Component* AddComponent(const std::string& componentName);
		// T型のコンポーネントをデタッチする
		template<typename T>
		void RemoveComponent();

		// 次のフレーム開始時に登録されている管理クラスから削除する
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
