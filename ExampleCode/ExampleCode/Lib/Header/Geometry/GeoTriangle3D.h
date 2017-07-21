#ifndef GEOTRIANGLE3D_H
#define GEOTRIANGLE3D_H
#include "IGeo3D.h"
#include "Primitives/Triangle.h"

namespace BAME
{
	class GeoTriangle3D : public IGeo3D
	{
	public:
		GeoTriangle3D() : IGeo3D(Topology::TRIANGLE)
		{
		};

		~GeoTriangle3D()
		{
		};

	protected:

		Vector3f Newell(std::vector<Vector3f> vertexList);
		void CalculateNormals();
		void BuildVertexList() override;
		int FindEqualVertex(Vertex const& vertex);
		void BuildIndexList() override;
		void CalculateTangentAndBinormal();
		std::vector<Vertex> mNotIndexedVertexList;
	private:
	};
}
#endif 
