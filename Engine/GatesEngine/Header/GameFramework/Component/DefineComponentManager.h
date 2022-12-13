#pragma once
#include "Component.h"
#include <map>
#include <functional>

namespace GE
{
	class DefineComponentManager
	{
	protected:
		std::map<std::string, std::function<Component*()>> registerComponents;
	public:
		DefineComponentManager() {}
		virtual ~DefineComponentManager() {}
		virtual void Initialize() {}
		virtual Component* GetComponent(const std::string& componentName) { return nullptr; }
	};
}