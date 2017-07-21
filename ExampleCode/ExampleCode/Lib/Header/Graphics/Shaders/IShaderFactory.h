#ifndef ISHADERFACTORY_H
#define ISHADERFACTORY_H
#include "IShader.h"

namespace BAME
{
	class IShaderFactory
	{
	public:
		IShaderFactory();
		virtual ~IShaderFactory();

		virtual std::unique_ptr<IShader> CreateBasicShader() =0;
		virtual std::unique_ptr<IShader> CreateGUIShader() =0;
		virtual std::unique_ptr<IShader> CreateLightningShader() =0;
		virtual std::unique_ptr<IShader> CreateSkydomeShader() =0;
		virtual std::unique_ptr<IShader> CreateTexturePhongShader() =0;
		virtual std::unique_ptr<IShader> CreateTextureShader() =0;
		virtual std::unique_ptr<IShader> CreateParticleShader() = 0;
		virtual std::unique_ptr<IShader> CreateSkyboxShader() = 0;
		virtual std::unique_ptr<IShader> CreateGeometryPassShader() = 0;
		virtual std::unique_ptr<IShader> CreateLightningPassShader() = 0;
		virtual std::unique_ptr<IShader> CreateShadowMapShader() = 0;
		virtual std::unique_ptr<IShader> CreateLightningSkinning()=0;
		virtual std::unique_ptr<IShader> CreateDemoSceneShader() = 0;
	};
}
#endif
