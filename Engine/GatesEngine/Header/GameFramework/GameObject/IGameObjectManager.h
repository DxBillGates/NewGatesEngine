#pragma once
#include <map>
#include <vector>
#include <string>

namespace GE
{
	class GameObject;
	class IGameObjectManager
	{
	public:
		// 指定したタグとして登録されているゲームオブジェクトの配列を返す
		virtual std::vector<GameObject*>& GetGameObjects(const std::string& tag) = 0;
		virtual GameObject* AddGameObject(GameObject* newGameObject) = 0;
		// 指定した名前のゲームオブジェクトを返す
		virtual GameObject* FindGameObject(const std::string& name) = 0;
		// 指定した名前とタグのゲームオブジェクトを返す
		virtual GameObject* FindGameObject(const std::string& name, const std::string& tag) = 0;
		// 指定した名前のゲームオブジェクトを次のフレーム開始時に削除する
		virtual void DestroyGameObject(const std::string& name) = 0;
		// 指定した名前とタグのゲームオブジェクトを次のフレーム開始時に削除する
		virtual void DestroyGameObject(const std::string& name,const std::string& tag) = 0;
		// 指定したゲームオブジェクトを次のフレーム開始時に削除する
		virtual void DestroyGameObject(GameObject* gameObject) = 0;

		//virtual bool Raycast(const Math::Vector3& pos, const Math::Vector3& dir, const std::string& tag, float length = 1000000, float* hitLenght = nullptr);
	};
}
