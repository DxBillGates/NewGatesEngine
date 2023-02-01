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
			/// このインスタンスの長さを返す関数
			/// </summary>
			/// <returns>長さ</returns>
			float Length()const;
			/// <summary>
			/// このインスタンスの正規化ベクトルを返す関数
			/// </summary>
			/// <returns>正規化ベクトル</returns>
			Vector4 Normalize()const;

			/// <summary>
			/// 正規化ベクトルを返す関数
			/// </summary>
			/// <param name="v">ベクトル</param>
			/// <returns>正規化ベクトル</returns>
			static Vector4 Normalize(const Vector4& v);
			/// <summary>
			/// 二つのベクトルの各成分を比較して小さい成分を返す
			/// </summary>
			/// <param name="minVector">比較対象</param>
			/// <param name="comparison">比較対象</param>
			/// <returns>小さい成分</returns>
			static Vector4 Min(const Vector4& minVector, const Vector4& comparison);
			/// <summary>
			/// 二つのベクトルの各成分を比較して大きい成分を返す
			/// </summary>
			/// <param name="maxVector">比較対象</param>
			/// <param name="comparison">比較対象</param>
			/// <returns>大きい成分</returns>
			static Vector4 Max(const Vector4& maxVector, const Vector4& comparison);
			/// <summary>
			/// minとmaxを利用し各成分がminVector,maxVectorの成分内に収める
			/// </summary>
			/// <param name="minVector">比較対象</param>
			/// <param name="maxVector">比較対象</param>
			/// <param name="comparison">比較対象</param>
			/// <returns>min,maxに収まった成分</returns>
			static Vector4 Clamp(const Vector4& minVector, const Vector4& maxVector, const Vector4& comparison);

			// 逆ベクトル
			Vector4 operator-()const;
			// ベクトルの成分同士の四則演算
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
