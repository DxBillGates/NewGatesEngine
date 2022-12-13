#include "..\..\..\Header\GameFramework\Component\Component.h"

GE::Component::Component()
	: name("Component")
	, gameObject(nullptr)
{
}

const GE::GameObject* GE::Component::GetGameObject()
{
	return gameObject;
}

void GE::Component::SetGameObject(GameObject* setObject)
{
	gameObject = setObject;
}
