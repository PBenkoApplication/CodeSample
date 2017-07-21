#ifndef QUATERNION_H
#define QUATERNION_H
#include "Matrix4x4f.h"


namespace BAME
{
	class Quaternion
	{
	public:
		Quaternion();
		Quaternion(const float s, const float x, const float y, const float z);
		void SetRollPitchYaw(float roll, float pitch, float yaw);
		Quaternion(const Quaternion& q);
		Quaternion(const float angle, Vector3f const& rotationAxis);
		~Quaternion();
		float Length() const;
		Quaternion Normalized() const;
		Quaternion Conjugated() const;
		Quaternion SlerpTo(Quaternion const& q2, float t) const;
		Quaternion Multiply(const Quaternion& r) const;
		Quaternion Multiply(const Vector3f& r) const;
		void Init(const float s, const float x, const float y, const float z);

		Matrix4x4f GetAsMatrix4x4f() const;

		float GetX() const;
		float GetY() const;
		float GetZ() const;
		float GetS() const;
		void SetX(const float x);
		void SetY(const float y);
		void SetZ(const float z);
		void SetS(const float s);
	private:
		float mX;
		float mY;
		float mZ;
		float mS;

	public:
		friend Vector3f operator*(Quaternion const& quat, Vector3f const& vec);
		friend Quaternion operator+(Quaternion const& lhs, Quaternion const& rhs);
	};
}
#endif
