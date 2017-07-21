#ifndef VERTEXBONE_H
#define VERTEXBONE_H
#include "Vertex.h"

namespace BAME
{
	class VertexBone: public Vertex
	{
	public:
		VertexBone();
		VertexBone(Vector3f const& pos, ColorRGB const& color, Vector2f const& texCoord, Vector3f const& normal, Vector3f const& tangent, Vector3f const& binormal, Vector4f const& boneIDs, Vector4f const& boneWeights);

		Vector4f const& GetBoneIDs() const;
		Vector4f const& GetBoneWeights() const;

	protected:
		Vector4f mBoneIDs;
		Vector4f mBoneWeights;
	};
}
#endif