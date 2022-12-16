#pragma once
#include "Component.h"
#include <map>
#include <functional>

namespace GE
{
	class DefineComponentManager
	{
	protected:
		std::map<std::string, std::function<Component*()>> registerComponents;
	public:
		DefineComponentManager() {}
		virtual ~DefineComponentManager() {}
		// ��`����Ă���R���|�[�l���g���N���X�ɓo�^
		virtual void Initialize() {}
		// �o�^����Ă���R���|�[�l���g�̃C���X�^���X��Ԃ�
		Component* GetComponent(const std::string& componentName);
	};
}