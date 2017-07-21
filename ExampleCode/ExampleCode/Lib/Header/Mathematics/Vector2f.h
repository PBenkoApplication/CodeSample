#ifndef VECTOR2F_H
#define VECTOR2F_H
#include <string>

namespace BAME
{
	class Vector2f
	{
	public:
		Vector2f();
		Vector2f(float x, float y);
		Vector2f(const Vector2f& v);
		~Vector2f();
		float GetX() const;
		float GetY() const;
		void SetX(const float x);
		void SetY(const float y);
		Vector2f Abs() const;
		Vector2f Normalized() const;
		float Length() const;
		std::string ToString() const;

		float Dot(const Vector2f& v) const;

		static Vector2f Zero();

		//Operator Überladungen
		friend Vector2f operator+(Vector2f const& lhs, Vector2f const& rhs);
		friend Vector2f operator-(Vector2f const& lhs, Vector2f const& rhs);
		friend Vector2f operator*(float const lhs, Vector2f const& rhs);
		friend Vector2f operator/(Vector2f const& lhs, float const rhs);
		friend bool operator==(const Vector2f& lhs, const Vector2f& rhs);
		friend bool operator!=(const Vector2f& lhs, const Vector2f& rhs);
		Vector2f& operator+=(Vector2f const& rhs);
		Vector2f& operator-=(Vector2f const& rhs);
		Vector2f& operator/=(float const rhs);
		
	private:
		float mX;
		float mY;
	};
}

#endif
