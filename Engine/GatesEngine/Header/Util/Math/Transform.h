#pragma once
#include "..\..\..\Header\Util\Math\Quaternion.h"

namespace GE
{
	namespace Math
	{
		struct Transform
		{
			Vector3 scale;
			Quaternion rotation;
			Vector3 position;

			Transform();
			Transform(const Math::Vector3& scale, const Math::Quaternion& rotation, const Math::Vector3& position);
			Transform(const Math::Transform& transform);

			Axis GetAxis()const;
			Vector3 GetRight()const;
			Vector3 GetUp()const;
			Vector3 GetForward()const;
			Matrix4x4 GetMatrix()const;
		};
	}
}