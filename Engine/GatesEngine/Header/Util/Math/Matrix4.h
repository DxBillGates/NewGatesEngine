#pragma once
#include "Axis.h"
#include "Vector2.h"

namespace GE
{
	namespace Math
	{
		struct Matrix4x4
		{
			union
			{
				float m[4][4];
				struct
				{
					float _00, _01, _02, _03;
					float _10, _11, _12, _13;
					float _20, _21, _22, _23;
					float _30, _31, _32, _33;
				};
			};

			Matrix4x4();
			Matrix4x4
			(
				float m00, float m01, float m02, float m03,
				float m10, float m11, float m12, float m13,
				float m20, float m21, float m22, float m23,
				float m30, float m31, float m32, float m33
			);

			/// <summary>
			/// ���̍s��̋t�s���Ԃ�
			/// </summary>
			/// <returns>���̍s��̋t�s���Ԃ�</returns>
			Matrix4x4 Inverse()const;
			/// <summary>
			/// ���̍s��̓]�u�s���Ԃ�
			/// </summary>
			/// <returns>���̍s��̓]�u�s���Ԃ�</returns>
			Matrix4x4 Transpose()const;
			/// <summary>
			/// ���̍s��̍s�񎮂�Ԃ�
			/// </summary>
			/// <returns>���̍s��̍s�񎮂�Ԃ�</returns>
			float Determinant()const;
			/// <summary>
			/// ���̍s��̎���Ԃ�
			/// </summary>
			/// <returns>���̍s��̎�</returns>
			Axis GetAxis()const;

			/// <summary>
			/// �P�ʍs��𐶐�
			/// </summary>
			/// <returns>�P�ʍs��</returns>
			static Matrix4x4 Identity();
			/// <summary>
			/// �s��̋t�s����擾����
			/// </summary>
			/// <param name="matrix">�Ώۂ̍s��</param>
			/// <returns>�Ώۂ̍s��̋t�s��</returns>
			static Matrix4x4 Inverse(const Matrix4x4& matrix);
			/// <summary>
			/// �s��̓]�u�s����擾����
			/// </summary>
			/// <param name="matrix">�Ώۂ̍s��</param>
			/// <returns>�Ώۂ̍s��̓]�u�s��</returns>
			static Matrix4x4 Transpose(const Matrix4x4& matrix);
			/// <summary>
			/// �s��̍s�񎮂��擾����
			/// </summary>
			/// <param name="matrix">�Ώۂ̍s��</param>
			/// <returns>�Ώۂ̍s��̍s��</returns>
			static float Determinant(const Matrix4x4& matrix);
			/// <summary>
			/// �s��̎����擾����
			/// </summary>
			/// <param name="matrix">�Ώۍs��</param>
			/// <returns>�Ώۍs��̎�</returns>
			static Axis GetAxis(const Matrix4x4& matrix);
			/// <summary>
			/// �s�����`��Ԃ���
			/// </summary>
			/// <param name="s">�J�n�s��</param>
			/// <param name="e">�I���s��</param>
			/// <param name="t">���� 0 ~ 1</param>
			/// <returns>�s��̐��`��Ԍ���</returns>
			static Matrix4x4 Lerp(const Matrix4x4& s, const Matrix4x4& e, float t);

			/// <summary>
			/// �X�P�[���s��𐶐�����֐�
			/// </summary>
			/// <param name="scale">�X�P�[��</param>
			/// <returns>�X�P�[���s��</returns>
			static Matrix4x4 Scale(const Vector3& scale);
			/// <summary>
			/// X���ł̉�]�s��𐶐�����֐�
			/// </summary>
			/// <param name="angle">�x���@</param>
			/// <returns>X����]�s��</returns>
			static Matrix4x4 RotateX(float angle);
			/// <summary>
			/// Y���ł̉�]�s��𐶐�����֐�
			/// </summary>
			/// <param name="angle">�x���@</param>
			/// <returns>Y����]�s��</returns>
			static Matrix4x4 RotateY(float angle);
			/// <summary>
			/// Y���ł̉�]�s��𐶐�����֐�
			/// </summary>
			/// <param name="angle">�x���@</param>
			/// <returns>Y����]�s��</returns>
			static Matrix4x4 RotateZ(float angle);
			/// <summary>
			/// ZXY�̏��ŉ�]�s��𐶐�����֐�
			/// </summary>
			/// <param name="angles">�x���@</param>
			/// <returns>ZXY��]�s��</returns>
			static Matrix4x4 RotateZXY(const Vector3& angles);
			/// <summary>
			/// ���s�ړ��s��𐶐�����֐�
			/// </summary>
			/// <param name="v">�ʒu</param>
			/// <returns>���s�ړ��s��</returns>
			static Matrix4x4 Translate(const Vector3& pos);
			/// <summary>
			/// �x�N�g���ƍs�񂩂�V���ȃx�N�g���𐶐�����֐�
			/// </summary>
			/// <param name="vector">�x�N�g��</param>
			/// <param name="matrix">�s��</param>
			/// <returns>�������ꂽ�x�N�g��</returns>
			static Vector3 Transform(const Vector3& vector,const Matrix4x4& matrix);

			/// <summary>
			/// �ʒu�A���_�ʒu�A��x�N�g�����w�肵�ăr���[�s��𐶐�����֐�
			/// </summary>
			/// <param name="pos">�ʒu</param>
			/// <param name="focasPos">���_�ʒu</param>
			/// <param name="upDir">��x�N�g��</param>
			/// <returns>�r���[�s��</returns>
			static Matrix4x4 GetViewMatrixLookAt(const Vector3& pos, const Vector3& focasPos, const Vector3& upDir);
			/// <summary>
			/// �ʒu�A�����A��x�N�g�����w�肵�ăr���[�s��𐶐�����֐�
			/// </summary>
			/// <param name="pos">�ʒu</param>
			/// <param name="direction">����</param>
			/// <param name="upDir">��x�N�g��</param>
			/// <returns>�r���[�s��</returns>
			static Matrix4x4 GetViewMatrixLookTo(const Vector3& pos, const Vector3& direction, const Vector3& upDir);
			/// <summary>
			/// �������e�s��𐶐�����֐�
			/// </summary>
			/// <param name="fov">����p(���ł͂Ȃ��c)</param>
			/// <param name="aspect">�A�X�y�N�g��</param>
			/// <param name="nearClip">�j�A�\�N���b�v</param>
			/// <param name="farClip">�t�@�[�N���b�v</param>
			/// <returns>�������e�s��</returns>
			static Matrix4x4 GetPerspectiveMatrix(float fov, float aspect, float nearClip = 1.0f, float farClip = 10000.0f);
			/// <summary>
			/// ���s���e�s��(���s��������I�u�W�F�N�g�Ή�)�𐶐�����֐�
			/// </summary>
			/// <param name="size">�T�C�Y</param>
			/// <param name="nearClip">�j�A�\�N���b�v</param>
			/// <param name="farClip">�t�@�[�N���b�v</param>
			/// <returns>���s���e�s��</returns>
			static Matrix4x4 GetOrthographMatrix(const Vector2& size, float nearClip = 0, float farClip = 1);
			/// <summary>
			/// �r���[�|�[�g�s��𐶐�
			/// </summary>
			/// <param name="size">�r���[�|�[�g�̃T�C�Y</param>
			/// <param name="offset">�r���[�|�[�g�̈ʒu</param>
			/// <returns>�r���[�|�[�g�s��</returns>
			static Matrix4x4 GetViewportMatrix(const Vector2& size, const Vector2& offset = {});
			/// <summary>
			/// ���[���h���W���X�N���[�����W�ɕϊ�����
			/// </summary>
			/// <param name="worldPos">���[���h���W</param>
			/// <param name="view">�r���[�s��</param>
			/// <param name="proj">�v���W�F�N�V�����s��</param>
			/// <returns>�X�N���[�����W</returns>
			static Vector2 ConvertWorldToScreen(const Vector3& worldPos, const Matrix4x4& view, const Matrix4x4& proj);
			///// <summary>
			///// �X�N���[�����W�����[���h���W�ɕϊ�����
			///// </summary>
			///// <param name="screenPos">�X�N���[�����W</param>
			///// <param name="view">�r���[�s��</param>
			///// <param name="proj">�v���W�F�N�V�����s��</param>
			///// <param name="viewPort">�r���[�|�[�g�s��</param>
			///// <returns>���[���h���W</returns>
			//static Vector3 ConvertScreenToWorld(const Vector2& screenPos, const Matrix4x4& view, const Matrix4x4& proj, const Matrix4x4& viewPort);

			const Matrix4x4 operator*(const Matrix4x4& matrix)const;
			Matrix4x4& operator*=(const Matrix4x4& matrix);
		};
	}
}