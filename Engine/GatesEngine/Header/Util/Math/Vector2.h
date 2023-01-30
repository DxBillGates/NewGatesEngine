#pragma once

namespace GE
{
	namespace Math
	{
		struct Vector2
		{
			union
			{
				struct
				{
					float x, y;
				};
				float value[2];
			};

			Vector2();
			Vector2(float xy);
			Vector2(float x, float y);

			/// <summary>
			/// ���C���X�^���X�̃x�N�g���̒�����Ԃ�
			/// </summary>
			/// <returns>���C���X�^���X�̃x�N�g���̒���</returns>
			float Length() const;
			/// <summary>
			/// ���C���X�^���X�̐��K���x�N�g����Ԃ�
			/// </summary>
			/// <returns>���C���X�^���X�̐��K���x�N�g��</returns>
			Vector2 Normalize() const;
			///// <summary>
			///// ���C���X�^���X�ƈ����Ŏ󂯎�����x�N�g���Ƃ̊O�ς�Ԃ�
			///// </summary>
			///// <param name="v">�Ώۂ̃x�N�g��</param>
			///// <returns>���C���X�^���X�ƈ����Ŏ󂯎�����x�N�g���Ƃ̊O��</returns>
			//float Cross(const Vector3& v) const;
			///// <summary>
			///// ���C���X�^���X�ƈ����Ŏ󂯎�����x�N�g���Ƃ̓��ς�Ԃ�
			///// </summary>
			///// <param name="v">�Ώۂ̃x�N�g��</param>
			///// <returns>���C���X�^���X�ƈ����Ŏ󂯎�����x�N�g���Ƃ̓���</returns>
			//float Dot(const Vector3& v) const;

			/// <summary>
			/// ��_�Ԃ̋�����Ԃ�
			/// </summary>
			/// <param name="p1">�_A</param>
			/// <param name="p2">�_B</param>
			/// <returns>��_�Ԃ̋���</returns>
			static float Distance(const Vector2& p1, const Vector2& p2);
			/// <summary>
			/// �Ώۂ̃x�N�g���̐��K���x�N�g����Ԃ�
			/// </summary>
			/// <param name="v">�Ώۂ̃x�N�g��</param>
			/// <returns>�Ώۂ̃x�N�g���̐��K���x�N�g��</returns>
			static Vector2 Normalize(const Vector2& v);
			/// <summary>
			/// ��̃x�N�g���̊O�ς�Ԃ�
			/// </summary>
			/// <param name="v1">�x�N�g��A</param>
			/// <param name="v2">�x�N�g��B</param>
			/// <returns>��̃x�N�g���̊O��</returns>
			static float Cross(const Vector2& v1, const Vector2& v2);
			/// <summary>
			/// ��̃x�N�g���̓��ς�Ԃ�
			/// </summary>
			/// <param name="v1">�x�N�g��A</param>
			/// <param name="v2">�x�N�g��B</param>
			/// <returns>��̃x�N�g���̓���</returns>
			static float Dot(const Vector2& v1, const Vector2& v2);
			/// <summary>
			/// ��_�ԁA�܂��͓�̃x�N�g������`��Ԃ������ʂ�Ԃ�
			/// </summary>
			/// <param name="v1">�_A or �x�N�g��A</param>
			/// <param name="v2">�_B or �x�N�g��B</param>
			/// <param name="t">��ԓx0 ~ 1</param>
			/// <returns>��_�ԁA�܂��͓�̃x�N�g������`��Ԃ�������</returns>
			static Vector2 Lerp(const Vector2& v1, const Vector2& v2, float t);
			/// <summary>
			/// ��̃x�N�g���̊e�������r���ď�����������Ԃ�
			/// </summary>
			/// <param name="minVector">��r�Ώ�</param>
			/// <param name="comparison">��r�Ώ�</param>
			/// <returns>����������</returns>
			static Vector2 Min(const Vector2& minVector, const Vector2& comparison);
			/// <summary>
			/// ��̃x�N�g���̊e�������r���đ傫��������Ԃ�
			/// </summary>
			/// <param name="maxVector">��r�Ώ�</param>
			/// <param name="comparison">��r�Ώ�</param>
			/// <returns>�傫������</returns>
			static Vector2 Max(const Vector2& maxVector, const Vector2& comparison);
			/// <summary>
			/// min��max�𗘗p���e������minVector,maxVector�̐������Ɏ��߂�
			/// </summary>
			/// <param name="minVector">��r�Ώ�</param>
			/// <param name="maxVector">��r�Ώ�</param>
			/// <param name="comparison">��r�Ώ�</param>
			/// <returns>min,max�Ɏ��܂�������</returns>
			static Vector2 Clamp(const Vector2& minVector, const Vector2& maxVector, const Vector2& comparison);
			// �t�x�N�g��
			Vector2 operator-()const;
			// �x�N�g���̐������m�̎l�����Z
			const Vector2 operator+(const Vector2& v)const;
			const Vector2 operator-(const Vector2& v)const;
			const Vector2 operator*(const Vector2& v)const;
			const Vector2 operator/(const Vector2& v)const;
			Vector2& operator+=(const Vector2& v);
			Vector2& operator-=(const Vector2& v);
			Vector2& operator*=(const Vector2& v);
			Vector2& operator/=(const Vector2& v);

			const Vector2 operator*(float value)const;
			const Vector2 operator/(float value)const;
			Vector2& operator*=(float value);
			Vector2& operator/=(float value);
		};

		// Vector2��int�Łi���Z�q�I�[�o�[���[�h�̂݁j
		struct Vector2Int
		{
			union
			{
				struct
				{
					int x, y;
				};
				int value[2];
			};

			Vector2Int();
			Vector2Int(int xy);
			Vector2Int(int x, int y);
			Vector2Int(const Vector2& v);

			// �t�x�N�g��
			Vector2Int operator-();
			// �x�N�g���̐������m�̎l�����Z
			const Vector2Int operator+(const Vector2Int& v)const;
			const Vector2Int operator-(const Vector2Int& v)const;
			const Vector2Int operator*(const Vector2Int& v)const;
			const Vector2Int operator/(const Vector2Int& v)const;
			Vector2Int& operator+=(const Vector2Int& v);
			Vector2Int& operator-=(const Vector2Int& v);
			Vector2Int& operator*=(const Vector2Int& v);
			Vector2Int& operator/=(const Vector2Int& v);

			const Vector2Int operator*(int value)const;
			const Vector2Int operator/(int value)const;
			Vector2Int& operator*=(int value);
			Vector2Int& operator/=(int value);
		};
	}
}
