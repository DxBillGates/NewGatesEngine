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
			/// 自インスタンスのベクトルの長さを返す
			/// </summary>
			/// <returns>自インスタンスのベクトルの長さ</returns>
			float Length() const;
			/// <summary>
			/// 自インスタンスの正規化ベクトルを返す
			/// </summary>
			/// <returns>自インスタンスの正規化ベクトル</returns>
			Vector2 Normalize() const;
			///// <summary>
			///// 自インスタンスと引数で受け取ったベクトルとの外積を返す
			///// </summary>
			///// <param name="v">対象のベクトル</param>
			///// <returns>自インスタンスと引数で受け取ったベクトルとの外積</returns>
			//float Cross(const Vector3& v) const;
			///// <summary>
			///// 自インスタンスと引数で受け取ったベクトルとの内積を返す
			///// </summary>
			///// <param name="v">対象のベクトル</param>
			///// <returns>自インスタンスと引数で受け取ったベクトルとの内積</returns>
			//float Dot(const Vector3& v) const;

			/// <summary>
			/// 二点間の距離を返す
			/// </summary>
			/// <param name="p1">点A</param>
			/// <param name="p2">点B</param>
			/// <returns>二点間の距離</returns>
			static float Distance(const Vector2& p1, const Vector2& p2);
			/// <summary>
			/// 対象のベクトルの正規化ベクトルを返す
			/// </summary>
			/// <param name="v">対象のベクトル</param>
			/// <returns>対象のベクトルの正規化ベクトル</returns>
			static Vector2 Normalize(const Vector2& v);
			/// <summary>
			/// 二つのベクトルの外積を返す
			/// </summary>
			/// <param name="v1">ベクトルA</param>
			/// <param name="v2">ベクトルB</param>
			/// <returns>二つのベクトルの外積</returns>
			static float Cross(const Vector2& v1, const Vector2& v2);
			/// <summary>
			/// 二つのベクトルの内積を返す
			/// </summary>
			/// <param name="v1">ベクトルA</param>
			/// <param name="v2">ベクトルB</param>
			/// <returns>二つのベクトルの内積</returns>
			static float Dot(const Vector2& v1, const Vector2& v2);
			/// <summary>
			/// 二点間、または二つのベクトルを線形補間した結果を返す
			/// </summary>
			/// <param name="v1">点A or ベクトルA</param>
			/// <param name="v2">点B or ベクトルB</param>
			/// <param name="t">補間度0 ~ 1</param>
			/// <returns>二点間、または二つのベクトルを線形補間した結果</returns>
			static Vector2 Lerp(const Vector2& v1, const Vector2& v2, float t);
			/// <summary>
			/// 二つのベクトルの各成分を比較して小さい成分を返す
			/// </summary>
			/// <param name="minVector">比較対象</param>
			/// <param name="comparison">比較対象</param>
			/// <returns>小さい成分</returns>
			static Vector2 Min(const Vector2& minVector, const Vector2& comparison);
			/// <summary>
			/// 二つのベクトルの各成分を比較して大きい成分を返す
			/// </summary>
			/// <param name="maxVector">比較対象</param>
			/// <param name="comparison">比較対象</param>
			/// <returns>大きい成分</returns>
			static Vector2 Max(const Vector2& maxVector, const Vector2& comparison);
			/// <summary>
			/// minとmaxを利用し各成分がminVector,maxVectorの成分内に収める
			/// </summary>
			/// <param name="minVector">比較対象</param>
			/// <param name="maxVector">比較対象</param>
			/// <param name="comparison">比較対象</param>
			/// <returns>min,maxに収まった成分</returns>
			static Vector2 Clamp(const Vector2& minVector, const Vector2& maxVector, const Vector2& comparison);
			// 逆ベクトル
			Vector2 operator-()const;
			// ベクトルの成分同士の四則演算
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

		// Vector2のint版（演算子オーバーロードのみ）
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

			// 逆ベクトル
			Vector2Int operator-();
			// ベクトルの成分同士の四則演算
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
