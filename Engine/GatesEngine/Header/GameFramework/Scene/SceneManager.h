#pragma once
#include "IScene.h"
#include <vector>

namespace GE
{
	namespace GameFramework
	{
		class SceneManager
		{
		private:
			std::vector<IScene*> scenes;
			IScene* currentScene;
			IScene* beforeScene;
			IScene* addedScene;
		private:
			bool CheckCurrentScene();
		public:
			SceneManager();
			~SceneManager();

			void Start();
			void Update(float deltaTime);
			void Draw();

			void Add(IScene* newScene);
			void ChangeScene(const std::string& changeSceneName);
			IScene* GetCurrentScene();
			IScene* GetBeforeScene();
			IScene* GetAddScene();
			IScene* GetScene(const std::string& sceneName);
		};
	}
}