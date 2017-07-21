#ifndef OBB_H
#define OBB_H
#include "../../Mathematics/Vector3f.h"
#include "../../Mathematics/Matrix4x4f.h"
#include <array>

namespace BAME
{
	class OBB
	{
	public:
		OBB();
		~OBB();


		std::array<Vector3f, 8> GetVertexListWorldSpace() const;

		std::array<Vector3f, 3> GetNormalListWorldSpace() const;

		void SetWorldMatrix(Matrix4x4f const& worldMatrix);

		void SetVertexList(std::array<Vector3f, 8> const& vertexList);

	private:
		std::array<Vector3f, 8> mVertexPositionList;

		Matrix4x4f mWorldMatrix;

	};

}

#endif