#ifndef IBUFFERFACTORY_H
#define IBUFFERFACTORY_H
#include "IVertexBuffer.h"
#include "IIndexBuffer.h"
#include "../../../Geometry/Vertex.h"
#include <vector>
#include "../../../Geometry/VertexBone.h"

namespace BAME
{
	class IBufferFactory
	{
	public:
		IBufferFactory()
		{
		};

		virtual ~IBufferFactory()
		{
		};

		virtual IVertexBuffer* CreateVertexBuffer(std::vector<Vertex> const& vertexList) = 0;
		virtual IVertexBuffer* CreateVertexBoneBuffer(std::vector<VertexBone> const& vertexList) = 0;
		virtual IIndexBuffer* CreateIndexBuffer(std::vector<unsigned int> const& indexList) = 0;
	};
}
#endif
