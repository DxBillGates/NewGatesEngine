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
			/// シードのリセット
			/// </summary>
			static void Reset();
			/// <summary>
			/// 範囲を指定してランダムな値を返す(int)
			/// </summary>
			/// <param name="minValue">範囲 小</param>
			/// <param name="maxValue">範囲 大</param>
			/// <returns>範囲指定したランダムな値</returns>
			static int GetInt(int minValue, int maxValue);
			/// <summary>
			/// 範囲を指定してランダムな値を返す(float)
			/// </summary>
			/// <param name="minValue">範囲 小</param>
			/// <param name="maxValue">範囲 大</param>
			/// <returns>範囲指定したランダムな値</returns>
			static float GetFloat(float minValue, float maxValue);
		};
	}
}