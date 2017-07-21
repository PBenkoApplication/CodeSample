#ifndef BOUNDINGSPHERE_H
#define BOUNDINGSPHERE_H
#include "../../Mathematics/Vector3f.h"

namespace BAME
{
	class BoundingSphere
	{
	public:
		BoundingSphere();
		BoundingSphere(Vector3f const& position, float radius);

		float GetRadius() const;
		Vector3f const& GetPosition() const;

	private:
		float mRadius;
		Vector3f mPosition;
	};
}
#endif