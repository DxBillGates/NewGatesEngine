#include "..\..\..\Header\Util\Math\Vector4.h"
#include "..\..\..\Header\Util\Math\Math.h"

GE::Math::Vector4::Vector4()
	: x(0)
	, y(0)
	, z(0)
	, w(0)
{
}

GE::Math::Vector4::Vector4(float xyzw)
	: x(xyzw)
	, y(xyzw)
	, z(xyzw)
	, w(xyzw)
{
}

GE::Math::Vector4::Vector4(float x, float y, float z, float w)
	: x(x)
	, y(y)
	, z(z)
	, w(w)
{
}

GE::Math::Vector4::Vector4(float vector3Value[3])
	: x(value[0])
	, y(value[1])
	, z(value[2])
	, w(0)
{
}

float GE::Math::Vector4::Length() const
{
	float result;
	result = Math::Pow(x, 2.0f);
	result += Math::Pow(y, 2.0f);
	result += Math::Pow(z, 2.0f);
	result += Math::Pow(w, 2.0f);
	return Math::Sqrt(result);
}

GE::Math::Vector4 GE::Math::Vector4::Normalize() const
{
	float length = Length();
	if (length == 0)return Vector4();
	return *this / length;
}

GE::Math::Vector4 GE::Math::Vector4::Normalize(const Vector4& v)
{
	return v.Normalize();
}

GE::Math::Vector4 GE::Math::Vector4::Min(const Vector4& minVector, const Vector4& comparison)
{
	Vector4 result;
	result.x = Math::Min(minVector.x, comparison.x);
	result.y = Math::Min(minVector.y, comparison.y);
	result.z = Math::Min(minVector.z, comparison.z);
	result.w = Math::Min(minVector.w, comparison.w);
	return result;
}

GE::Math::Vector4 GE::Math::Vector4::Max(const Vector4& maxVector, const Vector4& comparison)
{
	Vector4 result;
	result.x = Math::Max(maxVector.x, comparison.x);
	result.y = Math::Max(maxVector.y, comparison.y);
	result.z = Math::Max(maxVector.z, comparison.z);
	result.w = Math::Max(maxVector.w, comparison.w);
	return result;
}

GE::Math::Vector4 GE::Math::Vector4::Clamp(const Vector4& minVector, const Vector4& maxVector, const Vector4& comparison)
{
	Vector4 result;
	result.x = Math::Min(Math::Max(comparison.x, minVector.x), maxVector.x);
	result.y = Math::Min(Math::Max(comparison.y, minVector.y), maxVector.y);
	result.z = Math::Min(Math::Max(comparison.z, minVector.z), maxVector.z);
	result.w = Math::Min(Math::Max(comparison.w, minVector.w), maxVector.w);
	return result;
}

GE::Math::Vector4 GE::Math::Vector4::operator-() const
{
	return Vector4(-x, -y, -z, -w);
}

const GE::Math::Vector4 GE::Math::Vector4::operator+(const Vector4& v) const
{
	Vector4 result;
	result.x = x + v.x;
	result.y = y + v.y;
	result.z = z + v.z;
	result.w = w + v.w;
	return result;
}

const GE::Math::Vector4 GE::Math::Vector4::operator-(const Vector4& v) const
{
	Vector4 result;
	result.x = x - v.x;
	result.y = y - v.y;
	result.z = z - v.z;
	result.w = w - v.w;
	return result;
}

const GE::Math::Vector4 GE::Math::Vector4::operator*(const Vector4& v) const
{
	Vector4 result;
	result.x = x * v.x;
	result.y = y * v.y;
	result.z = z * v.z;
	result.w = w * v.w;
	return result;
}

const GE::Math::Vector4 GE::Math::Vector4::operator/(const Vector4& v) const
{
	Vector4 result;
	result.x = x / v.x;
	result.y = y / v.y;
	result.z = z / v.z;
	result.w = w / v.w;
	return result;
}

GE::Math::Vector4& GE::Math::Vector4::operator+=(const Vector4& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	w += v.w;
	return *this;
}

GE::Math::Vector4& GE::Math::Vector4::operator-=(const Vector4& v)
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
	w -= v.w;
	return *this;
}

GE::Math::Vector4& GE::Math::Vector4::operator*=(const Vector4& v)
{
	x *= v.x;
	y *= v.y;
	z *= v.z;
	w *= v.w;
	return *this;
}

GE::Math::Vector4& GE::Math::Vector4::operator/=(const Vector4& v)
{
	x /= v.x;
	y /= v.y;
	z /= v.z;
	w /= v.w;
	return *this;
}

const GE::Math::Vector4 GE::Math::Vector4::operator*(float value) const
{
	Vector4 result;
	result.x = x * value;
	result.y = y * value;
	result.z = z * value;
	result.w = w * value;
	return result;
}

const GE::Math::Vector4 GE::Math::Vector4::operator/(float value) const
{
	Vector4 result;
	result.x = x / value;
	result.y = y / value;
	result.z = z / value;
	result.w = w / value;
	return result;
}

GE::Math::Vector4& GE::Math::Vector4::operator*=(float value)
{
	x *= value;
	y *= value;
	z *= value;
	w *= value;
	return *this;
}

GE::Math::Vector4& GE::Math::Vector4::operator/=(float value)
{
	x /= value;
	y /= value;
	z /= value;
	w /= value;
	return *this;
}
