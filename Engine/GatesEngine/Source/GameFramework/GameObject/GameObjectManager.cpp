#include "..\..\..\Header\GameFramework\GameObject\GameObjectManager.h"

void GE::GameObjectManager::Destroy()
{
	if (destroyGameObjects.size() == 0)return;

	// 登録されているタグを走査
	for (auto& destroyTagObjects : destroyGameObjects)
	{
		// そのタグで登録されているゲームオブジェクトを削除していく
		for (auto& destroyObject : destroyTagObjects.second)
		{
			std::string tag = destroyTagObjects.first;

			// もとの配列から削除していく
			for (auto& gameObject : gameObjects[tag])
			{
				if (destroyObject == gameObject)
				{
					//if (gameObject == inspectorGui.CurrentSelectGameObject())
					//{
					//	inspectorGui.SetCurrentSelectGameObject(nullptr);
					//}

					std::swap(gameObject, gameObjects[tag].back());
					gameObjects[tag].pop_back();

					gameObject->OnDestroy();
					delete gameObject;
					gameObject = nullptr;
					break;
				}
			}
		}
		destroyTagObjects.second.clear();
	}
	destroyGameObjects.clear();
}

void GE::GameObjectManager::ResetTag()
{
	if (resetTagGameObjects.size() == 0)return;

	// 登録されているタグを走査
	for (auto& resetTagObjects : resetTagGameObjects)
	{
		// そのタグで登録されている配列を更新する
		for (auto& resetTagObject : resetTagObjects.second)
		{
			// 再設定前のタグ
			std::string beforeTag = resetTagObjects.first;
			// もとの配列から削除していく
			for (auto& gameObject : gameObjects[beforeTag])
			{
				if (resetTagObject == gameObject)
				{
					// もとのタグ配列から登録を解除
					std::swap(gameObject, gameObjects[beforeTag].back());
					gameObjects[beforeTag].pop_back();

					// 新しく設定されたタグとゲームオブジェクトたちを管理している配列に追加する
					// 再設定後のタグ
					std::string currentTag = gameObject->GetTag();
					gameObjects[currentTag].push_back(gameObject);

					break;
				}
			}
		}
		resetTagObjects.second.clear();
	}
	resetTagGameObjects.clear();
}

GE::GameObjectManager::GameObjectManager()
{
}

GE::GameObjectManager::~GameObjectManager()
{
	DestroyGameObjects();
}

void GE::GameObjectManager::Awake()
{
	for (auto& tagGameObjects : gameObjects)
	{
		for (auto& gameObject : tagGameObjects.second)
		{
			gameObject->Awake();
		}
	}
}

void GE::GameObjectManager::Start()
{
	// プログラム上（vs上）で追加したゲームオブジェクトに対してタグを再設定している可能性があるから一度配列を更新確認
	// タグが再設定されていた際に一度配列を更新する
	ResetTag();
	for (auto& tagGameObjects : gameObjects)
	{
		for (auto& gameObject : tagGameObjects.second)
		{
			gameObject->Start();
		}
	}
}

void GE::GameObjectManager::Update(float deltaTime)
{
	// タグが再設定されていた際に一度配列を更新する
	ResetTag();
	// 削除予定のゲームオブジェクトを削除
	Destroy();

	for (auto& tagGameObjects : gameObjects)
	{
		for (auto& gameObject : tagGameObjects.second)
		{
			gameObject->Update(deltaTime);
		}
	}
}

void GE::GameObjectManager::Draw()
{
	for (auto& tagGameObjects : gameObjects)
	{
		for (auto& gameObject : tagGameObjects.second)
		{
			gameObject->Draw();
		}
	}
}

void GE::GameObjectManager::LateDraw()
{
	for (auto& tagGameObjects : gameObjects)
	{
		for (auto& gameObject : tagGameObjects.second)
		{
			gameObject->LateDraw();
		}
	}
}

std::vector<GE::GameObject*>& GE::GameObjectManager::GetGameObjects(const std::string& tag)
{
	return gameObjects[tag];
}

GE::GameObject* GE::GameObjectManager::AddGameObject(GameObject* newGameObject)
{
	if (newGameObject == nullptr)return nullptr;

	gameObjects[newGameObject->GetTag()].emplace_back(newGameObject);
	newGameObject->SetManager(this);
	return newGameObject;
}

GE::GameObject* GE::GameObjectManager::FindGameObject(const std::string& name)
{
	for (auto& tagGameObjects : gameObjects)
	{
		for (auto& gameObject : tagGameObjects.second)
		{
			if (gameObject->GetName() == name)return gameObject;
		}
	}

	return nullptr;
}

GE::GameObject* GE::GameObjectManager::FindGameObject(const std::string& name, const std::string& tag)
{
	// そのタグがそもそも登録されていないから即リターン
	if (gameObjects.find(tag) == gameObjects.end())return nullptr;

	for (auto& gameObject : gameObjects[tag])
	{
		if (gameObject->GetName() == name)return gameObject;
	}

	return nullptr;
}

void GE::GameObjectManager::ResetTagGameObject(GameObject* gameObject, const std::string& beforeTag)
{
	if (gameObject == nullptr)return;
	// 再設定前のタグで登録
	resetTagGameObjects[beforeTag].push_back(gameObject);
}

void GE::GameObjectManager::DestroyGameObject(const std::string& name)
{
	GameObject* gameObject = FindGameObject(name);
	if (gameObject == nullptr)return;
	DestroyGameObject(gameObject);
}

void GE::GameObjectManager::DestroyGameObject(const std::string& name, const std::string& tag)
{
	GameObject* gameObject = FindGameObject(name,tag);
	if (gameObject == nullptr)return;
	DestroyGameObject(gameObject);
}

void GE::GameObjectManager::DestroyGameObject(GameObject* gameObject)
{
	if (gameObject == nullptr)return;

	destroyGameObjects[gameObject->GetTag()].emplace_back(gameObject);
}

void GE::GameObjectManager::DestroyGameObjects()
{
	for (auto& tagGameObjects : gameObjects)
	{
		for (auto& tagGameObject : tagGameObjects.second)
		{
			DestroyGameObject(tagGameObject);
		}
	}

	Destroy();
}
