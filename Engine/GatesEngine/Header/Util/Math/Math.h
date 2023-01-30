#pragma once

// cmathÇÃÉâÉbÉpÅ[

namespace GE
{
	namespace Math
	{
		const float PI = 3.141592f;
		const float TO_DEGREE = 180.f / PI;
		const float TO_RADIAN = PI / 180.f;

		bool Approximately(float comparison, float value);

		float ConvertToDegree(float value);
		float ConvertToRadian(float value);

		float Lerp(float s, float e, float t);

		float Abs(float value);
		float Sqrt(float value);
		float Pow(float value, float n);
		float Min(float a, float b);
		float Max(float a, float b);

		float Sin(float value);
		float Cos(float value);
		float Tan(float value);
		float Asin(float value);
		float Acos(float value);
		float Atan(float value);
		float Atan2(float y, float x);
	}
}
