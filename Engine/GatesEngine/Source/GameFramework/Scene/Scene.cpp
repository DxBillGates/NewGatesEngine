#include "..\..\..\Header\GameFramework\Scene\Scene.h"

GE::GameFramework::Scene::Scene()
	: Scene("UnnamedScene")
{
}

GE::GameFramework::Scene::Scene(const std::string& sceneName)
	: name(sceneName)
	, isTerminateApplication(false)
{
}

const std::string& GE::GameFramework::Scene::GetName()
{
	return name;
}

bool GE::GameFramework::Scene::IsTerminateApplication()
{
	return isTerminateApplication;
}

void GE::GameFramework::Scene::SetName(const std::string& setName)
{
	name = setName;
}

void GE::GameFramework::Scene::SetIsTerminateApplication(bool flag)
{
	isTerminateApplication = flag;
}
