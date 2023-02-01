#pragma once
#include <random>
namespace GE
{
	namespace Utility
	{
		class RandomMaker
		{
		private:
			static std::mt19937_64 rnd;
		public:
			/// <summary>
			/// �V�[�h�̃��Z�b�g
			/// </summary>
			static void Reset();
			/// <summary>
			/// �͈͂��w�肵�ă����_���Ȓl��Ԃ�(int)
			/// </summary>
			/// <param name="minValue">�͈� ��</param>
			/// <param name="maxValue">�͈� ��</param>
			/// <returns>�͈͎w�肵�������_���Ȓl</returns>
			static int GetInt(int minValue, int maxValue);
			/// <summary>
			/// �͈͂��w�肵�ă����_���Ȓl��Ԃ�(float)
			/// </summary>
			/// <param name="minValue">�͈� ��</param>
			/// <param name="maxValue">�͈� ��</param>
			/// <returns>�͈͎w�肵�������_���Ȓl</returns>
			static float GetFloat(float minValue, float maxValue);
		};
	}
}