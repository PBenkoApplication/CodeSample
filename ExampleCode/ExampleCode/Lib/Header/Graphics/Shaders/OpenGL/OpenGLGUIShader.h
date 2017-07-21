#ifndef OPENGLGUISHADER_H
#define OPENGLGUISHADER_H


#include "OpenGLShader.h"

namespace BAME
{
	class OpenGLGUIShader final : public OpenGLShader
	{
	public:
		void Init() override;
		void Update(RenderObject const& renderObj, Matrix4x4f const& viewMatrix, Matrix4x4f const& projectionMatrix, Vector3f const& camPos, ShaderData const& renderData) override;

		OpenGLGUIShader();
		~OpenGLGUIShader();
	};
}

#endif
