#ifndef OPENGLBUFFERFACTORY_H
#define OPENGLBUFFERFACTORY_H
#include "../IBufferFactory.h"

namespace BAME
{
	class OpenGLBufferFactory : public IBufferFactory
	{
	public:

		OpenGLBufferFactory();
		~OpenGLBufferFactory();

		IVertexBuffer* CreateVertexBuffer(std::vector<Vertex> const& vertexList) override;
		IIndexBuffer* CreateIndexBuffer(std::vector<unsigned int> const& indexList) override;
		IVertexBuffer* CreateVertexBoneBuffer(std::vector<VertexBone> const& vertexList) override;
	};
}
#endif
