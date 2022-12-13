#pragma once
#include <string>

namespace GE
{
	class GameObject;
	// すべてのコンポーネントの基底クラス
	// ゲームオブジェクトにつけたいけど当たり判定とかの無駄な処理はいらないな～ってときに継承
	class Component
	{
	private:
	protected:
		std::string name;
		GameObject* gameObject;
	public:
		Component();
		virtual ~Component() {}
		virtual void Awake() {}
		virtual void Start() {}
		virtual void Update(float deltaTime) {}

		virtual void OnDestroy() {}
		virtual void OnGUI() {}

		const GameObject* GetGameObject();
		void SetGameObject(GameObject* setObject);
	};
}

