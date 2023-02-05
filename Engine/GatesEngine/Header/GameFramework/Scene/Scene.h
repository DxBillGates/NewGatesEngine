#pragma once
#include "IScene.h"

namespace GE
{
	namespace GameFramework
	{
		class Scene : public IScene
		{
		private:
			std::string name;
			bool isTerminateApplication;
		public:
			Scene();
			Scene(const std::string& sceneName);
			virtual ~Scene() {}

			const std::string& GetName()override;
			bool IsTerminateApplication()override;

			void SetName(const std::string& setName)override;
			void SetIsTerminateApplication(bool flag)override;
		};
	}
}