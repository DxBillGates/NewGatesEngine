#pragma once
#include "GameObject.h"
#include "IGameObjectManager.h"

namespace GE
{
	class GameObjectManager : public IGameObjectManager
	{
	private:
		using TagGameObjects = std::map<std::string, std::vector<GameObject*>>;

		TagGameObjects gameObjects;
		TagGameObjects destroyGameObjects;
		TagGameObjects resetTagGameObjects;
	private:
		// �폜�\��̃Q�[���I�u�W�F�N�g���폜����
		void Destroy();
		// �O�t���[���Ƀ^�O���ύX����Ă����ꍇ�Q�[���I�u�W�F�N�g�ƃ^�O���ꏏ�ɊǗ����Ă���z����X�V����
		void ResetTag();
	public:
		GameObjectManager();
		~GameObjectManager();

		void Awake();
		void Start();
		void Update(float deltaTime);
		void Draw();
		void LateDraw();

		// �w�肵���^�O�Ƃ��ēo�^����Ă���Q�[���I�u�W�F�N�g�̔z���Ԃ�
		std::vector<GameObject*>& GetGameObjects(const std::string& tag)override;
		GameObject* AddGameObject(GameObject* newGameObject)override;
		// �w�肵�����O�̃Q�[���I�u�W�F�N�g��Ԃ�
		GameObject* FindGameObject(const std::string& name)override;
		// �w�肵�����O�ƃ^�O�̃Q�[���I�u�W�F�N�g��Ԃ�
		GameObject* FindGameObject(const std::string& name, const std::string& tag)override;
		// �w�肵���Q�[���I�u�W�F�N�g�Ƃ��̃^�O���ꏏ�ɊǗ����Ă���z������̃t���[���J�n���ɍX�V����
		void ResetTagGameObject(GameObject* gameObject, const std::string& beforeTag)override;
		// �w�肵�����O�̃Q�[���I�u�W�F�N�g�����̃t���[���J�n���ɍ폜����
		void DestroyGameObject(const std::string& name)override;
		// �w�肵�����O�ƃ^�O�̃Q�[���I�u�W�F�N�g�����̃t���[���J�n���ɍ폜����
		void DestroyGameObject(const std::string& name, const std::string& tag)override;
		// �w�肵���Q�[���I�u�W�F�N�g�����̃t���[���J�n���ɍ폜����
		void DestroyGameObject(GameObject* gameObject)override;
		// ���ׂẴQ�[���I�u�W�F�N�g���������폜����
		void DestroyGameObjects();

		//bool Raycast(const Math::Vector3& pos, const Math::Vector3& dir, const std::string& tag, float length = 1000000, float* hitLenght = nullptr)override;
	};
}
