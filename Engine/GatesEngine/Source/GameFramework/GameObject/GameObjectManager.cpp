#include "..\..\..\Header\GameFramework\GameObject\GameObjectManager.h"

void GE::GameFramework::GameObjectManager::Destroy()
{
	if (destroyGameObjectCount == 0)return;

	// 登録されているタグを走査&削除
	// remove_ifでisDestroyがtrueになっているオブジェクトを配列から削除していく
	for (auto& destroyTagObjects : managedTagGameObjects)
	{
		auto removeIfResult = std::remove_if(destroyTagObjects.second.begin(), destroyTagObjects.second.end(), [](GameObject* object)
			{
				bool isDestroy = object->IsDestroy();
				return isDestroy;
			});
		destroyTagObjects.second.erase(removeIfResult, destroyTagObjects.second.end());
	}

	// タグは管理していない配列の方も削除する
	// こっちでゲームオブジェクト自体も削除する
	auto removeIfResult = std::remove_if(gameObjects.begin(), gameObjects.end(), [](GameObject* object)
		{
			bool isDestroy = object->IsDestroy();
			object->OnDestroy();
			return isDestroy;
		});
	gameObjects.erase(removeIfResult, gameObjects.end());


	destroyGameObjectCount = 0;
}

GE::GameFramework::GameObjectManager::GameObjectManager()
	: destroyGameObjectCount(0)
{
}

GE::GameFramework::GameObjectManager::~GameObjectManager()
{
	DestroyGameObjects();
}

void GE::GameFramework::GameObjectManager::Awake()
{
	for (auto& gameObject : gameObjects)
	{
		gameObject->Awake();
	}
}

void GE::GameFramework::GameObjectManager::Start()
{
	Awake();

	for (auto& gameObject : gameObjects)
	{
		gameObject->Start();
	}
}

void GE::GameFramework::GameObjectManager::Update(float deltaTime)
{
	// 削除予定のゲームオブジェクトを削除
	Destroy();

	for (auto& gameObject : gameObjects)
	{
		gameObject->Update(deltaTime);
	}

	LateUpdate(deltaTime);
}

void GE::GameFramework::GameObjectManager::LateUpdate(float deltaTime)
{
	for (auto& gameObject : gameObjects)
	{
		gameObject->LateUpdate(deltaTime);
	}
}

void GE::GameFramework::GameObjectManager::Draw()
{
	for (auto& gameObject : gameObjects)
	{
		gameObject->Draw();
	}
}

void GE::GameFramework::GameObjectManager::LateDraw()
{
	for (auto& gameObject : gameObjects)
	{
		gameObject->LateDraw();
	}
}

const std::vector<GE::GameFramework::GameObject*>* GE::GameFramework::GameObjectManager::GetGameObjects(const std::string& tag)
{
	return &managedTagGameObjects[tag];
}

GE::GameFramework::GameObject* GE::GameFramework::GameObjectManager::AddGameObject(GameObject* newGameObject)
{
	if (newGameObject == nullptr)return nullptr;

	managedTagGameObjects[newGameObject->GetTag()].emplace_back(newGameObject);
	gameObjects.emplace_back(newGameObject);

	newGameObject->SetManager(this);
	return newGameObject;
}

GE::GameFramework::GameObject* GE::GameFramework::GameObjectManager::FindGameObject(const std::string& name)
{
	for (auto& tagGameObjects : managedTagGameObjects)
	{
		for (auto& gameObject : tagGameObjects.second)
		{
			if (gameObject->GetName() == name)return gameObject;
		}
	}

	return nullptr;
}

GE::GameFramework::GameObject* GE::GameFramework::GameObjectManager::FindGameObject(const std::string& name, const std::string& tag)
{
	// そのタグがそもそも登録されていないから即リターン
	if (managedTagGameObjects.find(tag) == managedTagGameObjects.end())return nullptr;

	for (auto& gameObject : managedTagGameObjects[tag])
	{
		if (gameObject->GetName() == name)return gameObject;
	}

	return nullptr;
}

void GE::GameFramework::GameObjectManager::ResetTagGameObject(GameObject* gameObject, const std::string& beforeTag)
{
	if (gameObject == nullptr)return;

	for (auto& tagGameObject : managedTagGameObjects[beforeTag])
	{
		if (tagGameObject == gameObject)
		{
			// 再設定前のタグで登録
			std::swap(tagGameObject, managedTagGameObjects[beforeTag].back());
			managedTagGameObjects[beforeTag].pop_back();
			break;
		}
	}

	managedTagGameObjects[gameObject->GetTag()].push_back(gameObject);
}

void GE::GameFramework::GameObjectManager::DestroyGameObject(const std::string& name)
{
	GameObject* gameObject = FindGameObject(name);
	if (gameObject == nullptr)return;
	DestroyGameObject(gameObject);
}

void GE::GameFramework::GameObjectManager::DestroyGameObject(const std::string& name, const std::string& tag)
{
	GameObject* gameObject = FindGameObject(name, tag);
	if (gameObject == nullptr)return;
	DestroyGameObject(gameObject);
}

void GE::GameFramework::GameObjectManager::DestroyGameObject(GameObject* gameObject)
{
	if (gameObject == nullptr)return;

	// 次のフレーム開始時に削除予定のオブジェクトの数を増やす
	++destroyGameObjectCount;
}

void GE::GameFramework::GameObjectManager::DestroyGameObjects()
{
	// タグと一緒に管理してる配列の方から削除処理
	for (auto& tagGameObjects : managedTagGameObjects)
	{
		// すべての要素を削除させるから++itはいらない
		// eraseで次のitを取得できるから
		for (auto it = tagGameObjects.second.begin(); it != tagGameObjects.second.end();)
		{
			it = tagGameObjects.second.erase(it);
		}
	}

	// タグは管理してない配列の削除処理
	for (auto it = gameObjects.begin(); it != gameObjects.end();)
	{
		(*it)->OnDestroy();
		it = gameObjects.erase(it);
	}

}
