#ifndef OPENGLSHADERFACTORY_H
#define OPENGLSHADERFACTORY_H


#include "../IShaderFactory.h"

namespace BAME
{
	class OpenGLShaderFactory final : public IShaderFactory
	{
	public:

		OpenGLShaderFactory();
		~OpenGLShaderFactory();


		std::unique_ptr<IShader> CreateBasicShader() override;
		std::unique_ptr<IShader> CreateGUIShader() override;
		std::unique_ptr<IShader> CreateLightningShader() override;
		std::unique_ptr<IShader> CreateSkydomeShader() override;
		std::unique_ptr<IShader> CreateTexturePhongShader() override;
		std::unique_ptr<IShader> CreateTextureShader() override;
		std::unique_ptr<IShader> CreateParticleShader() override;
		std::unique_ptr<IShader> CreateGeometryPassShader() override;
		std::unique_ptr<IShader> CreateLightningPassShader() override;
		std::unique_ptr<IShader> CreateSkyboxShader() override;
		std::unique_ptr<IShader> CreateShadowMapShader() override;
		std::unique_ptr<IShader> CreateLightningSkinning() override;
		std::unique_ptr<IShader> CreateDemoSceneShader() override;
	};
}

#endif
