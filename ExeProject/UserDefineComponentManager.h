#pragma once
#include <GatesEngine/Header/GameFramework/Component/DefineComponentManager.h>

class UserDefineComponentManager : public GE::GameFramework::DefineComponentManager
{
public:
	static DefineComponentManager* GetInstance();
	void Initialize() override;
private:
	UserDefineComponentManager();
	UserDefineComponentManager(const UserDefineComponentManager&) = delete;
	~UserDefineComponentManager() = default;
	UserDefineComponentManager& operator=(const UserDefineComponentManager&) = delete;
};
