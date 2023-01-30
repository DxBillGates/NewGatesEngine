#include "..\..\..\Header\Util\Math\Matrix4.h"
#include "..\..\..\Header\Util\Math\Math.h"

GE::Math::Matrix4x4::Matrix4x4()
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			m[i][j] = 0;
		}
	}
}

GE::Math::Matrix4x4::Matrix4x4(float m00, float m01, float m02, float m03, float m10, float m11, float m12, float m13, float m20, float m21, float m22, float m23, float m30, float m31, float m32, float m33)
	: _00(m00), _01(m01), _02(m02), _03(m03)
	, _10(m10), _11(m11), _12(m12), _13(m13)
	, _20(m20), _21(m21), _22(m22), _23(m23)
	, _30(m30), _31(m31), _32(m32), _33(m33)
{
}

GE::Math::Matrix4x4 GE::Math::Matrix4x4::Inverse() const
{
	return Matrix4x4::Inverse(*this);
}

GE::Math::Matrix4x4 GE::Math::Matrix4x4::Transpose() const
{
	return Matrix4x4::Transpose(*this);
}

float GE::Math::Matrix4x4::Determinant() const
{
	return Matrix4x4::Determinant(*this);
}

GE::Math::Axis GE::Math::Matrix4x4::GetAxis() const
{
	return Matrix4x4::GetAxis(*this);
}

GE::Math::Matrix4x4 GE::Math::Matrix4x4::Identity()
{
	Matrix4x4 result
	{
		1.0f,0.0f,0.0f,0.0f,
		0.0f,1.0f,0.0f,0.0f,
		0.0f,0.0f,1.0f,0.0f,
		0.0f,0.0f,0.0f,1.0f,
	};

	return result;
}

GE::Math::Matrix4x4 GE::Math::Matrix4x4::Inverse(const Matrix4x4& matrix)
{
	Matrix4x4 result;
	result.m[0][0] =  matrix.m[1][1] * matrix.m[2][2] * matrix.m[3][3] + matrix.m[1][2] * matrix.m[2][3] * matrix.m[3][1] + matrix.m[1][3] * matrix.m[2][1] * matrix.m[3][2] - matrix.m[1][3] * matrix.m[2][2] * matrix.m[3][1] - matrix.m[1][2] * matrix.m[2][1] * matrix.m[3][3] - matrix.m[1][1] * matrix.m[2][3] * matrix.m[3][2];
	result.m[0][1] = -matrix.m[0][1] * matrix.m[2][2] * matrix.m[3][3] - matrix.m[0][2] * matrix.m[2][3] * matrix.m[3][1] - matrix.m[0][3] * matrix.m[2][1] * matrix.m[3][2] + matrix.m[0][3] * matrix.m[2][2] * matrix.m[3][1] + matrix.m[0][2] * matrix.m[2][1] * matrix.m[3][3] + matrix.m[0][1] * matrix.m[2][3] * matrix.m[3][2];
	result.m[0][2] =  matrix.m[0][1] * matrix.m[1][2] * matrix.m[3][3] + matrix.m[0][2] * matrix.m[1][3] * matrix.m[3][1] + matrix.m[0][3] * matrix.m[1][1] * matrix.m[3][2] - matrix.m[0][3] * matrix.m[1][2] * matrix.m[3][1] - matrix.m[0][2] * matrix.m[1][1] * matrix.m[3][3] - matrix.m[0][1] * matrix.m[1][3] * matrix.m[3][2];
	result.m[0][3] = -matrix.m[0][1] * matrix.m[1][2] * matrix.m[2][3] - matrix.m[0][2] * matrix.m[1][3] * matrix.m[2][1] - matrix.m[0][3] * matrix.m[1][1] * matrix.m[2][2] + matrix.m[0][3] * matrix.m[1][2] * matrix.m[2][1] + matrix.m[0][2] * matrix.m[1][1] * matrix.m[2][3] + matrix.m[0][1] * matrix.m[1][3] * matrix.m[2][2];

	result.m[1][0] = -matrix.m[1][0] * matrix.m[2][2] * matrix.m[3][3] - matrix.m[1][2] * matrix.m[2][3] * matrix.m[3][0] - matrix.m[1][3] * matrix.m[2][0] * matrix.m[3][2] + matrix.m[1][3] * matrix.m[2][2] * matrix.m[3][0] + matrix.m[1][2] * matrix.m[2][0] * matrix.m[3][3] + matrix.m[1][0] * matrix.m[2][3] * matrix.m[3][2];
	result.m[1][1] =  matrix.m[0][0] * matrix.m[2][2] * matrix.m[3][3] + matrix.m[0][2] * matrix.m[2][3] * matrix.m[3][0] + matrix.m[0][3] * matrix.m[2][0] * matrix.m[3][2] - matrix.m[0][3] * matrix.m[2][2] * matrix.m[3][0] - matrix.m[0][2] * matrix.m[2][0] * matrix.m[3][3] - matrix.m[0][0] * matrix.m[2][3] * matrix.m[3][2];
	result.m[1][2] = -matrix.m[0][0] * matrix.m[1][2] * matrix.m[3][3] - matrix.m[0][2] * matrix.m[1][3] * matrix.m[3][0] - matrix.m[0][3] * matrix.m[1][0] * matrix.m[3][2] + matrix.m[0][3] * matrix.m[1][2] * matrix.m[3][0] + matrix.m[0][2] * matrix.m[1][0] * matrix.m[3][3] + matrix.m[0][0] * matrix.m[1][3] * matrix.m[3][2];
	result.m[1][3] =  matrix.m[0][0] * matrix.m[1][2] * matrix.m[2][3] + matrix.m[0][2] * matrix.m[1][3] * matrix.m[2][0] + matrix.m[0][3] * matrix.m[1][0] * matrix.m[2][2] - matrix.m[0][3] * matrix.m[1][2] * matrix.m[2][0] - matrix.m[0][2] * matrix.m[1][0] * matrix.m[2][3] - matrix.m[0][0] * matrix.m[1][3] * matrix.m[2][2];

	result.m[2][0] =  matrix.m[1][0] * matrix.m[2][1] * matrix.m[3][3] + matrix.m[1][1] * matrix.m[2][3] * matrix.m[3][0] + matrix.m[1][3] * matrix.m[2][0] * matrix.m[3][1] - matrix.m[1][3] * matrix.m[2][1] * matrix.m[3][0] - matrix.m[1][1] * matrix.m[2][0] * matrix.m[3][3] - matrix.m[1][0] * matrix.m[2][3] * matrix.m[3][1];
	result.m[2][1] = -matrix.m[0][0] * matrix.m[2][1] * matrix.m[3][3] - matrix.m[0][1] * matrix.m[2][3] * matrix.m[3][0] - matrix.m[0][3] * matrix.m[2][0] * matrix.m[3][1] + matrix.m[0][3] * matrix.m[2][1] * matrix.m[3][0] + matrix.m[0][1] * matrix.m[2][0] * matrix.m[3][3] + matrix.m[0][0] * matrix.m[2][3] * matrix.m[3][1];
	result.m[2][2] =  matrix.m[0][0] * matrix.m[1][1] * matrix.m[3][3] + matrix.m[0][1] * matrix.m[1][3] * matrix.m[3][0] + matrix.m[0][3] * matrix.m[1][0] * matrix.m[3][1] - matrix.m[0][3] * matrix.m[1][1] * matrix.m[3][0] - matrix.m[0][1] * matrix.m[1][0] * matrix.m[3][3] - matrix.m[0][0] * matrix.m[1][3] * matrix.m[3][1];
	result.m[2][3] = -matrix.m[0][0] * matrix.m[1][1] * matrix.m[2][3] - matrix.m[0][1] * matrix.m[1][3] * matrix.m[2][0] - matrix.m[0][3] * matrix.m[1][0] * matrix.m[2][1] + matrix.m[0][3] * matrix.m[1][1] * matrix.m[2][0] + matrix.m[0][1] * matrix.m[1][0] * matrix.m[2][3] + matrix.m[0][0] * matrix.m[1][3] * matrix.m[2][1];

	result.m[3][0] = -matrix.m[1][0] * matrix.m[2][1] * matrix.m[3][2] - matrix.m[1][1] * matrix.m[2][2] * matrix.m[3][0] - matrix.m[1][2] * matrix.m[2][0] * matrix.m[3][1] + matrix.m[1][2] * matrix.m[2][1] * matrix.m[3][0] + matrix.m[1][1] * matrix.m[2][0] * matrix.m[3][2] + matrix.m[1][0] * matrix.m[2][2] * matrix.m[3][1];
	result.m[3][1] =  matrix.m[0][0] * matrix.m[2][1] * matrix.m[3][2] + matrix.m[0][1] * matrix.m[2][2] * matrix.m[3][0] + matrix.m[0][2] * matrix.m[2][0] * matrix.m[3][1] - matrix.m[0][2] * matrix.m[2][1] * matrix.m[3][0] - matrix.m[0][1] * matrix.m[2][0] * matrix.m[3][2] - matrix.m[0][0] * matrix.m[2][2] * matrix.m[3][1];
	result.m[3][2] = -matrix.m[0][0] * matrix.m[1][1] * matrix.m[3][2] - matrix.m[0][1] * matrix.m[1][2] * matrix.m[3][0] - matrix.m[0][2] * matrix.m[1][0] * matrix.m[3][1] + matrix.m[0][2] * matrix.m[1][1] * matrix.m[3][0] + matrix.m[0][1] * matrix.m[1][0] * matrix.m[3][2] + matrix.m[0][0] * matrix.m[1][2] * matrix.m[3][1];
	result.m[3][3] =  matrix.m[0][0] * matrix.m[1][1] * matrix.m[2][2] + matrix.m[0][1] * matrix.m[1][2] * matrix.m[2][0] + matrix.m[0][2] * matrix.m[1][0] * matrix.m[2][1] - matrix.m[0][2] * matrix.m[1][1] * matrix.m[2][0] - matrix.m[0][1] * matrix.m[1][0] * matrix.m[2][2] - matrix.m[0][0] * matrix.m[1][2] * matrix.m[2][1];

	float f = Matrix4x4::Determinant(matrix);
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			result.m[i][j] *= 1.0f / f;
		}
	}
	return result;
}

GE::Math::Matrix4x4 GE::Math::Matrix4x4::Transpose(const Matrix4x4& matrix)
{
	Matrix4x4 result;
	result =
	{
		matrix.m[0][0],matrix.m[1][0],matrix.m[2][0],matrix.m[3][0],
		matrix.m[0][1],matrix.m[1][1],matrix.m[2][1],matrix.m[3][1],
		matrix.m[0][2],matrix.m[1][2],matrix.m[2][2],matrix.m[3][2],
		matrix.m[0][3],matrix.m[1][3],matrix.m[2][3],matrix.m[3][3],
	};
	return result;
}

float GE::Math::Matrix4x4::Determinant(const Matrix4x4& matrix)
{
	float f0 = matrix.m[0][0] * ((matrix.m[1][1] * (matrix.m[2][2] * matrix.m[3][3] - matrix.m[2][3] * matrix.m[3][2]) - (matrix.m[1][2] * (matrix.m[2][1] * matrix.m[3][3] - matrix.m[2][3] * matrix.m[3][1])) + (matrix.m[1][3] * (matrix.m[2][1] * matrix.m[3][2] - matrix.m[2][2] * matrix.m[3][1]))));
	float f1 = matrix.m[1][0] * ((matrix.m[0][1] * (matrix.m[2][2] * matrix.m[3][3] - matrix.m[2][3] * matrix.m[3][2]) - (matrix.m[0][2] * (matrix.m[2][1] * matrix.m[3][3] - matrix.m[2][3] * matrix.m[3][1])) + (matrix.m[0][3] * (matrix.m[2][1] * matrix.m[3][2] - matrix.m[2][2] * matrix.m[3][1]))));
	float f2 = matrix.m[2][0] * ((matrix.m[0][1] * (matrix.m[1][2] * matrix.m[3][3] - matrix.m[1][3] * matrix.m[3][2]) - (matrix.m[0][2] * (matrix.m[1][1] * matrix.m[3][3] - matrix.m[1][3] * matrix.m[3][1])) + (matrix.m[0][3] * (matrix.m[1][1] * matrix.m[3][2] - matrix.m[1][2] * matrix.m[3][1]))));
	float f3 = matrix.m[3][0] * ((matrix.m[0][1] * (matrix.m[1][2] * matrix.m[2][3] - matrix.m[1][3] * matrix.m[2][2]) - (matrix.m[0][2] * (matrix.m[1][1] * matrix.m[2][3] - matrix.m[1][3] * matrix.m[2][1])) + (matrix.m[0][3] * (matrix.m[1][1] * matrix.m[2][2] - matrix.m[1][2] * matrix.m[2][1]))));
	float result = f0 - f1 + f2 - f3;
	return result;
}

GE::Math::Axis GE::Math::Matrix4x4::GetAxis(const Matrix4x4& matrix)
{
	Axis result;
	result.x = Vector3(matrix._00, matrix._01, matrix._02).Normalize();
	result.y = Vector3(matrix._10, matrix._11, matrix._12).Normalize();
	result.z = Vector3(matrix._20, matrix._21, matrix._22).Normalize();
	return result;
}

GE::Math::Matrix4x4 GE::Math::Matrix4x4::Lerp(const Matrix4x4& s, const Matrix4x4& e, float t)
{
	Matrix4x4 result;
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			result.m[i][j] = Math::Lerp(s.m[i][j], e.m[i][j], t);
		}
	}
	return result;
}

GE::Math::Matrix4x4 GE::Math::Matrix4x4::Scale(const Vector3& scale)
{
	Matrix4x4 result
	{
		scale.x,0.0f,0.0f,0.0f,
		0.0f,scale.y,0.0f,0.0f,
		0.0f,0.0f,scale.z,0.0f,
		0.0f,0.0f,0.0f,1.0f,
	};

	return result;
}

GE::Math::Matrix4x4 GE::Math::Matrix4x4::RotateX(float angle)
{
	angle *= Math::TO_RADIAN;
	float sin = Math::Sin(angle);
	float cos = Math::Cos(angle);

	Matrix4x4 result
	{
		1.0f,0.0f,0.0f,0.0f,
		0.0f,cos,sin,0.0f,
		0.0f,-sin,cos,0.0f,
		0.0f,0.0f,0.0f,1.0f,
	};

	return result;
}

GE::Math::Matrix4x4 GE::Math::Matrix4x4::RotateY(float angle)
{
	angle *= Math::TO_RADIAN;
	float sin = Math::Sin(angle);
	float cos = Math::Cos(angle);

	Matrix4x4 result
	{
		cos,0.0f,-sin,0.0f,
		0.0f,1.0f,0.0f,0.0f,
		sin,0.0f,cos,0.0f,
		0.0f,0.0f,0.0f,1.0f,
	};

	return result;
}

GE::Math::Matrix4x4 GE::Math::Matrix4x4::RotateZ(float angle)
{
	angle *= Math::TO_RADIAN;
	float sin = Math::Sin(angle);
	float cos = Math::Cos(angle);

	Matrix4x4 result
	{
		cos,sin,0.0f,0.0f,
		-sin,cos,0.0f ,0.0f,
		0.0f,0.0f,1.0f,0.0f,
		0.0f,0.0f,0.0f,1.0f,
	};

	return result;
}

GE::Math::Matrix4x4 GE::Math::Matrix4x4::RotateZXY(const Vector3& angles)
{
	Vector3 convertedRadians = angles;
	convertedRadians *= Math::TO_RADIAN;
	return RotateZ(convertedRadians.z) * RotateX(convertedRadians.x) * RotateY(convertedRadians.y);
}

GE::Math::Matrix4x4 GE::Math::Matrix4x4::Translate(const Vector3& pos)
{
	Matrix4x4 result
	{
		1.0f,0.0f,0.0f,0.0f,
		0.0f,1.0f,0.0f,0.0f,
		0.0f,0.0f,1.0f,0.0f,
		pos.x,pos.y,pos.z,1.0f,
	};

	return result;
}

GE::Math::Vector3 GE::Math::Matrix4x4::Transform(const Vector3& vector, const Matrix4x4& matrix)
{
	float w = vector.x * matrix.m[0][3] + vector.y * matrix.m[1][3] + vector.z * matrix.m[2][3] + matrix.m[3][3];

	Vector3 result
	{
		(vector.x * matrix.m[0][0] + vector.y * matrix.m[1][0] + vector.z * matrix.m[2][0] + matrix.m[3][0]) / w,
		(vector.x * matrix.m[0][1] + vector.y * matrix.m[1][1] + vector.z * matrix.m[2][1] + matrix.m[3][1]) / w,
		(vector.x * matrix.m[0][2] + vector.y * matrix.m[1][2] + vector.z * matrix.m[2][2] + matrix.m[3][2]) / w,
	};

	return result;
}

GE::Math::Matrix4x4 GE::Math::Matrix4x4::GetViewMatrixLookAt(const Vector3& pos, const Vector3& focasPos, const Vector3& upDir)
{
	Vector3 dir = (focasPos - pos);
	return GetViewMatrixLookTo(pos, dir.Normalize(), upDir);
}

GE::Math::Matrix4x4 GE::Math::Matrix4x4::GetViewMatrixLookTo(const Vector3& pos, const Vector3& direction, const Vector3& upDir)
{
	Matrix4x4 result;
	Vector3 xAxis, yAxis, zAxis;
	zAxis = direction;
	xAxis = Vector3::Normalize(Vector3::Cross(upDir, zAxis));
	yAxis = Vector3::Cross(zAxis, xAxis);
	Vector3 negpos = Vector3(-pos.x, -pos.y, -pos.z);
	result =
	{
		xAxis.x,xAxis.y,xAxis.z,0,
		yAxis.x,yAxis.y,yAxis.z,0,
		zAxis.x,zAxis.y,zAxis.z,0,
		0,0,0,1,
	};
	result = Matrix4x4::Transpose(result);
	result.m[3][0] = Vector3::Dot(xAxis, negpos);
	result.m[3][1] = Vector3::Dot(yAxis, negpos);
	result.m[3][2] = Vector3::Dot(zAxis, negpos);
	result.m[3][3] = 1;
	return result;
}

GE::Math::Matrix4x4 GE::Math::Matrix4x4::GetPerspectiveMatrix(float fov, float aspect, float nearClip, float farClip)
{
	Matrix4x4 result;
	float tanTheta = Math::Tan(fov / 2);
	float x, y, width, height;
	x = 1.0f / tanTheta;
	y = 1.0f / tanTheta * aspect;
	width = 1 / (farClip - nearClip) * farClip;
	height = -nearClip / (farClip - nearClip) * farClip;
	result =
	{
		x,0,0,0,
		0,y,0,0,
		0,0,width,1,
		0,0,height,0
	};
	return result;
}

GE::Math::Matrix4x4 GE::Math::Matrix4x4::GetOrthographMatrix(const Vector2& size, float nearClip, float farClip)
{
	Matrix4x4 result;
	result =
	{
		2.0f / size.x,0,0,0,
		0,2.0f / size.y,0,0,
		0,0,1 / (farClip - nearClip),0,
		0,nearClip / (nearClip - farClip),0,1
	};
	return result;
}

GE::Math::Matrix4x4 GE::Math::Matrix4x4::GetViewportMatrix(const Vector2& size, const Vector2& offset)
{
	Matrix4x4 result;
	result =
	{
		size.x / 2,          0,0,0,
				 0,-size.y / 2,0,0,
				 0,          0,1,0,
		offset.x + size.x / 2,offset.y + size.y / 2,0,1
	};
	return result;
}

//GE::Math::Vector3 GE::Math::Matrix4x4::ConvertScreenToWorld(const Vector2& screenPos, const Matrix4x4& view, const Matrix4x4& proj, const Matrix4x4& viewPort)
//{
//	return Vector3();
//}

GE::Math::Vector2 GE::Math::Matrix4x4::ConvertWorldToScreen(const Vector3& worldPos, const Matrix4x4& view, const Matrix4x4& proj)
{
	Matrix4x4 transformMatrix = view * proj;
	Vector3 screenPos = Transform(worldPos, transformMatrix);
	// -1 ~ 1 ‚ð 0 ~ 1‚É•ÏŠ·
	screenPos += 1;
	screenPos /= 2;
	return Vector2(screenPos.x,screenPos.y);
}

const GE::Math::Matrix4x4 GE::Math::Matrix4x4::operator*(const Matrix4x4& matrix) const
{
	Matrix4x4 result;

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			for (int k = 0; k < 4; ++k)
			{
				result.m[i][j] += m[i][k] * matrix.m[k][j];
			}
		}
	}

	return result;
}

GE::Math::Matrix4x4& GE::Math::Matrix4x4::operator*=(const Matrix4x4& matrix)
{
	*this = *this * matrix;
	return *this;
}
