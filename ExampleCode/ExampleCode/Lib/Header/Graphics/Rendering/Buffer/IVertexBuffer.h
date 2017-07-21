#ifndef IVERTEXBUFFER_H
#define IVERTEXBUFFER_H
#include "IBuffer.h"
#include "../../../Geometry/Vertex.h"
#include <vector>

namespace BAME
{
	class IVertexBuffer: public IBuffer
	{
	public:
		IVertexBuffer()
		{
		};

		~IVertexBuffer()
		{
		};

		virtual void Update(std::vector<Vertex> const& vertexList) =0;
	};
}
#endif
