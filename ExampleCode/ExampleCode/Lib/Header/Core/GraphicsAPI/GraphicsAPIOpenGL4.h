#ifndef GRAPHICSAPIOPENGL_H
#define GRAPHICSAPIOPENGL_H
#include "IGraphicsAPI.h"

namespace BAME
{
	class GraphicsAPIOpenGL4 : public IGraphicsAPI
	{
	public:
		GraphicsAPIOpenGL4(IWindow* window, SceneManager* sceneManager);
		~GraphicsAPIOpenGL4();
		void Shutdown() override;
		void SetDebugView(bool value) const override;
		void Init() override;
	};
}
#endif
