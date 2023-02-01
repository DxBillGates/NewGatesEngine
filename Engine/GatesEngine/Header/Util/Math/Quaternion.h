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
			/// クォータニオンの共役を返す
			/// </summary>
			/// <returns>クォータニオンの共役</returns>
			Quaternion Conjugate()const;
			/// <summary>
			/// 正規化
			/// </summary>
			/// <returns>正規化した結果</returns>
			Quaternion Normalize()const;
			/// <summary>
			/// 大きさを取得
			/// </summary>
			/// <returns>大きさを取得</returns>
			float Length()const;
			/// <summary>
			/// 回転軸を取得
			/// </summary>
			/// <returns>回転軸</returns>
			Vector3 GetAxis()const;
			/// <summary>
			/// セットされてるクォータニオンから回転行列を作成する
			/// </summary>
			/// <returns>回転行列</returns>
			Matrix4x4 Rotation()const;
			/// <summary>
			/// クォータニオンからオイラー角に変換する
			/// </summary>
			/// <returns>オイラー角(ラジアン)</returns>
			Vector3 EulerRadian()const;
			/// <summary>
			/// クォータニオンからオイラー角に変換する
			/// </summary>
			/// <returns>オイラー角(度数法)</returns>
			Vector3 EulerAngle()const;

			/// <summary>
			/// 共役を生成する関数
			/// </summary>
			/// <param name="q">クォータニオン</param>
			/// <returns>共役</returns>
			static Quaternion Conjugate(const Quaternion& q);
			/// <summary>
			/// 正規化
			/// </summary>
			/// <param name="q">クォータニオン</param>
			/// <returns>正規化クォータニオン</returns>
			static Quaternion Normalize(const Quaternion& q);
			/// <summary>
			/// クォータニオンの長さを返す関数
			/// </summary>
			/// <param name="q">クォータニオン</param>
			/// <returns>長さ</returns>
			static float Length(const Quaternion& q);
			/// <summary>
			/// クォータニオンの軸を返す関数
			/// </summary>
			/// <param name="q">クォータニオン</param>
			/// <returns>軸ベクトル</returns>
			static Vector3 GetAxis(const Quaternion& q);
			/// <summary>
			/// クォータニオンから回転行列を生成する関数
			/// </summary>
			/// <param name="q">クォータニオン</param>
			/// <returns>回転行列</returns>
			static Matrix4x4 Rotation(const Quaternion& q);
			/// <summary>
			/// オイラー角からクォータニオンを計算する
			/// </summary>
			/// <param name="angle"></param>
			/// <returns></returns>
			static Quaternion Euler(const Math::Vector3& angle);
			/// <summary>
			/// クォータニオン同士の内積を返す関数
			/// </summary>
			/// <param name="q1">クォータニオン</param>
			/// <param name="q2">クォータニオン</param>
			/// <returns>内積結果</returns>
			static float Dot(const Quaternion& q1, const Quaternion& q2);
			/// <summary>
			/// 2つのクォータニオンから線形補間を生成する関数
			/// </summary>
			/// <param name="q1">クォータニオン</param>
			/// <param name="q2">クォータニオン</param>
			/// <param name="t">タイム 0 ~ 1</param>
			/// <returns>線形補間</returns>
			static Quaternion Lerp(const Quaternion& q1, const Quaternion& q2, float t);
			/// <summary>
			/// 2つのクォータニオンから球面線形補間を生成する関数
			/// </summary>
			/// <param name="q1">クォータニオン</param>
			/// <param name="q2">クォータニオン</param>
			/// <param name="t">タイム 0 ~ 1</param>
			/// <returns>球面線形補間</returns>
			static Quaternion Slerp(const Quaternion& q1, const Quaternion& q2, float t);
			/// <summary>
			/// directionを向くようなクォータニオンを生成
			/// </summary>
			/// <param name="Vector3">向いてる方向のベクトル</param>
			/// <returns></returns>
			static Quaternion LookDirection(GE::Math::Vector3 direction);
			/// <summary>
			/// ベクトルを回転させる
			/// </summary>
			/// <param name="q">回転させるためのクォータニオン</param>
			/// <param name="v">回転させるベクトル</param>
			/// <returns>回転後のベクトル</returns>
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