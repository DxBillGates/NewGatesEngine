#pragma once
#include "DefineComponentManager.h"

namespace GE
{
	class EngineDefineComponentManager : public DefineComponentManager
	{
	public:
		static DefineComponentManager* GetInstance();
		void Initialize() override;
		Component* GetComponent(const std::string& componentName) override;
	private:
		EngineDefineComponentManager();
		EngineDefineComponentManager(const EngineDefineComponentManager&) = delete;
		~EngineDefineComponentManager() = default;
		EngineDefineComponentManager& operator=(const EngineDefineComponentManager&) = delete;
	};
}