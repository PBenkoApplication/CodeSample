#ifndef BOUNDINGBOX_H
#define BOUNDINGBOX_H
#include <cmath>
#include "Mathematics/Vector3f.h"

namespace BAME
{
	class BoundingBox
	{
	public:

		bool CheckCollision(BoundingBox const& b) const;

		BoundingBox();
		BoundingBox(float minX, float maxX, float minY, float maxY, float minZ, float maxZ);
		~BoundingBox();

		float GetMinX() const { return mMinX; }
		float GetMaxX() const { return mMaxX; }

		float GetMinY() const { return mMinY; }
		float GetMaxY() const { return mMaxY; }

		float GetMinZ() const { return mMinZ; }
		float GetMaxZ() const { return mMaxZ; }

	private:
		float mMinX;
		float mMaxX;
		float mMinY;
		float mMaxY;
		float mMinZ;
		float mMaxZ;

		Vector3f mPosition;
		float mHalfSizeX;
		float mHalfSizeY;
		float mHalfSizeZ;

	};
}
#endif
