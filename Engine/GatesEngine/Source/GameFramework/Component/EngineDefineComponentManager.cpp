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

GE::Component* GE::EngineDefineComponentManager::GetComponent(const std::string& componentName)
{
	for (auto& component : registerComponents)
	{
		if (componentName != component.first)continue;

		return component.second();
	}
	return nullptr;
}
