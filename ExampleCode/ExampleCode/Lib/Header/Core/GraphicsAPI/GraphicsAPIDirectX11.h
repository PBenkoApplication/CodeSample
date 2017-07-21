#ifndef GRAPHICSAPIDIRECTX11_H
#define GRAPHICSAPIDIRECTX11_H
#include "IGraphicsAPI.h"

namespace BAME
{
	class GraphicsAPIDirectX11 :public IGraphicsAPI
	{
	public:
		GraphicsAPIDirectX11(IWindow* window, SceneManager* sceneManager);
		~GraphicsAPIDirectX11();
		void Shutdown() override;
		void SetDebugView(bool value) const override;
		void Init() override;
	};
}
#endif
