#include "BoundingBox.h"

namespace BAME
{
	

	BoundingBox::BoundingBox() :
		mMinX(0),
		mMaxX(0),
		mMinY(0),
		mMaxY(0),
		mMinZ(0),
		mMaxZ(0),
		mHalfSizeX(0),
		mHalfSizeY(0),
		mHalfSizeZ(0)
	{
	}

	BoundingBox::BoundingBox(float minX, float maxX, float minY, float maxY, float minZ, float maxZ):
		mMinX(minX),
		mMaxX(maxX),
		mMinY(minY),
		mMaxY(maxY),
		mMinZ(minZ),
		mMaxZ(maxZ)
	{
		mHalfSizeX = maxX - minX;
		mHalfSizeY = maxY - minY;
		mHalfSizeZ = maxZ - minZ;

		mPosition = Vector3f(mHalfSizeX, mHalfSizeY, mHalfSizeZ);
	}

	BoundingBox::~BoundingBox()
	{
	}

	bool BoundingBox::CheckCollision(BoundingBox const& b) const
	{
		if (abs(mPosition.GetX() - b.mPosition.GetX()) < mHalfSizeX + b.mHalfSizeX)
		{
			if (abs(mPosition.GetY() - b.mPosition.GetY()) < mHalfSizeY + b.mHalfSizeY)
			{
					return true;
			}
		}

		return false;
	}
}