#ifndef ENGINE_H
#define ENGINE_H

#include "Window/IWindow.h"
#include "../Graphics/Rendering/Renderer/RendererType.h"
#include "SceneGraph/SceneManager.h"
//#include "../Input/InputManager.h"
#include "../Graphics/Shaders/ShaderHandler.h"
#include "GraphicsAPI/IGraphicsAPI.h"
#include "SoundAPI/SoundAPIType.h"
#include "../Audio/AudioPlayer.h"
#include "InputAPI/IInputAPI.h"
#include "InputAPI/InputManager.h"

namespace BAME
{
	class BAMEngine
	{
	public:
		BAMEngine();
		void InitSound(SOUNDAPITYPE soundAPIType, AudioPlayer* audioPlayer);
		void InitGraphicAPI(const RendererType renderer_type, const int windowWidth, const int windowHeight, const char* title);
		void InitInput(InputManager* inputManager);
		~BAMEngine();

		void Init(const RendererType renderer_type, SOUNDAPITYPE soundAPIType = SOUNDAPITYPE::OPENAL_API, SceneManager* sceneManager = nullptr, InputManager* inputManager = nullptr, AudioPlayer* audioPlayer = nullptr, const int windowWidth = 1280, const int windowHeight = 720, const char title[20] = "BAMEEngine");
		void InitWithoutWindow();
		void RenderScene() const;
		void HandleEvents() const;
		void Shutdown();
		bool IsCloseRequested() const;
		void SetWindowTitle(std::string const& title) const;
		void writeHeader(RendererType rendererType) const;
		void Update(float frameTime);

	private:
		std::unique_ptr<IWindow> mWindow;

		bool mIsShutdowned;
		InputManager* mInputManager;
		SceneManager* mSceneManager;

		std::unique_ptr<IGraphicsAPI> mGraphicsAPI;
		std::unique_ptr<ISoundAPI> mSoundAPI;
		std::unique_ptr<IInputAPI> mInputAPI;
	};
}
#endif ENGINE_H
