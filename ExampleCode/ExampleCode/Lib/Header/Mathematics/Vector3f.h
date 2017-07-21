#ifndef VECTOR3F_H
#define VECTOR3F_H
#include <string>


namespace BAME
{
	class Quaternion;
	class Vector3f
	{
	
	private:
		friend class Matrix4x4f;
	public:
		Vector3f();
		Vector3f(float x, float y, float z);
		//Vector3f(const Vector3f& v);
		~Vector3f();
		float GetX() const;
		float GetY() const;
		float GetZ() const;
		void SetX(const float x);
		void SetY(const float y);
		void SetZ(const float z);
		static Vector3f Zero();
		Vector3f Cross(const Vector3f& v) const;
		float Dot(const Vector3f& v) const;
		Vector3f Rotate(const float angle, const Vector3f& axis) const;
		Vector3f Rotate(const Quaternion& rotation) const;
		Vector3f Abs() const;
		Vector3f Normalized() const;
		float Length() const;
		Vector3f Translated(const float x, const float y, const float z) const;
		Vector3f Translated(const Vector3f& vector) const;
		std::string ToString() const;
		bool IsEqual(Vector3f const& other) const;
		Vector3f Negate() const;


		float RotateToVector(Vector3f const& vec) const;
		float CalcSignedAngle(Vector3f const& vec, Vector3f const& axis) const;
		float CalcAngle360(Vector3f const& vec) const;


		static Vector3f GetZero();

		//Operator Überladungen
		friend Vector3f operator+(Vector3f const& lhs, Vector3f const& rhs);
		friend Vector3f operator-(Vector3f const& lhs, Vector3f const& rhs);
		friend Vector3f operator*(float const lhs, Vector3f const& rhs);
		friend Vector3f operator*(Vector3f const& lhs, float const rhs);
		friend Vector3f operator/(Vector3f const& lhs, float const rhs);
		friend bool operator==(const Vector3f& lhs, const Vector3f& rhs);
		friend bool operator!=(const Vector3f& lhs, const Vector3f& rhs);
		Vector3f& operator+=(Vector3f const& rhs);
		Vector3f& operator-=(Vector3f const& rhs);
		Vector3f& operator/=(float const rhs);
		Vector3f& operator*=(float const rhs);

	private:
		float mX;
		float mY;
		float mZ;
	};
}

#endif
