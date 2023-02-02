#pragma once
#include "DefineComponentManager.h"

namespace GE
{
	namespace GameFramework
	{
		class EngineDefineComponentManager : public DefineComponentManager
		{
		public:
			static DefineComponentManager* GetInstance();
			void Initialize() override;
		private:
			EngineDefineComponentManager();
			EngineDefineComponentManager(const EngineDefineComponentManager&) = delete;
			~EngineDefineComponentManager() = default;
			EngineDefineComponentManager& operator=(const EngineDefineComponentManager&) = delete;
		};
	}
}