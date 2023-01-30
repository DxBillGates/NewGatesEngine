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
			/// 自インスタンスのベクトルの長さを返す
			/// </summary>
			/// <returns>自インスタンスのベクトルの長さ</returns>
			float Length() const;
			/// <summary>
			/// 自インスタンスの正規化ベクトルを返す
			/// </summary>
			/// <returns>自インスタンスの正規化ベクトル</returns>
			Vector3 Normalize() const;
			///// <summary>
			///// 自インスタンスと引数で受け取ったベクトルとの外積を返す
			///// </summary>
			///// <param name="v">対象のベクトル</param>
			///// <returns>自インスタンスと引数で受け取ったベクトルとの外積</returns>
			//Vector3 Cross(const Vector3& v) const;
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
			static float Distance(const Vector3& p1, const Vector3& p2);
			/// <summary>
			/// 対象のベクトルの正規化ベクトルを返す
			/// </summary>
			/// <param name="v">対象のベクトル</param>
			/// <returns>対象のベクトルの正規化ベクトル</returns>
			static Vector3 Normalize(const Vector3& v);
			/// <summary>
			/// 二つのベクトルの外積を返す
			/// </summary>
			/// <param name="v1">ベクトルA</param>
			/// <param name="v2">ベクトルB</param>
			/// <returns>二つのベクトルの外積</returns>
			static Vector3 Cross(const Vector3& v1, const Vector3& v2);
			/// <summary>
			/// 二つのベクトルの内積を返す
			/// </summary>
			/// <param name="v1">ベクトルA</param>
			/// <param name="v2">ベクトルB</param>
			/// <returns>二つのベクトルの内積</returns>
			static float Dot(const Vector3& v1, const Vector3& v2);
			/// <summary>
			/// 二点間、または二つのベクトルを線形補間した結果を返す
			/// </summary>
			/// <param name="v1">点A or ベクトルA</param>
			/// <param name="v2">点B or ベクトルB</param>
			/// <param name="t">補間度0 ~ 1</param>
			/// <returns>二点間、または二つのベクトルを線形補間した結果</returns>
			static Vector3 Lerp(const Vector3& v1, const Vector3& v2, float t);
			/// <summary>
			/// 二つのベクトルの各成分を比較して小さい成分を返す
			/// </summary>
			/// <param name="minVector">比較対象</param>
			/// <param name="comparison">比較対象</param>
			/// <returns>小さい成分</returns>
			static Vector3 Min(const Vector3& minVector, const Vector3& comparison);
			/// <summary>
			/// 二つのベクトルの各成分を比較して大きい成分を返す
			/// </summary>
			/// <param name="maxVector">比較対象</param>
			/// <param name="comparison">比較対象</param>
			/// <returns>大きい成分</returns>
			static Vector3 Max(const Vector3& maxVector, const Vector3& comparison);
			/// <summary>
			/// minとmaxを利用し各成分がminVector,maxVectorの成分内に収める
			/// </summary>
			/// <param name="minVector">比較対象</param>
			/// <param name="maxVector">比較対象</param>
			/// <param name="comparison">比較対象</param>
			/// <returns>min,maxに収まった成分</returns>
			static Vector3 Clamp(const Vector3& minVector, const Vector3& maxVector, const Vector3& comparison);
			/// <summary>
			/// directionをnormalで反射させる
			/// </summary>
			/// <param name="direction">方向ベクトル</param>
			/// <param name="normal">法線ベクトル</param>
			/// <param name="p">1 or 2、1ならnormalに垂直なベクトル、2なら反射ベクトルになる</param>
			/// <returns>directionをnormalで反射させたベクトル</returns>
			static Vector3 Reflect(const Vector3& direction, const Vector3& normal, float p = 2);
			/// <summary>
			/// vectorをnormalに射影する
			/// </summary>
			/// <param name="vector">射影させたいベクトル</param>
			/// <param name="normal">射影対象、正規・非正規どちらでも可</param>
			/// <returns>normalにvectorを射影したベクトル</returns>
			static Vector3 Project(const Vector3& vector, const Vector3& normal);

			// 逆ベクトル
			Vector3 operator-()const;
			// ベクトルの成分同士の四則演算
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

		// Vector3のint版（演算子オーバーロードのみ）
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

			// 逆ベクトル
			Vector3Int operator-();
			// ベクトルの成分同士の四則演算
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