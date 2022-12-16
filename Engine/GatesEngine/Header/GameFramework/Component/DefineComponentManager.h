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
		// 定義されているコンポーネントをクラスに登録
		virtual void Initialize() {}
		// 登録されているコンポーネントのインスタンスを返す
		Component* GetComponent(const std::string& componentName);
	};
}