#pragma once
#include "GameObject.h"
#include "IGameObjectManager.h"

namespace GE
{
	class GameObjectManager : public IGameObjectManager
	{
	private:
		using TagGameObjects = std::map<std::string, std::vector<GameObject*>>;

		TagGameObjects gameObjects;
		TagGameObjects destroyGameObjects;
		TagGameObjects resetTagGameObjects;
	private:
		// 削除予定のゲームオブジェクトを削除する
		void Destroy();
		// 前フレームにタグが変更されていた場合ゲームオブジェクトとタグを一緒に管理している配列を更新する
		void ResetTag();
	public:
		GameObjectManager();
		~GameObjectManager();

		void Awake();
		void Start();
		void Update(float deltaTime);
		void Draw();
		void LateDraw();

		// 指定したタグとして登録されているゲームオブジェクトの配列を返す
		std::vector<GameObject*>& GetGameObjects(const std::string& tag)override;
		GameObject* AddGameObject(GameObject* newGameObject)override;
		// 指定した名前のゲームオブジェクトを返す
		GameObject* FindGameObject(const std::string& name)override;
		// 指定した名前とタグのゲームオブジェクトを返す
		GameObject* FindGameObject(const std::string& name, const std::string& tag)override;
		// 指定したゲームオブジェクトとそのタグを一緒に管理している配列を次のフレーム開始時に更新する
		void ResetTagGameObject(GameObject* gameObject, const std::string& beforeTag)override;
		// 指定した名前のゲームオブジェクトを次のフレーム開始時に削除する
		void DestroyGameObject(const std::string& name)override;
		// 指定した名前とタグのゲームオブジェクトを次のフレーム開始時に削除する
		void DestroyGameObject(const std::string& name, const std::string& tag)override;
		// 指定したゲームオブジェクトを次のフレーム開始時に削除する
		void DestroyGameObject(GameObject* gameObject)override;
		// すべてのゲームオブジェクトを今すぐ削除する
		void DestroyGameObjects();

		//bool Raycast(const Math::Vector3& pos, const Math::Vector3& dir, const std::string& tag, float length = 1000000, float* hitLenght = nullptr)override;
	};
}
