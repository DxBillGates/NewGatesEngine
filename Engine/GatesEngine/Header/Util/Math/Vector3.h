#pragma once

namespace GE
{
	namespace Math
	{
		struct Vector3
		{
			union
			{
				struct
				{
					float x, y, z;
				};
				float value[3];

			};

			Vector3();
			Vector3(float xyz);
			Vector3(float x, float y, float z);
			Vector3(float vector2Value[2]);

			/// <summary>
			/// ���C���X�^���X�̃x�N�g���̒�����Ԃ�
			/// </summary>
			/// <returns>���C���X�^���X�̃x�N�g���̒���</returns>
			float Length() const;
			/// <summary>
			/// ���C���X�^���X�̐��K���x�N�g����Ԃ�
			/// </summary>
			/// <returns>���C���X�^���X�̐��K���x�N�g��</returns>
			Vector3 Normalize() const;
			///// <summary>
			///// ���C���X�^���X�ƈ����Ŏ󂯎�����x�N�g���Ƃ̊O�ς�Ԃ�
			///// </summary>
			///// <param name="v">�Ώۂ̃x�N�g��</param>
			///// <returns>���C���X�^���X�ƈ����Ŏ󂯎�����x�N�g���Ƃ̊O��</returns>
			//Vector3 Cross(const Vector3& v) const;
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
			static float Distance(const Vector3& p1, const Vector3& p2);
			/// <summary>
			/// �Ώۂ̃x�N�g���̐��K���x�N�g����Ԃ�
			/// </summary>
			/// <param name="v">�Ώۂ̃x�N�g��</param>
			/// <returns>�Ώۂ̃x�N�g���̐��K���x�N�g��</returns>
			static Vector3 Normalize(const Vector3& v);
			/// <summary>
			/// ��̃x�N�g���̊O�ς�Ԃ�
			/// </summary>
			/// <param name="v1">�x�N�g��A</param>
			/// <param name="v2">�x�N�g��B</param>
			/// <returns>��̃x�N�g���̊O��</returns>
			static Vector3 Cross(const Vector3& v1, const Vector3& v2);
			/// <summary>
			/// ��̃x�N�g���̓��ς�Ԃ�
			/// </summary>
			/// <param name="v1">�x�N�g��A</param>
			/// <param name="v2">�x�N�g��B</param>
			/// <returns>��̃x�N�g���̓���</returns>
			static float Dot(const Vector3& v1, const Vector3& v2);
			/// <summary>
			/// ��_�ԁA�܂��͓�̃x�N�g������`��Ԃ������ʂ�Ԃ�
			/// </summary>
			/// <param name="v1">�_A or �x�N�g��A</param>
			/// <param name="v2">�_B or �x�N�g��B</param>
			/// <param name="t">��ԓx0 ~ 1</param>
			/// <returns>��_�ԁA�܂��͓�̃x�N�g������`��Ԃ�������</returns>
			static Vector3 Lerp(const Vector3& v1, const Vector3& v2, float t);
			/// <summary>
			/// ��̃x�N�g���̊e�������r���ď�����������Ԃ�
			/// </summary>
			/// <param name="minVector">��r�Ώ�</param>
			/// <param name="comparison">��r�Ώ�</param>
			/// <returns>����������</returns>
			static Vector3 Min(const Vector3& minVector, const Vector3& comparison);
			/// <summary>
			/// ��̃x�N�g���̊e�������r���đ傫��������Ԃ�
			/// </summary>
			/// <param name="maxVector">��r�Ώ�</param>
			/// <param name="comparison">��r�Ώ�</param>
			/// <returns>�傫������</returns>
			static Vector3 Max(const Vector3& maxVector, const Vector3& comparison);
			/// <summary>
			/// min��max�𗘗p���e������minVector,maxVector�̐������Ɏ��߂�
			/// </summary>
			/// <param name="minVector">��r�Ώ�</param>
			/// <param name="maxVector">��r�Ώ�</param>
			/// <param name="comparison">��r�Ώ�</param>
			/// <returns>min,max�Ɏ��܂�������</returns>
			static Vector3 Clamp(const Vector3& minVector, const Vector3& maxVector, const Vector3& comparison);
			/// <summary>
			/// direction��normal�Ŕ��˂�����
			/// </summary>
			/// <param name="direction">�����x�N�g��</param>
			/// <param name="normal">�@���x�N�g��</param>
			/// <param name="p">1 or 2�A1�Ȃ�normal�ɐ����ȃx�N�g���A2�Ȃ甽�˃x�N�g���ɂȂ�</param>
			/// <returns>direction��normal�Ŕ��˂������x�N�g��</returns>
			static Vector3 Reflect(const Vector3& direction, const Vector3& normal, float p = 2);
			/// <summary>
			/// vector��normal�Ɏˉe����
			/// </summary>
			/// <param name="vector">�ˉe���������x�N�g��</param>
			/// <param name="normal">�ˉe�ΏہA���K�E�񐳋K�ǂ���ł���</param>
			/// <returns>normal��vector���ˉe�����x�N�g��</returns>
			static Vector3 Project(const Vector3& vector, const Vector3& normal);

			// �t�x�N�g��
			Vector3 operator-()const;
			// �x�N�g���̐������m�̎l�����Z
			const Vector3 operator+(const Vector3& v)const;
			const Vector3 operator-(const Vector3& v)const;
			const Vector3 operator*(const Vector3& v)const;
			const Vector3 operator/(const Vector3& v)const;
			Vector3& operator+=(const Vector3& v);
			Vector3& operator-=(const Vector3& v);
			Vector3& operator*=(const Vector3& v);
			Vector3& operator/=(const Vector3& v);

			const Vector3 operator*(float value)const;
			const Vector3 operator/(float value)const;
			Vector3& operator*=(float value);
			Vector3& operator/=(float value);
		};

		// Vector3��int�Łi���Z�q�I�[�o�[���[�h�̂݁j
		struct Vector3Int
		{
			union
			{
				struct
				{
					int x, y, z;
				};
				int value[3];
			};

			Vector3Int();
			Vector3Int(int xy);
			Vector3Int(int x, int y, int z);

			// �t�x�N�g��
			Vector3Int operator-();
			// �x�N�g���̐������m�̎l�����Z
			const Vector3Int operator+(const Vector3Int& v)const;
			const Vector3Int operator-(const Vector3Int& v)const;
			const Vector3Int operator*(const Vector3Int& v)const;
			const Vector3Int operator/(const Vector3Int& v)const;
			Vector3Int& operator+=(const Vector3Int& v);
			Vector3Int& operator-=(const Vector3Int& v);
			Vector3Int& operator*=(const Vector3Int& v);
			Vector3Int& operator/=(const Vector3Int& v);

			const Vector3Int operator*(int value)const;
			const Vector3Int operator/(int value)const;
			Vector3Int& operator*=(int value);
			Vector3Int& operator/=(int value);
		};
	}
}