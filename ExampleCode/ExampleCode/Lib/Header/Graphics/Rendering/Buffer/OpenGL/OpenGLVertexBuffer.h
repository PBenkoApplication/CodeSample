#ifndef OPENGLVERTEXBUFFER_H
#define OPENGLVERTEXBUFFER_H
#include "../IVertexBuffer.h"

#include "../../../Geometry/Vertex.h"
#include <vector>

#include <GL/glew.h>

namespace BAME
{
	class OpenGLVertexBuffer: public IVertexBuffer
	{
	public:
		OpenGLVertexBuffer(std::vector<Vertex> const& vertexList);
		~OpenGLVertexBuffer();

		GLuint GetBuffer() const;
		void Update(std::vector<Vertex> const& vertexList) override;
	private:
		GLuint mVertexBuffer;
	};
}
#endif
