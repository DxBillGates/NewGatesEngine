#pragma once
#include <Windows.h>

namespace GE
{
	namespace Utility
	{
		class Timer
		{
		private:
			LARGE_INTEGER timeStart;
			LARGE_INTEGER timeEnd;
			LARGE_INTEGER timeFreq;
		public:
			Timer();
			virtual ~Timer();

			/// <summary>
			/// �t���[���̎��Ԃ�}�邽�߂̃X�^�[�g�֐�
			/// </summary>
			void Start();
			/// <summary>
			/// �t���[���̎��Ԃ�}�邽�߂̃G���h�֐�
			/// </summary>
			/// <param name="isShow">ms��\�����邩</param>
			/// <param name="addComment">�ǉ��R�����g</param>
			/// <returns>�o�ߎ���(s)</returns>
			float End(bool isShow = true, const char* addComment = "");
		};
	}
}
