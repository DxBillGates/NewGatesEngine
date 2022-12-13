#pragma once
#include <string>

namespace GE
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
	public:
		Component();
		virtual ~Component() {}
		virtual void Awake() {}
		virtual void Start() {}
		virtual void Update(float deltaTime) {}

		virtual void OnDestroy() {}
		virtual void OnGUI() {}

		const GameObject* GetGameObject();
		void SetGameObject(GameObject* setObject);
	};
}
