#include "..\..\..\Header\GameFramework\Component\EngineDefineComponentManager.h"
#include "..\..\..\Header\GameFramework\Component\SampleComponent.h"
#include "..\..\..\Header\GameFramework\Component\SampleBehaviour.h"

GE::GameFramework::EngineDefineComponentManager::EngineDefineComponentManager()
{
}

GE::GameFramework::DefineComponentManager* GE::GameFramework::EngineDefineComponentManager::GetInstance()
{
	static EngineDefineComponentManager instance;
	return &instance;
}

void GE::GameFramework::EngineDefineComponentManager::Initialize()
{
	registerComponents["SampleComponent"] = [](){return new SampleComponent();};
	registerComponents["SampleBehaviour"] = [](){return new SampleBehaviour();};
}
