#ifndef ISOUNDLISTENER_H
#define ISOUNDLISTENER_H
#include "../../Mathematics/Vector3f.h"

namespace BAME
{
	///Beschreibt einen Listener im 3D Raum
	class ISoundListener
	{
	public:
		ISoundListener(Vector3f const& position = Vector3f::GetZero(), Vector3f const& velocity = Vector3f::GetZero(),
		               Vector3f const& orientationAt = Vector3f::GetZero(), Vector3f const& orientationUp = Vector3f::GetZero());
		virtual ~ISoundListener();

		Vector3f const& GetPosition() const;
		virtual void SetPosition(const Vector3f& position) = 0;
		Vector3f const& GetVelocity() const;
		virtual void SetVelocity(const Vector3f& velocity) = 0;
		Vector3f const& GetOrientationAt() const;
		virtual void SetOrientationAt(const Vector3f& orientationAt) = 0;
		Vector3f GetOrientationUp() const;
		virtual void SetOrientationUp(const Vector3f& orientationUp) = 0;

	private:
		Vector3f mPosition;
		Vector3f mVelocity;
		Vector3f mOrientationAt;
		Vector3f mOrientationUp;
	};
}
#endif
