#pragma once
#include "Vector3.h"
#include "Matrix4.h"
namespace GE
{
	namespace Math
	{
		struct Quaternion
		{
			union
			{
				struct
				{
					float x;
					float y;
					float z;
					float w;
				};

				float value[4];
			};

			Quaternion();
			Quaternion(float x, float y, float z, float w = 1.0f);
			Quaternion(const Vector3& axisVector, float angle);
			Quaternion(const Matrix4x4& m);

			/// <summary>
			/// �N�H�[�^�j�I���̋�����Ԃ�
			/// </summary>
			/// <returns>�N�H�[�^�j�I���̋���</returns>
			Quaternion Conjugate()const;
			/// <summary>
			/// ���K��
			/// </summary>
			/// <returns>���K����������</returns>
			Quaternion Normalize()const;
			/// <summary>
			/// �傫�����擾
			/// </summary>
			/// <returns>�傫�����擾</returns>
			float Length()const;
			/// <summary>
			/// ��]�����擾
			/// </summary>
			/// <returns>��]��</returns>
			Vector3 GetAxis()const;
			/// <summary>
			/// �Z�b�g����Ă�N�H�[�^�j�I�������]�s����쐬����
			/// </summary>
			/// <returns>��]�s��</returns>
			Matrix4x4 Rotation()const;
			/// <summary>
			/// �N�H�[�^�j�I������I�C���[�p�ɕϊ�����
			/// </summary>
			/// <returns>�I�C���[�p(���W�A��)</returns>
			Vector3 EulerRadian()const;
			/// <summary>
			/// �N�H�[�^�j�I������I�C���[�p�ɕϊ�����
			/// </summary>
			/// <returns>�I�C���[�p(�x���@)</returns>
			Vector3 EulerAngle()const;

			/// <summary>
			/// �����𐶐�����֐�
			/// </summary>
			/// <param name="q">�N�H�[�^�j�I��</param>
			/// <returns>����</returns>
			static Quaternion Conjugate(const Quaternion& q);
			/// <summary>
			/// ���K��
			/// </summary>
			/// <param name="q">�N�H�[�^�j�I��</param>
			/// <returns>���K���N�H�[�^�j�I��</returns>
			static Quaternion Normalize(const Quaternion& q);
			/// <summary>
			/// �N�H�[�^�j�I���̒�����Ԃ��֐�
			/// </summary>
			/// <param name="q">�N�H�[�^�j�I��</param>
			/// <returns>����</returns>
			static float Length(const Quaternion& q);
			/// <summary>
			/// �N�H�[�^�j�I���̎���Ԃ��֐�
			/// </summary>
			/// <param name="q">�N�H�[�^�j�I��</param>
			/// <returns>���x�N�g��</returns>
			static Vector3 GetAxis(const Quaternion& q);
			/// <summary>
			/// �N�H�[�^�j�I�������]�s��𐶐�����֐�
			/// </summary>
			/// <param name="q">�N�H�[�^�j�I��</param>
			/// <returns>��]�s��</returns>
			static Matrix4x4 Rotation(const Quaternion& q);
			/// <summary>
			/// �I�C���[�p����N�H�[�^�j�I�����v�Z����
			/// </summary>
			/// <param name="angle"></param>
			/// <returns></returns>
			static Quaternion Euler(const Math::Vector3& angle);
			/// <summary>
			/// �N�H�[�^�j�I�����m�̓��ς�Ԃ��֐�
			/// </summary>
			/// <param name="q1">�N�H�[�^�j�I��</param>
			/// <param name="q2">�N�H�[�^�j�I��</param>
			/// <returns>���ό���</returns>
			static float Dot(const Quaternion& q1, const Quaternion& q2);
			/// <summary>
			/// 2�̃N�H�[�^�j�I��������`��Ԃ𐶐�����֐�
			/// </summary>
			/// <param name="q1">�N�H�[�^�j�I��</param>
			/// <param name="q2">�N�H�[�^�j�I��</param>
			/// <param name="t">�^�C�� 0 ~ 1</param>
			/// <returns>���`���</returns>
			static Quaternion Lerp(const Quaternion& q1, const Quaternion& q2, float t);
			/// <summary>
			/// 2�̃N�H�[�^�j�I�����狅�ʐ��`��Ԃ𐶐�����֐�
			/// </summary>
			/// <param name="q1">�N�H�[�^�j�I��</param>
			/// <param name="q2">�N�H�[�^�j�I��</param>
			/// <param name="t">�^�C�� 0 ~ 1</param>
			/// <returns>���ʐ��`���</returns>
			static Quaternion Slerp(const Quaternion& q1, const Quaternion& q2, float t);
			/// <summary>
			/// direction�������悤�ȃN�H�[�^�j�I���𐶐�
			/// </summary>
			/// <param name="Vector3">�����Ă�����̃x�N�g��</param>
			/// <returns></returns>
			static Quaternion LookDirection(GE::Math::Vector3 direction);
			/// <summary>
			/// �x�N�g������]������
			/// </summary>
			/// <param name="q">��]�����邽�߂̃N�H�[�^�j�I��</param>
			/// <param name="v">��]������x�N�g��</param>
			/// <returns>��]��̃x�N�g��</returns>
			static Vector3 Transform(const Quaternion& q, const Vector3& v);

			Quaternion operator-()const;

			const Quaternion operator+(const Quaternion& q)const;
			const Quaternion operator-(const Quaternion& q)const;
			const Quaternion operator*(const Quaternion& q)const;
			const Quaternion operator*(float s)const;
			const Quaternion operator/(float s)const;

			Quaternion& operator+=(const Quaternion& q);
			Quaternion& operator-=(const Quaternion& q);
			Quaternion& operator*=(const Quaternion& q);
			Quaternion& operator*=(float s);
			Quaternion& operator/=(float s);
		};
	}
}