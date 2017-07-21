#ifndef PHISYCS_H
#define PHISYCS_H
#include "BoundingVolumes/AABB.h"
#include <vector>
#include "../Geometry/Vertex.h"
#include "BoundingVolumes/OBB.h"
#include "BoundingVolumes/BoundingSphere.h"

namespace BAME
{
	class Physics
	{
	public:
		Physics();
		~Physics();
		static bool CheckCollision(AABB const& a, AABB const& b);
		static AABB CalculateAABB(std::vector<Vertex> const& vertexList);
		static BoundingSphere CalculateBoundingSphere(std::vector<Vector3f> const& pointList);
		static BoundingSphere CalculateBoundingSphere(std::vector<Vertex> const& vertexList);
		static AABB CalculateAABB(std::vector<Vector3f> const& pointList);
		static Vector3f ProjectPointOnLine(Vector3f const& point, Vector3f const& lineDirection);
		static bool CheckCollisionOBBOBBSeperationAxis(OBB const& a, OBB const& b);
		bool CheckCollisionOBBOBBSeperationAxisParallel(OBB const& a, OBB const& b);
	};
}
#endif
