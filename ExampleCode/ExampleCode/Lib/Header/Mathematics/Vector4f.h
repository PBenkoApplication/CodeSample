#ifndef VECTOR4F_H
#define VECTOR4F_H
#include <string>

namespace BAME
{
	class Vector4f
	{
	public:
		Vector4f();
		Vector4f(float x, float y, float z, float w);
		Vector4f(const Vector4f& v);
		~Vector4f();
		float GetX() const;
		float GetY() const;
		float GetZ() const;
		float GetW() const;
		void SetX(const float x);
		void SetY(const float y);
		void SetZ(const float z);
		void SetW(const float w);
		Vector4f Cross(const Vector4f& v) const;
		float Dot(const Vector4f& v) const;
		Vector4f Rotate(const float angle, const Vector4f& axis) const;
		Vector4f Abs() const;
		Vector4f Normalized() const;
		float Length() const;
		Vector4f Translated(const float x, const float y, const float z, const float w) const;
		Vector4f Translated(const Vector4f& vector) const;
		std::string ToString() const;
		bool IsEqual(Vector4f const& other) const;

		//Operator Überladungen
		friend Vector4f operator+(Vector4f const& lhs, Vector4f const& rhs);
		friend Vector4f operator-(Vector4f const& lhs, Vector4f const& rhs);
		friend Vector4f operator*(float const lhs, Vector4f const& rhs);
		friend Vector4f operator/(Vector4f const& lhs, float const rhs);
		friend bool operator==(const Vector4f& lhs, const Vector4f& rhs);
		friend bool operator!=(const Vector4f& lhs, const Vector4f& rhs);
		Vector4f& operator+=(Vector4f const& rhs);
		Vector4f& operator-=(Vector4f const& rhs);
		Vector4f& operator/=(float const rhs);


	private:
		float mX;
		float mY;
		float mZ;
		float mW;
	};
}

#endif
