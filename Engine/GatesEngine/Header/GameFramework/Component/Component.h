#pragma once
#include "..\..\Util\Math\Transform.h"
#include <string>

namespace GE
{
	namespace GameFramework
	{
		class GameObject;
		// ���ׂẴR���|�[�l���g�̊��N���X
		// �Q�[���I�u�W�F�N�g�ɂ��������Ǔ����蔻��Ƃ��̖��ʂȏ����͂���Ȃ��ȁ`���ĂƂ��Ɍp��
		class Component
		{
		private:
		protected:
			std::string name;
			GameObject* gameObject;
			bool isEnable;
			Math::Transform* transform;
		public:
			Component();
			virtual ~Component() {}
			virtual void Awake() {}
			virtual void Start() {}
			virtual void Update(float deltaTime) {}
			virtual void LateUpdate(float deltaTime) {}
			virtual void Draw() {}
			virtual void LateDraw() {}

			virtual void OnDestroy() {}
			virtual void OnGUI() {}
			virtual void OnSerialize() {}

			const GameObject* GetGameObject();
			bool IsEnabled();

			void SetGameObject(GameObject* setObject);
		};
	}
}

