#include "..\..\..\Header\GameFramework\Component\Component.h"
#include "..\..\..\Header\GameFramework\GameObject\GameObject.h"

GE::GameFramework::Component::Component()
	: name("Component")
	, gameObject(nullptr)
	, isEnable(true)
{
}

const GE::GameFramework::GameObject* GE::GameFramework::Component::GetGameObject()
{
	return gameObject;
}

bool GE::GameFramework::Component::IsEnabled()
{
	return isEnable;
}

void GE::GameFramework::Component::SetGameObject(GameObject* setObject)
{
	gameObject = setObject;
	transform = gameObject->GetTransform();
}
