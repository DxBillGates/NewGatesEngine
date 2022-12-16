#include "..\..\..\Header\GameFramework\Component\DefineComponentManager.h"

GE::Component* GE::DefineComponentManager::GetComponent(const std::string& componentName)
{
	for (auto& component : registerComponents)
	{
		if (componentName != component.first)continue;

		return component.second();
	}
	return nullptr;
}
