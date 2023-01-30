#include "..\..\..\Header\Util\Math\Math.h"
#include <cmath>

bool GE::Math::Approximately(float comparison, float value)
{
	float epsilon = 0.0001f;
	float abs = Abs(comparison - value);
	bool isResult = abs <= epsilon;
	return isResult;
}

float GE::Math::ConvertToDegree(float value)
{
	if (value == 0)return 0;
	float result = TO_DEGREE * PI;
	return result;
}

float GE::Math::ConvertToRadian(float value)
{
	if (value == 0)return 0;
	float result = TO_RADIAN * value;
	return result;
}

float GE::Math::Lerp(float s, float e, float t)
{
	return s * (1.f - t) + e * t;
}

float GE::Math::Abs(float value)
{
	return std::fabsf(value);
}

float GE::Math::Sqrt(float value)
{
	return std::sqrtf(value);
}

float GE::Math::Pow(float value, float n)
{
	return std::powf(value,n);
}

float GE::Math::Min(float a, float b)
{
	return std::fminf(a,b);
}

float GE::Math::Max(float a, float b)
{
	return std::fmaxf(a,b);
}

float GE::Math::Sin(float value)
{
	return std::sinf(value);
}

float GE::Math::Asin(float value)
{
	return std::asinf(value);
}

float GE::Math::Cos(float value)
{
	return std::cosf(value);
}

float GE::Math::Acos(float value)
{
	return std::acosf(value);
}

float GE::Math::Tan(float value)
{
	return std::tanf(value);
}

float GE::Math::Atan(float value)
{
	return std::atan(value);
}

float GE::Math::Atan2(float y, float x)
{
	return std::atan2f(y,x);
}
