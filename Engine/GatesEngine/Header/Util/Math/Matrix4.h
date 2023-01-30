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
			/// この行列の逆行列を返す
			/// </summary>
			/// <returns>この行列の逆行列を返す</returns>
			Matrix4x4 Inverse()const;
			/// <summary>
			/// この行列の転置行列を返す
			/// </summary>
			/// <returns>この行列の転置行列を返す</returns>
			Matrix4x4 Transpose()const;
			/// <summary>
			/// この行列の行列式を返す
			/// </summary>
			/// <returns>この行列の行列式を返す</returns>
			float Determinant()const;
			/// <summary>
			/// この行列の軸を返す
			/// </summary>
			/// <returns>この行列の軸</returns>
			Axis GetAxis()const;

			/// <summary>
			/// 単位行列を生成
			/// </summary>
			/// <returns>単位行列</returns>
			static Matrix4x4 Identity();
			/// <summary>
			/// 行列の逆行列を取得する
			/// </summary>
			/// <param name="matrix">対象の行列</param>
			/// <returns>対象の行列の逆行列</returns>
			static Matrix4x4 Inverse(const Matrix4x4& matrix);
			/// <summary>
			/// 行列の転置行列を取得する
			/// </summary>
			/// <param name="matrix">対象の行列</param>
			/// <returns>対象の行列の転置行列</returns>
			static Matrix4x4 Transpose(const Matrix4x4& matrix);
			/// <summary>
			/// 行列の行列式を取得する
			/// </summary>
			/// <param name="matrix">対象の行列</param>
			/// <returns>対象の行列の行列式</returns>
			static float Determinant(const Matrix4x4& matrix);
			/// <summary>
			/// 行列の軸を取得する
			/// </summary>
			/// <param name="matrix">対象行列</param>
			/// <returns>対象行列の軸</returns>
			static Axis GetAxis(const Matrix4x4& matrix);
			/// <summary>
			/// 行列を線形補間する
			/// </summary>
			/// <param name="s">開始行列</param>
			/// <param name="e">終了行列</param>
			/// <param name="t">時間 0 ~ 1</param>
			/// <returns>行列の線形補間結果</returns>
			static Matrix4x4 Lerp(const Matrix4x4& s, const Matrix4x4& e, float t);

			/// <summary>
			/// スケール行列を生成する関数
			/// </summary>
			/// <param name="scale">スケール</param>
			/// <returns>スケール行列</returns>
			static Matrix4x4 Scale(const Vector3& scale);
			/// <summary>
			/// X軸での回転行列を生成する関数
			/// </summary>
			/// <param name="angle">度数法</param>
			/// <returns>X軸回転行列</returns>
			static Matrix4x4 RotateX(float angle);
			/// <summary>
			/// Y軸での回転行列を生成する関数
			/// </summary>
			/// <param name="angle">度数法</param>
			/// <returns>Y軸回転行列</returns>
			static Matrix4x4 RotateY(float angle);
			/// <summary>
			/// Y軸での回転行列を生成する関数
			/// </summary>
			/// <param name="angle">度数法</param>
			/// <returns>Y軸回転行列</returns>
			static Matrix4x4 RotateZ(float angle);
			/// <summary>
			/// ZXYの順で回転行列を生成する関数
			/// </summary>
			/// <param name="angles">度数法</param>
			/// <returns>ZXY回転行列</returns>
			static Matrix4x4 RotateZXY(const Vector3& angles);
			/// <summary>
			/// 平行移動行列を生成する関数
			/// </summary>
			/// <param name="v">位置</param>
			/// <returns>平行移動行列</returns>
			static Matrix4x4 Translate(const Vector3& pos);
			/// <summary>
			/// ベクトルと行列から新たなベクトルを生成する関数
			/// </summary>
			/// <param name="vector">ベクトル</param>
			/// <param name="matrix">行列</param>
			/// <returns>生成されたベクトル</returns>
			static Vector3 Transform(const Vector3& vector,const Matrix4x4& matrix);

			/// <summary>
			/// 位置、視点位置、上ベクトルを指定してビュー行列を生成する関数
			/// </summary>
			/// <param name="pos">位置</param>
			/// <param name="focasPos">視点位置</param>
			/// <param name="upDir">上ベクトル</param>
			/// <returns>ビュー行列</returns>
			static Matrix4x4 GetViewMatrixLookAt(const Vector3& pos, const Vector3& focasPos, const Vector3& upDir);
			/// <summary>
			/// 位置、方向、上ベクトルを指定してビュー行列を生成する関数
			/// </summary>
			/// <param name="pos">位置</param>
			/// <param name="direction">方向</param>
			/// <param name="upDir">上ベクトル</param>
			/// <returns>ビュー行列</returns>
			static Matrix4x4 GetViewMatrixLookTo(const Vector3& pos, const Vector3& direction, const Vector3& upDir);
			/// <summary>
			/// 透視投影行列を生成する関数
			/// </summary>
			/// <param name="fov">視野角(横ではなく縦)</param>
			/// <param name="aspect">アスペクト比</param>
			/// <param name="nearClip">ニア―クリップ</param>
			/// <param name="farClip">ファークリップ</param>
			/// <returns>透視投影行列</returns>
			static Matrix4x4 GetPerspectiveMatrix(float fov, float aspect, float nearClip = 1.0f, float farClip = 10000.0f);
			/// <summary>
			/// 平行投影行列(奥行きがあるオブジェクト対応)を生成する関数
			/// </summary>
			/// <param name="size">サイズ</param>
			/// <param name="nearClip">ニア―クリップ</param>
			/// <param name="farClip">ファークリップ</param>
			/// <returns>平行投影行列</returns>
			static Matrix4x4 GetOrthographMatrix(const Vector2& size, float nearClip = 0, float farClip = 1);
			/// <summary>
			/// ビューポート行列を生成
			/// </summary>
			/// <param name="size">ビューポートのサイズ</param>
			/// <param name="offset">ビューポートの位置</param>
			/// <returns>ビューポート行列</returns>
			static Matrix4x4 GetViewportMatrix(const Vector2& size, const Vector2& offset = {});
			/// <summary>
			/// ワールド座標をスクリーン座標に変換する
			/// </summary>
			/// <param name="worldPos">ワールド座標</param>
			/// <param name="view">ビュー行列</param>
			/// <param name="proj">プロジェクション行列</param>
			/// <returns>スクリーン座標</returns>
			static Vector2 ConvertWorldToScreen(const Vector3& worldPos, const Matrix4x4& view, const Matrix4x4& proj);
			///// <summary>
			///// スクリーン座標をワールド座標に変換する
			///// </summary>
			///// <param name="screenPos">スクリーン座標</param>
			///// <param name="view">ビュー行列</param>
			///// <param name="proj">プロジェクション行列</param>
			///// <param name="viewPort">ビューポート行列</param>
			///// <returns>ワールド座標</returns>
			//static Vector3 ConvertScreenToWorld(const Vector2& screenPos, const Matrix4x4& view, const Matrix4x4& proj, const Matrix4x4& viewPort);

			const Matrix4x4 operator*(const Matrix4x4& matrix)const;
			Matrix4x4& operator*=(const Matrix4x4& matrix);
		};
	}
}