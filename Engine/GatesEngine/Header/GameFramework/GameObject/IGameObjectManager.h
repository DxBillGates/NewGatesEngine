#pragma once
#include <map>
#include <vector>
#include <string>

namespace GE
{
	class GameObject;
	class IGameObjectManager
	{
	public:
		// �w�肵���^�O�Ƃ��ēo�^����Ă���Q�[���I�u�W�F�N�g�̔z���Ԃ�
		virtual std::vector<GameObject*>& GetGameObjects(const std::string& tag) = 0;
		virtual GameObject* AddGameObject(GameObject* newGameObject) = 0;
		// �w�肵�����O�̃Q�[���I�u�W�F�N�g��Ԃ�
		virtual GameObject* FindGameObject(const std::string& name) = 0;
		// �w�肵�����O�ƃ^�O�̃Q�[���I�u�W�F�N�g��Ԃ�
		virtual GameObject* FindGameObject(const std::string& name, const std::string& tag) = 0;
		// �w�肵�����O�̃Q�[���I�u�W�F�N�g�����̃t���[���J�n���ɍ폜����
		virtual void DestroyGameObject(const std::string& name) = 0;
		// �w�肵�����O�ƃ^�O�̃Q�[���I�u�W�F�N�g�����̃t���[���J�n���ɍ폜����
		virtual void DestroyGameObject(const std::string& name,const std::string& tag) = 0;
		// �w�肵���Q�[���I�u�W�F�N�g�����̃t���[���J�n���ɍ폜����
		virtual void DestroyGameObject(GameObject* gameObject) = 0;

		//virtual bool Raycast(const Math::Vector3& pos, const Math::Vector3& dir, const std::string& tag, float length = 1000000, float* hitLenght = nullptr);
	};
}
