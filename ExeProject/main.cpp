#include <GatesEngine/Header/Util/Utility.h>
#include <GatesEngine/Header/GameFramework/Component/EngineDefineComponentManager.h>
#include <GatesEngine/Header/GameFramework/Component/SampleComponent.h>
#include <GatesEngine/Header/GameFramework/Component/SampleBehaviour.h>
#include <GatesEngine/Header/GameFramework/GameObject/GameObject.h>
#include <GatesEngine/Header/GameFramework/GameObject/GameObjectManager.h>
#include <GatesEngine/Header/Util/Math/Transform.h>
#include <GatesEngine/Header/Util/Random.h>
#include <GatesEngine/Header/Util/Timer.h>

#include "UserDefineComponentManager.h"

int main()
{
	GE::Utility::Printf("test\n");
	GE::GameFramework::DefineComponentManager* engineDifineComponentManager = GE::GameFramework::EngineDefineComponentManager::GetInstance();
	GE::GameFramework::DefineComponentManager* userDefineComponentManager = UserDefineComponentManager::GetInstance();
	engineDifineComponentManager->Initialize();
	userDefineComponentManager->Initialize();

	GE::GameFramework::GameObject::SetDefineComponentManager(engineDifineComponentManager, userDefineComponentManager);

	GE::GameFramework::GameObjectManager gameObjectManager;

	auto gameObject = gameObjectManager.AddGameObject(new GE::GameFramework::GameObject());
	gameObject->AddComponent("SampleComponent");
	gameObject->AddComponent("SampleBehaviour");
	gameObject->SetTag("aa");

	gameObject = gameObjectManager.AddGameObject(new GE::GameFramework::GameObject());
	gameObject->AddComponent("SampleComponent");
	gameObject->AddComponent("SampleBehaviour");
	gameObject->SetTag("aa");

	gameObject = gameObjectManager.AddGameObject(new GE::GameFramework::GameObject());
	gameObject->AddComponent("SampleComponent");
	gameObject->AddComponent("SampleBehaviour");
	gameObject->SetTag("aa");

	gameObjectManager.Start();
	gameObjectManager.Update(0);
	gameObjectManager.Draw();
	gameObjectManager.LateDraw();
	gameObjectManager.DestroyGameObjects();

	return 0;
}