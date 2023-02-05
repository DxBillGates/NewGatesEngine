#include <GatesEngine/Header/Util/Utility.h>
#include <GatesEngine/Header/GameFramework/Scene/SceneManager.h>
#include "SampleScene.h"

int main()
{
	GE::GameFramework::SceneManager sceneManager;
	sceneManager.Add(new SampleScene());
	GE::Utility::Printf("test\n");
	return 0;
}