#include <GatesEngine/Header/Util/Utility.h>
#include <GatesEngine/Header/GameFramework/Component/EngineDefineComponentManager.h>
#include <GatesEngine/Header/GameFramework/Component/SampleComponent.h>
#include <GatesEngine/Header/GameFramework/Component/SampleBehaviour.h>
#include <GatesEngine/Header/GameFramework/GameObject/GameObject.h>
#include <GatesEngine/Header/GameFramework/GameObject/GameObjectManager.h>
#include <GatesEngine/Header/Util/Math/Transform.h>
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
	gameObject->Update(1);

	gameObjectManager.Start();
	gameObjectManager.Update(0);

	GE::Math::Transform testTransform;
	auto axis = testTransform.GetAxis();
	testTransform.rotation = GE::Math::Quaternion::Euler(GE::Math::Vector3(90,0,0));
	axis = testTransform.GetAxis();
	return 0;
}