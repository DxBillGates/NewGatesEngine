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
			/// フレームの時間を図るためのスタート関数
			/// </summary>
			void Start();
			/// <summary>
			/// フレームの時間を図るためのエンド関数
			/// </summary>
			/// <param name="isShow">msを表示するか</param>
			/// <param name="addComment">追加コメント</param>
			/// <returns>経過時間(s)</returns>
			float End(bool isShow = true, const char* addComment = "");
		};
	}
}
