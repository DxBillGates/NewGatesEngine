#include "UserDefineComponentManager.h"

GE::DefineComponentManager* UserDefineComponentManager::GetInstance()
{
	static UserDefineComponentManager instance;
	return &instance;
}

void UserDefineComponentManager::Initialize()
{
}