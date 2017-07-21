#ifndef IGRAPHICSAPIDIRECTX11DEMOSCENE_H
#define IGRAPHICSAPIDIRECTX11DEMOSCENE_H
#include "IGraphicsAPI.h"
namespace BAME
{
	class GraphicsAPIDirectX11DemoScene :public IGraphicsAPI
	{
	public:
		GraphicsAPIDirectX11DemoScene(IWindow* window, SceneManager* sceneManager);
		~GraphicsAPIDirectX11DemoScene();
		void Shutdown() override;
		void SetDebugView(bool value) const override;
		void Init() override;
	};
}
#endif