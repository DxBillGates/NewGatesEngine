#pragma once
#include <string>

namespace GE
{
	namespace GameFramework
	{
		class IScene
		{
		public:
			virtual void LoadContents() = 0;
			virtual void Load() = 0;
			virtual void Start() = 0;
			virtual void Update(float deltaTime) = 0;
			virtual void Draw() = 0;
			virtual void UnLoad() = 0;

			virtual const std::string& GetName() = 0;
			/// <summary>
			/// シーンからアプリを終了するかどうかを返す
			/// </summary>
			/// <returns>シーンからアプリを終了するかどうか</returns>
			virtual bool IsTerminateApplication() = 0;
		protected:
			virtual void SetName(const std::string& setName) = 0;
			virtual void SetIsTerminateApplication(bool flag) = 0;
		};
	}
}
