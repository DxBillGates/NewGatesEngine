#pragma once

namespace GE
{
	namespace Math
	{
		struct Vector4
		{
			union
			{
				struct
				{
					float x, y, z, w;
				};
				float value[4];
			};

			Vector4();
			Vector4(float xyzw);
			Vector4(float x, float y, float z, float w);
			Vector4(float vector3Value[3]);

			/// <summary>
			/// ���̃C���X�^���X�̒�����Ԃ��֐�
			/// </summary>
			/// <returns>����</returns>
			float Length()const;
			/// <summary>
			/// ���̃C���X�^���X�̐��K���x�N�g����Ԃ��֐�
			/// </summary>
			/// <returns>���K���x�N�g��</returns>
			Vector4 Normalize()const;

			/// <summary>
			/// ���K���x�N�g����Ԃ��֐�
			/// </summary>
			/// <param name="v">�x�N�g��</param>
			/// <returns>���K���x�N�g��</returns>
			static Vector4 Normalize(const Vector4& v);
			/// <summary>
			/// ��̃x�N�g���̊e�������r���ď�����������Ԃ�
			/// </summary>
			/// <param name="minVector">��r�Ώ�</param>
			/// <param name="comparison">��r�Ώ�</param>
			/// <returns>����������</returns>
			static Vector4 Min(const Vector4& minVector, const Vector4& comparison);
			/// <summary>
			/// ��̃x�N�g���̊e�������r���đ傫��������Ԃ�
			/// </summary>
			/// <param name="maxVector">��r�Ώ�</param>
			/// <param name="comparison">��r�Ώ�</param>
			/// <returns>�傫������</returns>
			static Vector4 Max(const Vector4& maxVector, const Vector4& comparison);
			/// <summary>
			/// min��max�𗘗p���e������minVector,maxVector�̐������Ɏ��߂�
			/// </summary>
			/// <param name="minVector">��r�Ώ�</param>
			/// <param name="maxVector">��r�Ώ�</param>
			/// <param name="comparison">��r�Ώ�</param>
			/// <returns>min,max�Ɏ��܂�������</returns>
			static Vector4 Clamp(const Vector4& minVector, const Vector4& maxVector, const Vector4& comparison);

			// �t�x�N�g��
			Vector4 operator-()const;
			// �x�N�g���̐������m�̎l�����Z
			const Vector4 operator+(const Vector4& v)const;
			const Vector4 operator-(const Vector4& v)const;
			const Vector4 operator*(const Vector4& v)const;
			const Vector4 operator/(const Vector4& v)const;
			Vector4& operator+=(const Vector4& v);
			Vector4& operator-=(const Vector4& v);
			Vector4& operator*=(const Vector4& v);
			Vector4& operator/=(const Vector4& v);

			const Vector4 operator*(float value)const;
			const Vector4 operator/(float value)const;
			Vector4& operator*=(float value);
			Vector4& operator/=(float value);
		};
	}
}
