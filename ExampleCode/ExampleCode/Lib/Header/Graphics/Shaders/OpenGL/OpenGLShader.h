#ifndef OPENGLSHADER_H
#define OPENGLSHADER_H

#include "../IShader.h"
#include <map>
#include "../../../Mathematics/Vector4f.h"
#include "../../Lighting/DirectLight.h"
#include "../../Rendering/Renderer/RenderObject.h"

namespace BAME
{
	class SpotLight;
	class PointLight;

	enum LightType
	{
		DLight = 0,
		PLight = 1,
		SLight = 2
	};

	struct Light
	{
		Vector4f Position;
		Vector4f Direction;
		Vector4f Color;
		float SpotAngle;
		float ConstantAttenuation;
		float LinearAttenuation;
		float QuadraticAttenuation;
		int LightType;
		int Enabled;
	};

	class OpenGLShader : public IShader
	{
	public:

		OpenGLShader();
		~OpenGLShader();

		virtual void Init() override;
		void Update(RenderObject const& renderObj, Matrix4x4f const& viewMatrix, Matrix4x4f const& projectionMatrix, Vector3f const& camPos, ShaderData const& renderData) override;
		void SetActive() override;
	protected:
		char* LoadShader(const char* fileName);
		void AddProgram(char* text, int type);
		void CompileShader();
		void AddUniform(std::string const& uniform);
		void SetUniformi(std::string const& uniformName, int value);
		void SetUniformf(std::string const& uniformName, float value);
		void SetUniform(std::string const& uniformName, Vector3f const& value);
		void SetUniform(std::string const& uniformName, Vector4f const& value);
		void SetUniform(std::string const& uniformName, Matrix4x4f& value);
		void SetUniform(std::string const& uniformName, Material const* value);
		void SetUniform(std::string const& uniformName, DirectLight const* value);
		void SetUniform(std::string const& uniformName, PointLight const* value);
		void SetUniform(std::string const& uniformName, SpotLight const* value);


	public:
		void Deactivate() override;
	protected:
		int mProgram;
		std::map<std::string, int> mUniformMap;

		static const int MAX_LIGHTS = 8;
	};
}

#endif
