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

			/// <summary>
			/// ���[�J����xyz�����擾
			/// </summary>
			/// <returns>���[�J����xyz��</returns>
			Axis GetAxis()const;
			/// <summary>
			/// ���[�J����x�����擾
			/// </summary>
			/// <returns>���[�J����x��</returns>
			Vector3 GetRight()const;
			/// <summary>
			/// ���[�J����z�����擾
			/// </summary>
			/// <returns>���[�J����z��</returns>
			Vector3 GetUp()const;
			/// <summary>
			/// ���[�J����z�����擾
			/// </summary>
			/// <returns>���[�J����z��</returns>
			Vector3 GetForward()const;
			Matrix4x4 GetMatrix()const;
		};
	}
}