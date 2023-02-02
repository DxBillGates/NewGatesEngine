#pragma once
#include "Component.h"

namespace GE
{
	namespace GameFramework
	{
		// OnCollision�Ƃ����������R���|�[�l���g�̊��N���X
		// ��ɃQ�[���I�u�W�F�N�g�̓����Ȃǂ����ۂɌp��
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