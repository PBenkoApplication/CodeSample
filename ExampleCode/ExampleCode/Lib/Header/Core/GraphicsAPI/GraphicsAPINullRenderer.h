#ifndef GRAPHICSAPINULLRENDERER_H
#define GRAPHICSAPINULLRENDERER_H
#include "IGraphicsAPI.h"

namespace BAME
{
	class GraphicsAPINullRenderer : public IGraphicsAPI
	{
	public:
		GraphicsAPINullRenderer(IWindow* window, SceneManager* sceneManager);
		~GraphicsAPINullRenderer();
		void Shutdown() override;
		void SetDebugView(bool value) const override;
		void Init() override;
		void Render() override;
	};
}
#endif
