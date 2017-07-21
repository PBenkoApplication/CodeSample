#ifndef OPENGLTEXTUREPHONGSHADER_H
#define OPENGLTEXTUREPHONGSHADER_H


#include "OpenGLShader.h"

namespace BAME
{
	class OpenGLTexturePhongShader final : public OpenGLShader
	{
	public:
		void Init() override;
		void Update(RenderObject const& renderObj, Matrix4x4f const& viewMatrix, Matrix4x4f const& projectionMatrix, Vector3f const& camPos, ShaderData const& renderData) override;

		OpenGLTexturePhongShader();
		~OpenGLTexturePhongShader();
	};
}

#endif
