#include "..\..\..\Header\Util\Math\Transform.h"

GE::Math::Transform::Transform()
	: Transform(Vector3(1),Quaternion(),Vector3())
{
}

GE::Math::Transform::Transform(const Math::Vector3& scale, const Math::Quaternion& rotation, const Math::Vector3& position)
	: scale(scale)
	, rotation(rotation)
	, position(position)
{
}

GE::Math::Transform::Transform(const Math::Transform& transform)
	: scale(transform.scale)
	, rotation( transform.rotation)
	, position( transform.position)
{
}

GE::Math::Axis GE::Math::Transform::GetAxis() const
{
	Axis axis;
	axis.x = Quaternion::Transform(rotation, axis.x);
	axis.y = Quaternion::Transform(rotation, axis.y);
	axis.z = Quaternion::Transform(rotation, axis.z);
	return axis;
}

GE::Math::Vector3 GE::Math::Transform::GetRight() const
{
	Vector3 right = Vector3(1, 0, 0);
	right = Quaternion::Transform(rotation, right);
	return right;
}

GE::Math::Vector3 GE::Math::Transform::GetUp() const
{
	Vector3 up = Vector3(0, 1, 0);
	up = Quaternion::Transform(rotation, up);
	return up;
}

GE::Math::Vector3 GE::Math::Transform::GetForward() const
{
	Vector3 foward = Vector3(0, 0, 1);
	foward = Quaternion::Transform(rotation, foward);
	return foward;
}

GE::Math::Matrix4x4 GE::Math::Transform::GetMatrix() const
{
	return Matrix4x4::Scale(scale) * rotation.Rotation() * Matrix4x4::Translate(position);
}
