#include "..\..\..\Header\GameFramework\Component\Component.h"
#include "..\..\..\Header\GameFramework\GameObject\GameObject.h"

GE::Component::Component()
	: name("Component")
	, gameObject(nullptr)
	, isEnable(true)
{
}

const GE::GameObject* GE::Component::GetGameObject()
{
	return gameObject;
}

bool GE::Component::IsEnabled()
{
	return isEnable;
}

void GE::Component::SetGameObject(GameObject* setObject)
{
	gameObject = setObject;
	transform = gameObject->GetTransform();
}
