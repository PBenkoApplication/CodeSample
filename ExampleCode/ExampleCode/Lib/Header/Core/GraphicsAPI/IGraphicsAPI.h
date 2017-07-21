#ifndef GRAPHICSAPI_H
#define GRAPHICSAPI_H
#include "../Window/IWindow.h"
#include "../../Graphics/Rendering/Renderer/IRenderer.h"

namespace BAME
{
	class IGraphicsAPI
	{
	public:
		IGraphicsAPI(IWindow* window, SceneManager* sceneManager);
		virtual ~IGraphicsAPI();
		virtual void Shutdown() =0;
		virtual void SetDebugView(bool value) const =0;
		virtual void Init() =0;
		virtual void Render();
		void Update(float frameTime);
	protected:
		std::unique_ptr<IRenderer> mRenderer;
		SceneManager* mSceneManager;
		std::unique_ptr<ShaderHandler> mShaderHandler;
		IWindow* mWindow;
	};
}
#endif
