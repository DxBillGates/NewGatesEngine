#include "UserDefineComponentManager.h"

UserDefineComponentManager::UserDefineComponentManager()
{
}

GE::DefineComponentManager* UserDefineComponentManager::GetInstance()
{
	static UserDefineComponentManager instance;
	return &instance;
}

void UserDefineComponentManager::Initialize()
{
}