#ifndef GRAPHICSAPIDIRECTX11DERERRED_H
#define GRAPHICSAPIDIRECTX11DERERRED_H
#include "IGraphicsAPI.h"

namespace BAME
{
	class GraphicsAPIDirectX11Deferred :public IGraphicsAPI
	{
	public:
		GraphicsAPIDirectX11Deferred(IWindow* window, SceneManager* sceneManager);
		~GraphicsAPIDirectX11Deferred();
		void Shutdown() override;
		void SetDebugView(bool value) const override;
		void Init() override;
	};
}
#endif
