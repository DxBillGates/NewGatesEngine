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
			/// ローカルのxyz軸を取得
			/// </summary>
			/// <returns>ローカルのxyz軸</returns>
			Axis GetAxis()const;
			/// <summary>
			/// ローカルのx軸を取得
			/// </summary>
			/// <returns>ローカルのx軸</returns>
			Vector3 GetRight()const;
			/// <summary>
			/// ローカルのz軸を取得
			/// </summary>
			/// <returns>ローカルのz軸</returns>
			Vector3 GetUp()const;
			/// <summary>
			/// ローカルのz軸を取得
			/// </summary>
			/// <returns>ローカルのz軸</returns>
			Vector3 GetForward()const;
			Matrix4x4 GetMatrix()const;
		};
	}
}