#include "UserDefineComponentManager.h"

UserDefineComponentManager::UserDefineComponentManager()
{
}

GE::GameFramework::DefineComponentManager* UserDefineComponentManager::GetInstance()
{
	static UserDefineComponentManager instance;
	return &instance;
}

void UserDefineComponentManager::Initialize()
{
}