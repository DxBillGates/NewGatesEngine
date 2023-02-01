#include "..\..\..\Header\Util\Math\Quaternion.h"
#include "..\..\..\Header\Util\Math\Math.h"

GE::Math::Quaternion::Quaternion()
	:
	x(0), y(0), z(0), w(1)
{
}

GE::Math::Quaternion::Quaternion(float x, float y, float z, float w)
	:
	x(x), y(y), z(z), w(w)
{
}

GE::Math::Quaternion::Quaternion(const Vector3& v, float angle)
{
	float sin, cos;
	sin = Math::Sin(angle / 2.0f);
	cos = Math::Cos(angle / 2.0f);
	x = sin * v.x;
	y = sin * v.y;
	z = sin * v.z;
	w = cos;
}

GE::Math::Quaternion::Quaternion(const Matrix4x4& m)
{
	Quaternion result;
	float tr = m.m[0][0] + m.m[1][1] + m.m[2][2] + m.m[3][3];
	if (tr >= 1.0f)
	{
		float fourD = 2.0f * Math::Sqrt(tr);
		result.x = (m.m[1][2] - m.m[2][1]) / fourD;
		result.y = (m.m[2][0] - m.m[0][2]) / fourD;
		result.z = (m.m[0][1] - m.m[1][0]) / fourD;
		result.w = fourD / 4.0f;
	}
	int i = 0, j = 0, k = 0;
	if (m.m[0][0] <= m.m[1][1])i = 1;
	if (m.m[2][2] > m.m[i][i])i = 2;
	j = (i + 1) % 3;
	k = (j + 1) % 3;
	tr = m.m[i][i] - m.m[j][j] - m.m[k][k] + 1.0f;
	float fourD = 2.0f * Math::Sqrt(tr);
	float qa[4];
	qa[i] = fourD / 4.0f;
	qa[j] = (m.m[j][i] + m.m[i][j]) / fourD;
	qa[k] = (m.m[k][i] + m.m[i][k]) / fourD;
	qa[3] = (m.m[j][k] - m.m[k][j]) / fourD;

	x = qa[0];
	y = qa[1];
	z = qa[2];
	w = qa[3];
}

GE::Math::Quaternion GE::Math::Quaternion::Conjugate()const
{
	return Quaternion::Conjugate(*this);
}

GE::Math::Quaternion GE::Math::Quaternion::Normalize()const
{
	return Quaternion::Normalize(*this);
}

float GE::Math::Quaternion::Length()const
{
	return Quaternion::Length(*this);
}

GE::Math::Vector3 GE::Math::Quaternion::GetAxis()const
{
	return Quaternion::GetAxis(*this);
}

GE::Math::Matrix4x4 GE::Math::Quaternion::Rotation()const
{
	return Quaternion::Rotation(*this);
}

GE::Math::Vector3 GE::Math::Quaternion::EulerRadian()const
{
	Matrix4x4 matrix = this->Rotation();
	Vector3 angle;

	float epsilon = 0.0001f;
	float sign = matrix._32 / matrix._32;
	float comparison = matrix._32 + epsilon * sign;
	comparison = comparison > 1 * sign ? 1 * sign : matrix._32;
	if (comparison == 1)
	{
		angle.x = -PI / 2;
		angle.y = 0;
		angle.z = Math::Atan2(matrix._21, matrix._11);
	}
	else if (comparison == -1)
	{
		angle.x = PI / 2;
		angle.y = 0;
		angle.z = Math::Atan2(matrix._21, matrix._11);
	}
	else
	{
		angle.x = Math::Asin(-matrix._32);
		angle.y = Math::Atan2(matrix._31, matrix._33);
		angle.z = Math::Atan2(matrix._12, matrix._22);
	}

	return angle;
}

GE::Math::Vector3 GE::Math::Quaternion::EulerAngle()const
{
	Vector3 angle = EulerRadian();
	angle *= Math::TO_RADIAN;
	return angle;
}

GE::Math::Quaternion GE::Math::Quaternion::Conjugate(const Quaternion& q)
{
	Quaternion result = q;
	result = -result;
	result.w *= -1;
	return result;
}

GE::Math::Quaternion GE::Math::Quaternion::Normalize(const Quaternion& q)
{
	Quaternion result = q;
	float length = Length(result);
	if (length != 0)
	{
		result /= length;
		return result;
	}
	return Quaternion();
}

float GE::Math::Quaternion::Length(const Quaternion& q)
{
	float result = 0;
	result = Math::Sqrt(q.x * q.x + q.y * q.y + q.z * q.z + q.w * q.w);
	return result;
}

GE::Math::Vector3 GE::Math::Quaternion::GetAxis(const Quaternion& q)
{
	Vector3 result;
	float x, y, z, length;
	x = q.x;
	y = q.y;
	z = q.z;
	length = Length(q);
	result =
	{
		x / length,y / length,z / length
	};

	return result;
}

GE::Math::Matrix4x4 GE::Math::Quaternion::Rotation(const Quaternion& q)
{
	float xx = q.x * q.x * 2.0f;
	float yy = q.y * q.y * 2.0f;
	float zz = q.z * q.z * 2.0f;
	float xy = q.x * q.y * 2.0f;
	float xz = q.x * q.z * 2.0f;
	float yz = q.y * q.z * 2.0f;
	float wx = q.w * q.x * 2.0f;
	float wy = q.w * q.y * 2.0f;
	float wz = q.w * q.z * 2.0f;
	Matrix4x4 result =
	{
			1.0f - yy - zz,xy + wz,xz - wy,0.0f,
			xy - wz,1.0f - xx - zz,yz + wx,0.0f,
			xz + wy,yz - wx,1.0f - xx - yy,0.0f,
			0.0f,0.0f,0.0f,1.0f
	};
	return result;
}

GE::Math::Quaternion GE::Math::Quaternion::Euler(const Math::Vector3& angle)
{
	float xRadian = Math::ConvertToRadian(angle.x);
	float yRadian = Math::ConvertToRadian(angle.y);
	float zRadian = Math::ConvertToRadian(angle.z);

	float xCos = Math::Cos(xRadian / 2.0f);
	float xSin = Math::Sin(xRadian / 2.0f);
	float yCos = Math::Cos(yRadian / 2.0f);
	float ySin = Math::Sin(yRadian / 2.0f);
	float zCos = Math::Cos(zRadian / 2.0f);
	float zSin = Math::Sin(zRadian / 2.0f);

	Quaternion result =
	{
		xSin * yCos * zCos - xCos * ySin * zSin,
		xCos * ySin * zCos + xSin * yCos * zSin,
		xCos * yCos * zSin - xSin * ySin * zCos,
		xCos * yCos * zCos + xSin * ySin * zSin,
	};
	return result;
}

float GE::Math::Quaternion::Dot(const Quaternion& q1, const Quaternion& q2)
{
	float result = 0;
	result = q1.x * q2.x + q1.y * q2.y + q1.z * q2.z + q1.w * q2.w;
	return result;
}

GE::Math::Quaternion GE::Math::Quaternion::Lerp(const Quaternion& q1, const Quaternion& q2, float t)
{
	float cos = Dot(q1, q2);
	Quaternion t2 = q2;
	if (cos < 0.0f)
	{
		cos = -cos;
		Quaternion two = q2;
		t2 = -two;
	}
	float k0 = 1.0f - t;
	float k1 = t;
	return q1 * k0 + t2 * k1;
}

GE::Math::Quaternion GE::Math::Quaternion::Slerp(const Quaternion& q1, const Quaternion& q2, float t)
{
	float cos = Dot(q1, q2);
	Quaternion t2 = q2;
	if (cos < 0.0f)
	{
		cos = -cos;
		Quaternion two = q2;
		t2 = -two;
	}
	float k0 = 1.0f - t;
	float k1 = t;
	if ((1.0f - cos) > 0.001f)
	{
		float theta = Math::Acos(cos);
		k0 = Math::Sin(theta * k0) / Math::Sin(theta);
		k1 = Math::Sin(theta * k1) / Math::Sin(theta);
	}
	return q1 * k0 + t2 * k1;
}

GE::Math::Quaternion GE::Math::Quaternion::LookDirection(GE::Math::Vector3 direction)
{
	GE::Math::Vector3 dir = direction.Normalize();
	GE::Math::Vector3 forward = { 0,0,1 };
	float dot;
	float theta;
	dot = GE::Math::Vector3::Dot(forward, dir);
	theta = Math::Acos(dot);
	GE::Math::Vector3 cross = GE::Math::Vector3::Cross(forward, dir).Normalize();
	GE::Math::Quaternion result = { cross,theta };
	return result;
}

GE::Math::Vector3 GE::Math::Quaternion::Transform(const Quaternion& q, const Vector3& v)
{
	Quaternion vQuaternion = Quaternion(v.x, v.y, v.z, 0);
	Quaternion result = q * vQuaternion * q.Conjugate();
	return Vector3(result.x,result.y,result.z);
}

GE::Math::Quaternion GE::Math::Quaternion::operator-()const
{
	return Quaternion(-x, -y, -z, -w);;
}

const GE::Math::Quaternion GE::Math::Quaternion::operator+(const Quaternion& q) const
{
	Quaternion result;
	result.x = x + q.x;
	result.y = y + q.y;
	result.z = z + q.z;
	result.w = w + q.w;
	return result;
}

const GE::Math::Quaternion GE::Math::Quaternion::operator-(const Quaternion& q) const
{
	Quaternion result;
	result.x = x - q.x;
	result.y = y - q.y;
	result.z = z - q.z;
	result.w = w - q.w;
	return result;
}

const GE::Math::Quaternion GE::Math::Quaternion::operator*(const Quaternion& q) const
{
	Quaternion result = *this;
	result *= q;
	return result;
}

const GE::Math::Quaternion GE::Math::Quaternion::operator*(float s) const
{
	Quaternion result;
	result.x = x * s;
	result.y = y * s;
	result.z = z * s;
	result.w = w * s;
	return result;
}

const GE::Math::Quaternion GE::Math::Quaternion::operator/(float s) const
{
	Quaternion result = *this;
	result /= s;
	return result;
}

GE::Math::Quaternion& GE::Math::Quaternion::operator+=(const Quaternion& q)
{
	this->x += q.x;
	this->y += q.y;
	this->z += q.z;
	this->w += q.w;
	return *this;
}

GE::Math::Quaternion& GE::Math::Quaternion::operator-=(const Quaternion& q)
{
	this->x -= q.x;
	this->y -= q.y;
	this->z -= q.z;
	this->w -= q.w;
	return *this;
}

GE::Math::Quaternion& GE::Math::Quaternion::operator*=(const Quaternion& q)
{
	Quaternion result =
	{
		 this->x * q.w + this->y * q.z - this->z * q.y + this->w * q.x,
		-this->x * q.z + this->y * q.w + this->z * q.x + this->w * q.y,
		 this->x * q.y - this->y * q.x + this->z * q.w + this->w * q.z,
		-this->x * q.x - this->y * q.y - this->z * q.z + this->w * q.w,
	};
	*this = result;
	return *this;
}

GE::Math::Quaternion& GE::Math::Quaternion::operator*=(float s)
{
	this->x *= s;
	this->y *= s;
	this->z *= s;
	this->w *= s;
	return *this;
}

GE::Math::Quaternion& GE::Math::Quaternion::operator/=(float s)
{
	return *this *= 1.0f / s;
}