#pragma once
#include <string>
#include <vector>

namespace GE
{
	namespace IO
	{
		// directory���w�肵�Ă���directory���ł̃t�@�C�����[�h�֌W���s����N���X
		class DirectoryFileLoader
		{
		private:
			std::string directoryPath;
		public:
			/// <param name="directoryPath">���΃p�X�Ńt�H���_��(��:resources,texture)�A�X���b�V���͂��Ȃ�</param>
			DirectoryFileLoader(const std::string& directoryPath);

			/// <summary>
			/// �f�B���N�g���̍Đݒ�
			/// </summary>
			/// <param name="setDirectorypath">�ݒ肵�����f�B���N�g���p�X</param>
			void SetDirectory(const std::string& setDirectorypath);

			/// <summary>
			/// directory���̎w�肵���g���q�̃t�@�C���p�X���ꗗ�擾����֐�
			/// </summary>
			/// <param name="extension">�g���q�w��@�w�薼+�g���q���\ �h�b�g�͂���</param>
			/// <param name="filenames">�ꗗ�擾���i�[���邽�߂̔z��</param>
			void GetFilepaths(const std::string& extension,std::vector<std::string>& filenames);
		};
	}
}
