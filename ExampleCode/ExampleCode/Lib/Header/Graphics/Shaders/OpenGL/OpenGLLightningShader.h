#ifndef OPENGLLIGHTNINGSHADER_H
#define OPENGLLIGHTNINGSHADER_H


#include "OpenGLShader.h"
#include "../../Lighting/DirectLight.h"

namespace BAME
{
	class OpenGLLightningShader final : public OpenGLShader
	{
	public:
		void Init() override;
		void Update(RenderObject const& renderObj, Matrix4x4f const& viewMatrix, Matrix4x4f const& projectionMatrix, Vector3f const& camPos, ShaderData const& renderData) override;

		OpenGLLightningShader();
		~OpenGLLightningShader();
	};
}
#endif
