#ifndef IRENDERER_H
#define IRENDERER_H
#include "../../../Core/SceneGraph/SceneManager.h"
#include "../Buffer/BufferHandler.h"
#include "../../Shaders/ShaderHandler.h"

namespace BAME
{
	class IRenderer
	{
	public:

		explicit IRenderer(SceneManager* sceneManager, IBufferFactory* bufferFactory, ShaderHandler* shaderHandler):
			mDebugEnabled(false),
			mSceneManager(sceneManager),
			mShaderHandler(shaderHandler),
			mVertexCount(0)
		{
			BufferHandler::Get().Init(bufferFactory);
		}

		virtual ~IRenderer()
		{
			BufferHandler::Get().Destroy();
		}

		virtual bool Init() = 0;
		virtual void Shutdown() = 0;
		virtual void RenderScene() = 0;
		virtual void BeforeRenderScene() = 0;
		virtual void AfterRenderScene() = 0;
		virtual void SetDebugView(bool value) = 0;

		unsigned int GetVertexCount() const { return mVertexCount; }

	protected:
		bool mDebugEnabled;

		SceneManager* mSceneManager;
		ShaderHandler* mShaderHandler;
		unsigned int mVertexCount;
	};
}

#endif
