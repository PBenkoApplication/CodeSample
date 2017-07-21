#ifndef OPENGLINDEXBUFFER_H
#define OPENGLINDEXBUFFER_H
#include "../IIndexBuffer.h"
#include <vector>
#include <GL/glew.h>

namespace BAME
{
	class OpenGLIndexBuffer : public IIndexBuffer
	{
	public:

		OpenGLIndexBuffer(std::vector<unsigned int> const& indexList);
		~OpenGLIndexBuffer();

		GLuint GetBuffer() const;
		void Update(std::vector<unsigned> const& indexList) override;

	private:
		GLuint mIndexBuffer;
	};
}
#endif
