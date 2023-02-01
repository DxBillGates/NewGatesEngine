#include "..\..\..\Header\Util\Math\Vector3.h"
#include "..\..\..\Header\Util\Math\Math.h"

GE::Math::Vector3::Vector3()
	: x(0)
	, y(0)
	, z(0)
{
}

GE::Math::Vector3::Vector3(float xyz)
	: x(xyz)
	, y(xyz)
	, z(xyz)
{
}

GE::Math::Vector3::Vector3(float x, float y, float z)
	: x(x)
	, y(y)
	, z(z)
{
}

GE::Math::Vector3::Vector3(float vector2Value[2])
	: x(vector2Value[0])
	, y(vector2Value[1])
	, z(0)
{
}

float GE::Math::Vector3::Length() const
{
	float result;
	result =  Math::Pow(x, 2);
	result += Math::Pow(y, 2);
	result += Math::Pow(z, 2);
	return Math::Sqrt(result);
}

GE::Math::Vector3 GE::Math::Vector3::Normalize() const
{
	float length = Length();
	if (length == 0)return Vector3();
	return *this / length;
}

//GE::Math::Vector3 GE::Math::Vector3::Cross(const Vector3& v) const
//{
//	Vector3 result;
//	result.x = y * v.z - z * v.y;
//	result.y = x * v.z - z * v.x;
//	result.z = x * v.y - y * v.x;
//	return result;
//}

//float GE::Math::Vector3::Dot(const Vector3& v) const
//{
//	float result;
//	result = x * v.x;
//	result += y * v.y;
//	result += z * v.z;
//	return result;
//}

float GE::Math::Vector3::Distance(const Vector3& p1, const Vector3& p2)
{
	Vector3 v = p2 - p1;
	return v.Length();
}

GE::Math::Vector3 GE::Math::Vector3::Normalize(const Vector3& v)
{
	return v.Normalize();
}

GE::Math::Vector3 GE::Math::Vector3::Cross(const Vector3& v1, const Vector3& v2)
{
	Vector3 result;
	result.x = v1.y * v2.z - v1.z * v2.y;
	result.y = v1.x * v2.z - v1.z * v2.x;
	result.z = v1.x * v2.y - v1.y * v2.x;
	return result;
}

float GE::Math::Vector3::Dot(const Vector3& v1, const Vector3& v2)
{
	float result;
	result = v1.x * v2.x;
	result += v1.y * v2.y;
	result += v1.z * v2.z;
	return result;
}

GE::Math::Vector3 GE::Math::Vector3::Lerp(const Vector3& v1, const Vector3& v2, float t)
{
	if (t < 0)t = 0;
	if (t > 1)t = 1;
	Vector3 result;
	result = v1 * (1.f - t) + v2 * t;
	return result;
}

GE::Math::Vector3 GE::Math::Vector3::Min(const Vector3& minVector, const Vector3& comparison)
{
	Vector3 result;
	result.x = Math::Min(minVector.x, comparison.x);
	result.y = Math::Min(minVector.y, comparison.y);
	result.z = Math::Min(minVector.z, comparison.z);
	return result;
}

GE::Math::Vector3 GE::Math::Vector3::Max(const Vector3& maxVector, const Vector3& comparison)
{
	Vector3 result;
	result.x = Math::Max(maxVector.x, comparison.x);
	result.y = Math::Max(maxVector.y, comparison.y);
	result.z = Math::Max(maxVector.z, comparison.z);
	return result;
}

GE::Math::Vector3 GE::Math::Vector3::Clamp(const Vector3& minVector, const Vector3& maxVector, const Vector3& comparison)
{
	Vector3 result;
	result = Min(Max(comparison, minVector), maxVector);
	return result;
}

GE::Math::Vector3 GE::Math::Vector3::Reflect(const Vector3& direction, const Vector3& normal, float p)
{
	GE::Math::Vector3 normalizedNormal = normal.Normalize();
	GE::Math::Vector3 inverseDirection = -direction;
	float LdotNx2 = p * GE::Math::Vector3::Dot(inverseDirection, normalizedNormal);
	GE::Math::Vector3 result = direction + normalizedNormal * LdotNx2;
	return result;
}

GE::Math::Vector3 GE::Math::Vector3::Project(const Vector3& vector, const Vector3& normal)
{
	GE::Math::Vector3 normalizedNormal = normal;
	if (normalizedNormal.Length() > 1)normalizedNormal = normalizedNormal.Normalize();
	GE::Math::Vector3 result;
	result = normal * Math::Vector3::Dot(vector, normal);
	return result;
}

GE::Math::Vector3 GE::Math::Vector3::operator-()const
{
	return Vector3(-x, -y, -z);
}

const GE::Math::Vector3 GE::Math::Vector3::operator+(const Vector3& v) const
{
	Vector3 result;
	result.x = x + v.x;
	result.y = x + v.y;
	result.z = z + v.z;
	return result;
}

const GE::Math::Vector3 GE::Math::Vector3::operator-(const Vector3& v) const
{
	Vector3 result;
	result.x = x - v.x;
	result.y = x - v.y;
	result.z = z - v.z;
	return result;
}

const GE::Math::Vector3 GE::Math::Vector3::operator*(const Vector3& v) const
{
	Vector3 result;
	result.x = x * v.x;
	result.y = x * v.y;
	result.z = z * v.z;
	return result;
}

const GE::Math::Vector3 GE::Math::Vector3::operator/(const Vector3& v) const
{
	Vector3 result;
	result.x = x / v.x;
	result.y = x / v.y;
	result.z = z / v.z;
	return result;
}

GE::Math::Vector3& GE::Math::Vector3::operator+=(const Vector3& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	return *this;
}

GE::Math::Vector3& GE::Math::Vector3::operator-=(const Vector3& v)
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
	return *this;
}

GE::Math::Vector3& GE::Math::Vector3::operator*=(const Vector3& v)
{
	x *= v.x;
	y *= v.y;
	z *= v.z;
	return *this;
}

GE::Math::Vector3& GE::Math::Vector3::operator/=(const Vector3& v)
{
	x /= v.x;
	y /= v.y;
	z /= v.z;
	return *this;
}

const GE::Math::Vector3 GE::Math::Vector3::operator*(float value) const
{
	Vector3 result = *this;
	result.x *= value;
	result.y *= value;
	return result;
}

const GE::Math::Vector3 GE::Math::Vector3::operator/(float value) const
{
	Vector3 result = *this;
	result.x /= value;
	result.y /= value;
	return result;
}

GE::Math::Vector3& GE::Math::Vector3::operator*=(float value)
{
	x *= value;
	y *= value;
	z *= value;
	return *this;
}

GE::Math::Vector3& GE::Math::Vector3::operator/=(float value)
{
	x /= value;
	y /= value;
	z /= value;
	return *this;
}

GE::Math::Vector3Int::Vector3Int()
	: x(0)
	, y(0)
	, z(0)
{
}

GE::Math::Vector3Int::Vector3Int(int xy)
	: x(xy)
	, y(xy)
	, z(0)
{
}

GE::Math::Vector3Int::Vector3Int(int x, int y, int z)
	: x(x)
	, y(y)
	, z(z)
{
}

GE::Math::Vector3Int GE::Math::Vector3Int::operator-()
{
	return Vector3Int(-x, -y, -z);
}

const GE::Math::Vector3Int GE::Math::Vector3Int::operator+(const Vector3Int& v) const
{
	Vector3Int result;
	result.x = x + v.x;
	result.y = y + v.y;
	result.z = z + v.z;
	return result;
}

const GE::Math::Vector3Int GE::Math::Vector3Int::operator-(const Vector3Int& v) const
{
	Vector3Int result;
	result.x = x - v.x;
	result.y = y - v.y;
	result.z = z - v.z;
	return result;
}

const GE::Math::Vector3Int GE::Math::Vector3Int::operator*(const Vector3Int& v) const
{
	Vector3Int result;
	result.x = x * v.x;
	result.y = y * v.y;
	result.z = z * v.z;
	return result;
}

const GE::Math::Vector3Int GE::Math::Vector3Int::operator/(const Vector3Int& v) const
{
	Vector3Int result;
	result.x = x / v.x;
	result.y = y / v.y;
	result.z = z / v.z;
	return result;
}

GE::Math::Vector3Int& GE::Math::Vector3Int::operator+=(const Vector3Int& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	return *this;
}

GE::Math::Vector3Int& GE::Math::Vector3Int::operator-=(const Vector3Int& v)
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
	return *this;
}

GE::Math::Vector3Int& GE::Math::Vector3Int::operator*=(const Vector3Int& v)
{
	x *= v.x;
	y *= v.y;
	z *= v.z;
	return *this;
}

GE::Math::Vector3Int& GE::Math::Vector3Int::operator/=(const Vector3Int& v)
{
	x /= v.x;
	y /= v.y;
	z /= v.z;
	return *this;
}

const GE::Math::Vector3Int GE::Math::Vector3Int::operator*(int value) const
{
	Vector3Int result;
	result.x = x * value;
	result.y = y * value;
	result.z = z * value;
	return result;
}

const GE::Math::Vector3Int GE::Math::Vector3Int::operator/(int value) const
{
	Vector3Int result;
	result.x = x / value;
	result.y = y / value;
	result.z = z / value;
	return result;
}

GE::Math::Vector3Int& GE::Math::Vector3Int::operator*=(int value)
{
	x *= value;
	y *= value;
	z *= value;
	return *this;
}

GE::Math::Vector3Int& GE::Math::Vector3Int::operator/=(int value)
{
	x /= value;
	y /= value;
	z /= value;
	return *this;
}
