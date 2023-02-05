#include "..\..\..\Header\GameFramework\Scene\SceneManager.h"

bool GE::GameFramework::SceneManager::CheckCurrentScene()
{
	return currentScene;
}

GE::GameFramework::SceneManager::SceneManager()
	: currentScene(nullptr)
	, beforeScene(nullptr)
	, addedScene(nullptr)
{
}

GE::GameFramework::SceneManager::~SceneManager()
{
	for (auto& scene : scenes)
	{
		delete scene;
	}
}

void GE::GameFramework::SceneManager::Start()
{
	if (CheckCurrentScene() == false)return;
	currentScene->Start();
}

void GE::GameFramework::SceneManager::Update(float deltaTime)
{
	if (CheckCurrentScene() == false)return;
	currentScene->Update(deltaTime);
}

void GE::GameFramework::SceneManager::Draw()
{
	if (CheckCurrentScene() == false)return;
	currentScene->Draw();
}

void GE::GameFramework::SceneManager::Add(IScene* newScene)
{
	scenes.emplace_back(newScene);

	addedScene = newScene;
}

void GE::GameFramework::SceneManager::ChangeScene(const std::string& changeSceneName)
{
	// まず該当するシーンを探す
	IScene* findScene = GetScene(changeSceneName);

	if (findScene == nullptr)return;

	// 見つかってから今のシーンを終了させる
	currentScene->UnLoad();
	beforeScene = currentScene;
	currentScene = findScene;
}

GE::GameFramework::IScene* GE::GameFramework::SceneManager::GetCurrentScene()
{
	return currentScene;
}

GE::GameFramework::IScene* GE::GameFramework::SceneManager::GetBeforeScene()
{
	return beforeScene;
}

GE::GameFramework::IScene* GE::GameFramework::SceneManager::GetAddScene()
{
	return addedScene;
}

GE::GameFramework::IScene* GE::GameFramework::SceneManager::GetScene(const std::string& sceneName)
{
	IScene* findScene = nullptr;
	for (auto& scene : scenes)
	{
		if (scene->GetName() == sceneName)
		{
			findScene = scene;
			return findScene;
		}
	};

	return nullptr;
}
