#ifndef FRUSTUM_H
#define FRUSTUM_H
#include "../../Mathematics/Vector3f.h"

namespace BAME
{

	class Frustum
	{
	public:
		
		static enum {OUTSIDE, INTERSECT, INSIDE};

		Vector3f mCamPos;
		Vector3f X, Y, Z; //the camera referential
		float nearD, farD, width, height, ratio, tang;

		
		Frustum();
		~Frustum();

		void setCamInternals(float angle, float ratio, float nearD, float farD);
		void setCamDef(Vector3f const& p, Vector3f const& l, Vector3f const& u);
		int pointInFrustum(Vector3f const& p);
	};
}
#endif
