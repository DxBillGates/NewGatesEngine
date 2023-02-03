#include "..\..\..\Header\GameFramework\GameObject\GameObjectManager.h"

void GE::GameFramework::GameObjectManager::Destroy()
{
	if (destroyGameObjects.size() == 0)return;

	// �o�^����Ă���^�O�𑖍�
	for (auto& destroyTagObjects : destroyGameObjects)
	{
		// ���̃^�O�œo�^����Ă���Q�[���I�u�W�F�N�g���폜���Ă���
		for (auto& destroyObject : destroyTagObjects.second)
		{
			std::string tag = destroyTagObjects.first;

			// ���Ƃ̔z�񂩂�폜���Ă���
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

void GE::GameFramework::GameObjectManager::ResetTag()
{
	if (resetTagGameObjects.size() == 0)return;

	// �o�^����Ă���^�O�𑖍�
	for (auto& resetTagObjects : resetTagGameObjects)
	{
		// ���̃^�O�œo�^����Ă���z����X�V����
		for (auto& resetTagObject : resetTagObjects.second)
		{
			// �Đݒ�O�̃^�O
			std::string beforeTag = resetTagObjects.first;
			// ���Ƃ̔z�񂩂�폜���Ă���
			for (auto& gameObject : gameObjects[beforeTag])
			{
				if (resetTagObject == gameObject)
				{
					// ���Ƃ̃^�O�z�񂩂�o�^������
					std::swap(gameObject, gameObjects[beforeTag].back());
					gameObjects[beforeTag].pop_back();

					// �V�����ݒ肳�ꂽ�^�O�ƃQ�[���I�u�W�F�N�g�������Ǘ����Ă���z��ɒǉ�����
					// �Đݒ��̃^�O
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

GE::GameFramework::GameObjectManager::GameObjectManager()
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

	// �v���O������ivs��j�Œǉ������Q�[���I�u�W�F�N�g�ɑ΂��ă^�O���Đݒ肵�Ă���\�������邩���x�z����X�V�m�F
	// �^�O���Đݒ肳��Ă����ۂɈ�x�z����X�V����
	ResetTag();
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
	// �^�O���Đݒ肳��Ă����ۂɈ�x�z����X�V����
	ResetTag();
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
	// �Đݒ�O�̃^�O�œo�^
	resetTagGameObjects[beforeTag].push_back(gameObject);
}

void GE::GameFramework::GameObjectManager::DestroyGameObject(const std::string& name)
{
	GameObject* gameObject = FindGameObject(name);
	if (gameObject == nullptr)return;
	DestroyGameObject(gameObject);
}

void GE::GameFramework::GameObjectManager::DestroyGameObject(const std::string& name, const std::string& tag)
{
	GameObject* gameObject = FindGameObject(name,tag);
	if (gameObject == nullptr)return;
	DestroyGameObject(gameObject);
}

void GE::GameFramework::GameObjectManager::DestroyGameObject(GameObject* gameObject)
{
	if (gameObject == nullptr)return;

	destroyGameObjects[gameObject->GetTag()].emplace_back(gameObject);
}

void GE::GameFramework::GameObjectManager::DestroyGameObjects()
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
