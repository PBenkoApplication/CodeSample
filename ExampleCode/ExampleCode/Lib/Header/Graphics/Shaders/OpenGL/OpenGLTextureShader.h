#ifndef OPENGLTEXTURESHADER_H
#define OPENGLTEXTURESHADER_H
#include "OpenGLShader.h"

namespace BAME
{
	class Matrix4x4f;


	class OpenGLTextureShader final : public OpenGLShader
	{
	public:
		void Init() override;
		void Update(RenderObject const& renderObj, Matrix4x4f const& viewMatrix, Matrix4x4f const& projectionMatrix, Vector3f const& camPos, ShaderData const& renderData) override;

		OpenGLTextureShader();
		~OpenGLTextureShader();
	};
}

#endif
