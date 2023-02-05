#pragma once
#include <GatesEngine/Header/GameFramework/Scene/Scene.h>

class SampleScene : public GE::GameFramework::Scene
{
private:
public:
	SampleScene();
	SampleScene(const std::string& setName);

	void LoadContents()override;
	void Load()override;
	void Start()override;
	void Update(float deltaTime)override;
	void Draw()override;
	void UnLoad()override;
};
