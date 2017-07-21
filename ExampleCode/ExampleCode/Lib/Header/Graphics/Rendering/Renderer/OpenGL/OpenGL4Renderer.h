#ifndef OPENGL4RENDERER_H
#define OPENGL4RENDERER_H
#include "../IRenderer.h"
#include "../../../Core/Window/OpenGL/OpenGLWindow.h"
#include "../../../../Geometry/LineMesh/Grid.h"

namespace BAME
{
	class OpenGL4Renderer : public IRenderer
	{
	public:
		void BeforeRenderScene() override;
		void AfterRenderScene() override;
		explicit OpenGL4Renderer(IWindow* window, SceneManager* sceneManager, ShaderHandler* shaderHandler);

		~OpenGL4Renderer();

		bool Init() override;
		void Shutdown() override;

		void Draw(RenderObject* renderObj, int glTopology);
		void RenderScene() override;

		void SetDebugView(bool value) override;

	private:

		OpenGLWindow* mWindow;
		Placement* mGridPlace;
		Grid* mGrid;
		RenderObject* mGridRenderObj;
		IWindow* window_;
	};
}
#endif
