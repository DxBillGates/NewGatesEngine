#include "..\..\..\Header\Util\Math\Vector2.h"
#include "..\..\..\Header\Util\Math\Math.h"

GE::Math::Vector2::Vector2()
	: x(0)
	, y(0)
{
}

GE::Math::Vector2::Vector2(float xy)
	: x(xy)
	, y(xy)
{
}

GE::Math::Vector2::Vector2(float x, float y)
	: x(x)
	, y(y)
{
}

float GE::Math::Vector2::Length() const
{
	return Math::Sqrt(x * x + y * y);
}

GE::Math::Vector2 GE::Math::Vector2::Normalize() const
{
	float length = Length();
	if (length == 0)return Vector2();
	return *this / length;
}

//float GE::Math::Vector2::Cross(const Vector2& v) const
//{
//	float result;
//	result = x * v.y;
//	result -= y * v.x;
//	return result;
//}

//float GE::Math::Vector2::Dot(const Vector2& v) const
//{
//	float result;
//	result = x * v.x + y * v.y;
//	return result;
//}

float GE::Math::Vector2::Distance(const Vector2& p1, const Vector2& p2)
{
	Vector2 v = p2 - p1;
	return v.Length();
}

GE::Math::Vector2 GE::Math::Vector2::Normalize(const Vector2& v)
{
	return v.Normalize();
}

float GE::Math::Vector2::Cross(const Vector2& v1, const Vector2& v2)
{
	float result;
	result = v1.x * v2.y;
	result -= v1.y * v2.x;
	return result;
}

float GE::Math::Vector2::Dot(const Vector2& v1, const Vector2& v2)
{
	float result;
	result = v1.x * v2.x + v1.y * v2.y;
	return result;
}

GE::Math::Vector2 GE::Math::Vector2::Lerp(const Vector2& v1, const Vector2& v2, float t)
{
	if (t < 0)t = 0;
	if (t > 1)t = 1;
	return v1 * (1.f - t) + v2 * t;
}

GE::Math::Vector2 GE::Math::Vector2::Min(const Vector2& minVector, const Vector2& comparison)
{
	Vector2 result;
	result.x = Math::Min(minVector.x, comparison.x);
	result.y = Math::Min(minVector.y, comparison.y);
	return result;
}

GE::Math::Vector2 GE::Math::Vector2::Max(const Vector2& maxVector, const Vector2& comparison)
{
	Vector2 result;
	result.x = Math::Max(maxVector.x, comparison.x);
	result.y = Math::Max(maxVector.y, comparison.y);
	return result;
}

GE::Math::Vector2 GE::Math::Vector2::Clamp(const Vector2& minVector, const Vector2& maxVector, const Vector2& comparison)
{
	Vector2 result;
	result = Min(Max(comparison, minVector), maxVector);
	return result;
}

GE::Math::Vector2 GE::Math::Vector2::operator-()const
{
	Vector2 result(-x, -y);
	return result;
}

const GE::Math::Vector2 GE::Math::Vector2::operator+(const Vector2& v) const
{
	Vector2 result;
	result.x = x + v.x;
	result.y = y + v.y;
	return result;
}

const GE::Math::Vector2 GE::Math::Vector2::operator-(const Vector2& v) const
{
	Vector2 result;
	result.x = x - v.x;
	result.y = y - v.y;
	return result;
}

const GE::Math::Vector2 GE::Math::Vector2::operator*(const Vector2& v) const
{
	Vector2 result;
	result.x = x * v.x;
	result.y = y * v.y;
	return result;
}

const GE::Math::Vector2 GE::Math::Vector2::operator/(const Vector2& v) const
{
	Vector2 result;
	result.x = x / v.x;
	result.y = y / v.y;
	return result;
}

GE::Math::Vector2& GE::Math::Vector2::operator+=(const Vector2& v)
{
	x += v.x;
	y += v.y;
	return *this;
}

GE::Math::Vector2& GE::Math::Vector2::operator-=(const Vector2& v)
{
	x -= v.x;
	y -= v.y;
	return *this;
}

GE::Math::Vector2& GE::Math::Vector2::operator*=(const Vector2& v)
{
	x *= v.x;
	y *= v.y;
	return *this;
}

GE::Math::Vector2& GE::Math::Vector2::operator/=(const Vector2& v)
{
	x /= v.x;
	y /= v.y;
	return *this;
}

const GE::Math::Vector2 GE::Math::Vector2::operator*(float value) const
{
	Vector2 result;
	result.x = x * value;
	result.y = y * value;
	return result;
}

const GE::Math::Vector2 GE::Math::Vector2::operator/(float value) const
{
	Vector2 result;
	result.x = x / value;
	result.y = y / value;
	return result;
}

GE::Math::Vector2& GE::Math::Vector2::operator*=(float value)
{
	x *= value;
	x *= value;
	return *this;
}

GE::Math::Vector2& GE::Math::Vector2::operator/=(float value)
{
	x /= value;
	x /= value;
	return *this;
}

GE::Math::Vector2Int::Vector2Int()
	: x(0)
	, y(0)
{
}

GE::Math::Vector2Int::Vector2Int(int xy)
	: x(xy)
	, y(xy)
{
}

GE::Math::Vector2Int::Vector2Int(int x, int y)
	: x(x)
	, y(y)
{
}

GE::Math::Vector2Int::Vector2Int(const Vector2& v)
	: x((int)v.x)
	, y((int)v.y)
{
}

GE::Math::Vector2Int GE::Math::Vector2Int::operator-()
{
	Vector2Int result(-x, -y);
	return result;
}

const GE::Math::Vector2Int GE::Math::Vector2Int::operator+(const Vector2Int& v) const
{
	return Vector2Int();
}

const GE::Math::Vector2Int GE::Math::Vector2Int::operator-(const Vector2Int& v) const
{
	return Vector2Int();
}

const GE::Math::Vector2Int GE::Math::Vector2Int::operator*(const Vector2Int& v) const
{
	return Vector2Int();
}

const GE::Math::Vector2Int GE::Math::Vector2Int::operator/(const Vector2Int& v) const
{
	return Vector2Int();
}

GE::Math::Vector2Int& GE::Math::Vector2Int::operator+=(const Vector2Int& v)
{
	x += v.x;
	y += v.y;
	return *this;
}

GE::Math::Vector2Int& GE::Math::Vector2Int::operator-=(const Vector2Int& v)
{
	x -= v.x;
	y -= v.y;
	return *this;
}

GE::Math::Vector2Int& GE::Math::Vector2Int::operator*=(const Vector2Int& v)
{
	x *= v.x;
	y *= v.y;
	return *this;
}

GE::Math::Vector2Int& GE::Math::Vector2Int::operator/=(const Vector2Int& v)
{
	x /= v.x;
	y /= v.y;
	return *this;
}

const GE::Math::Vector2Int GE::Math::Vector2Int::operator*(int value) const
{
	Vector2Int result;
	result.x = x * value;
	result.y = y * value;
	return result;
}

const GE::Math::Vector2Int GE::Math::Vector2Int::operator/(int value) const
{
	Vector2Int result;
	result.x = x / value;
	result.y = y / value;
	return result;
}

GE::Math::Vector2Int& GE::Math::Vector2Int::operator*=(int value)
{
	x *= value;
	y *= value;
	return *this;
}

GE::Math::Vector2Int& GE::Math::Vector2Int::operator/=(int value)
{
	x /= value;
	y /= value;
	return *this;
}
