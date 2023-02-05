#include "..\..\..\Header\GameFramework\GameObject\GameObjectManager.h"

void GE::GameFramework::GameObjectManager::Destroy()
{
	if (destroyGameObjectCount == 0)return;

	// �o�^����Ă���^�O�𑖍�&�폜
	for (auto& destroyTagObjects : gameObjects)
	{
		auto removeIfResult = std::remove_if(destroyTagObjects.second.begin(), destroyTagObjects.second.end(), [](GameObject* object)
			{
				bool isDestroy = object->IsDestroy();
				if (isDestroy)object->OnDestroy();
				return isDestroy;
			});
		destroyTagObjects.second.erase(removeIfResult, destroyTagObjects.second.end());
	}

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
	for (auto& tagGameObjects : gameObjects)
	{
		for (auto& gameObject : tagGameObjects.second)
		{
			gameObject->Awake();
		}
	}
}

void GE::GameFramework::GameObjectManager::Start()
{
	Awake();

	for (auto& tagGameObjects : gameObjects)
	{
		for (auto& gameObject : tagGameObjects.second)
		{
			gameObject->Start();
		}
	}
}

void GE::GameFramework::GameObjectManager::Update(float deltaTime)
{
	// �폜�\��̃Q�[���I�u�W�F�N�g���폜
	Destroy();

	for (auto& tagGameObjects : gameObjects)
	{
		for (auto& gameObject : tagGameObjects.second)
		{
			gameObject->Update(deltaTime);
		}
	}

	LateUpdate(deltaTime);
}

void GE::GameFramework::GameObjectManager::LateUpdate(float deltaTime)
{
	for (auto& tagGameObjects : gameObjects)
	{
		for (auto& gameObject : tagGameObjects.second)
		{
			gameObject->LateUpdate(deltaTime);
		}
	}
}

void GE::GameFramework::GameObjectManager::Draw()
{
	for (auto& tagGameObjects : gameObjects)
	{
		for (auto& gameObject : tagGameObjects.second)
		{
			gameObject->Draw();
		}
	}
}

void GE::GameFramework::GameObjectManager::LateDraw()
{
	for (auto& tagGameObjects : gameObjects)
	{
		for (auto& gameObject : tagGameObjects.second)
		{
			gameObject->LateDraw();
		}
	}
}

std::vector<GE::GameFramework::GameObject*>& GE::GameFramework::GameObjectManager::GetGameObjects(const std::string& tag)
{
	return gameObjects[tag];
}

GE::GameFramework::GameObject* GE::GameFramework::GameObjectManager::AddGameObject(GameObject* newGameObject)
{
	if (newGameObject == nullptr)return nullptr;

	gameObjects[newGameObject->GetTag()].emplace_back(newGameObject);
	newGameObject->SetManager(this);
	return newGameObject;
}

GE::GameFramework::GameObject* GE::GameFramework::GameObjectManager::FindGameObject(const std::string& name)
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

GE::GameFramework::GameObject* GE::GameFramework::GameObjectManager::FindGameObject(const std::string& name, const std::string& tag)
{
	// ���̃^�O�����������o�^����Ă��Ȃ����瑦���^�[��
	if (gameObjects.find(tag) == gameObjects.end())return nullptr;

	for (auto& gameObject : gameObjects[tag])
	{
		if (gameObject->GetName() == name)return gameObject;
	}

	return nullptr;
}

void GE::GameFramework::GameObjectManager::ResetTagGameObject(GameObject* gameObject, const std::string& beforeTag)
{
	if (gameObject == nullptr)return;

	for (auto& tagGameObject : gameObjects[beforeTag])
	{
		if (tagGameObject == gameObject)
		{
			// �Đݒ�O�̃^�O�œo�^
			std::swap(tagGameObject, gameObjects[beforeTag].back());
			gameObjects[beforeTag].pop_back();
			break;
		}
	}

	gameObjects[gameObject->GetTag()].push_back(gameObject);
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

	// ���̃t���[���J�n���ɍ폜�\��̃I�u�W�F�N�g�̐��𑝂₷
	++destroyGameObjectCount;
}

void GE::GameFramework::GameObjectManager::DestroyGameObjects()
{
	for (auto& tagGameObjects : gameObjects)
	{
		// ���ׂĂ̗v�f���폜�����邩��++it�͂���Ȃ�
		// erase�Ŏ���it���擾�ł��邩��
		for (auto it = tagGameObjects.second.begin(); it != tagGameObjects.second.end();)
		{
			(*it)->OnDestroy();
			it = tagGameObjects.second.erase(it);
		}
	}
}
