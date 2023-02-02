#pragma once
#include "Component.h"

namespace GE
{
	namespace GameFramework
	{
		// OnCollisionとかを持ったコンポーネントの基底クラス
		// 主にゲームオブジェクトの動きなどを作る際に継承
		class Behaviour : public Component
		{
		private:
		protected:
		public:
			Behaviour() {}
			virtual ~Behaviour() {}

			virtual void OnCollisionEnter(GameObject* other) {}
			virtual void OnCollisionStay(GameObject* other) {}
			virtual void OnCollisionExit(GameObject* other) {}
		};
	}
}