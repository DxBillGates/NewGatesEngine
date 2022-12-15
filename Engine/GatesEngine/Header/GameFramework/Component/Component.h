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
		bool isEnable;
	public:
		Component();
		virtual ~Component() {}
		virtual void Awake() {}
		virtual void Start() {}
		virtual void Update(float deltaTime) {}
		virtual void Draw() {}
		virtual void LateDraw() {}

		virtual void OnDestroy() {}
		virtual void OnGUI() {}
		virtual void OnSerialize() {}

		const GameObject* GetGameObject();
		bool IsEnabled();

		void SetGameObject(GameObject* setObject);
	};
}

