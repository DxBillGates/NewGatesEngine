#include "..\..\..\Header\GameFramework\Component\EngineDefineComponentManager.h"
#include "..\..\..\Header\GameFramework\Component\SampleComponent.h"
#include "..\..\..\Header\GameFramework\Component\SampleBehaviour.h"

GE::EngineDefineComponentManager::EngineDefineComponentManager()
{
}

GE::DefineComponentManager* GE::EngineDefineComponentManager::GetInstance()
{
	static EngineDefineComponentManager instance;
	return &instance;
}

void GE::EngineDefineComponentManager::Initialize()
{
	registerComponents["SampleComponent"] = [](){return new SampleComponent();};
	registerComponents["SampleBehaviour"] = [](){return new SampleBehaviour();};
}
