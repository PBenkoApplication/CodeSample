#ifndef AABB_H
#define AABB_H
#include "../../Mathematics/Vector3f.h"
#include <array>
namespace BAME
{
	class AABB
	{
		friend class Physics;
		friend class SceneManager;

	public:
		AABB();
		AABB(float minX, float maxX, float minY, float maxY, float minZ, float maxZ);
		AABB(Vector3f const& minValues, Vector3f const& center);
		~AABB();

		float GetMinX() const { return mMinX; }
		float GetMaxX() const { return mMaxX; }

		float GetMinY() const { return mMinY; }
		float GetMaxY() const { return mMaxY; }

		float GetMinZ() const { return mMinZ; }
		float GetMaxZ() const { return mMaxZ; }

		std::array<Vector3f, 8> GetCorners() const;

		bool Contains(AABB const& aabb) const;

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
