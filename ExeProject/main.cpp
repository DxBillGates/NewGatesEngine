#include <GatesEngine/Header/Util/Utility.h>
#include <GatesEngine/Header/GameFramework/Component/EngineDefineComponentManager.h>
#include <GatesEngine/Header/GameFramework/Component/SampleComponent.h>
#include <GatesEngine/Header/GameFramework/Component/SampleBehaviour.h>
#include <GatesEngine/Header/GameFramework/GameObject/GameObject.h>
#include <GatesEngine/Header/GameFramework/GameObject/GameObjectManager.h>

#include "UserDefineComponentManager.h"

int main()
{
	GE::Utility::Printf("test\n");
	GE::DefineComponentManager* engineDifineComponentManager = GE::EngineDefineComponentManager::GetInstance();
	GE::DefineComponentManager* userDefineComponentManager = UserDefineComponentManager::GetInstance();
	engineDifineComponentManager->Initialize();
	userDefineComponentManager->Initialize();

	GE::GameObject::SetDefineComponentManager(engineDifineComponentManager, userDefineComponentManager);

	GE::GameObjectManager gameObjectManager;
	auto gameObject = gameObjectManager.AddGameObject(new GE::GameObject());
	gameObject->AddComponent("SampleComponent");
	gameObject->AddComponent("SampleBehaviour");
	gameObject->Update(1);

	return 0;
}