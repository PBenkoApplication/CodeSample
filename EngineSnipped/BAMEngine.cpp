
#include "BAMEngine.h"
#include "../Core/InputAPI/InputManager.h"
#include "InputAPI/DirectXInputAPI.h"
#include "InputAPI/OpenGLInputAPI.h"
#include "SceneGraph/SceneManager.h"
#include <ctime>
#include "GraphicsAPI/GraphicsAPIDirectX11.h"
#include "GraphicsAPI/GraphicsAPIOpenGL4.h"
#include "GraphicsAPI/GraphicsAPINullRenderer.h"
#include "SoundAPI/OpenAL/OpenALSoundAPI.h"
#include "GraphicsAPI/GraphicsAPIDirectX11Deferred.h"
#include "GraphicsAPI/GraphicsAPIDirectX11DemoScene.h"
#include "../ExceptionHandling/BAMELog.h"
#include "../Helper/PlattformHelper.h"


namespace BAME
{
	BAMEngine::BAMEngine()
		: mWindow(nullptr),
		mIsShutdowned(false),
		mInputManager(nullptr),
		mSceneManager(nullptr),
		mGraphicsAPI(nullptr),
		mSoundAPI(nullptr)
	{
		srand(unsigned int(time(nullptr)));
	}


	void BAMEngine::Init(const RendererType renderer_type, SOUNDAPITYPE soundAPIType, SceneManager* sceneManager, InputManager* inputManager, AudioPlayer* audioPlayer, 
		const int windowWidth, const int windowHeight, const char title[20])
	{
		writeHeader(renderer_type);
		
		mSceneManager = sceneManager;

		InitGraphicAPI(renderer_type, windowWidth, windowHeight, title);

		InitSound(soundAPIType, audioPlayer);

		InitInput(inputManager);

		BAMESUCCESS("BAMEEngine initialized successully");
	}

	BAMEngine::~BAMEngine()
	{
		Shutdown();
	}

	void BAMEngine::InitSound(SOUNDAPITYPE soundAPIType, AudioPlayer* audioPlayer)
	{
		switch (soundAPIType)
		{
		case SOUNDAPITYPE::OPENAL_API:
		{
			mSoundAPI.reset(new OpenALSoundAPI());
			break;
		}
		case SOUNDAPITYPE::XAUDIO2_API:
		{
			BAMEERROR("XAudio2 not yet implemented!");
			break;
		}
		default: break;
		}
		mSoundAPI->Init();

		audioPlayer->Init(mSoundAPI.get());
	}

	void BAMEngine::InitGraphicAPI(const RendererType renderer_type, const int windowWidth, const int windowHeight, const char* title)
	{
		switch (renderer_type)
		{
		case RendererType::DirectX11_Forward:
			mWindow.reset(new DirectXWindow());
			mGraphicsAPI.reset(new GraphicsAPIDirectX11(mWindow.get(), mSceneManager));
			mInputAPI.reset(new DirectXInputAPI());
			break;
		case RendererType::DirectX11_Deferred:
			mWindow.reset(new DirectXWindow());
			mGraphicsAPI.reset(new GraphicsAPIDirectX11Deferred(mWindow.get(), mSceneManager));
			mInputAPI.reset(new DirectXInputAPI());
			break;
		case RendererType::DirectX11_DemoScene:
			mWindow.reset(new DirectXWindow());
			mGraphicsAPI.reset(new GraphicsAPIDirectX11DemoScene(mWindow.get(), mSceneManager));
			mInputAPI.reset(new DirectXInputAPI());
			break;
		case RendererType::OpenGL4_0_Forward:
			mWindow.reset(new OpenGLWindow());
			mGraphicsAPI.reset(new GraphicsAPIOpenGL4(mWindow.get(), mSceneManager));
			mInputAPI.reset(new OpenGLInputAPI());
			break;
		case RendererType::NO_RENDERER:
			mWindow.reset(new DirectXWindow());
			mGraphicsAPI.reset(new GraphicsAPINullRenderer(mWindow.get(), mSceneManager));
			mInputAPI.reset(new DirectXInputAPI());
			break;
		default:
			break;
		}

		mWindow->CreateTheWindow(windowWidth, windowHeight, title);
		mGraphicsAPI->Init();
	}

	void BAMEngine::InitInput(InputManager* inputManager)
	{
		mInputManager = inputManager;
		mInputAPI->Init(mWindow.get());
		mInputManager->Init(mInputAPI.get(), mWindow.get());
	}

	void BAMEngine::InitWithoutWindow()
	{
		Init(RendererType::NO_RENDERER, SOUNDAPITYPE::OPENAL_API, nullptr, nullptr);
	}

	void BAMEngine::RenderScene() const
	{
		mGraphicsAPI->Render();
	}

	void BAMEngine::HandleEvents() const
	{
		mInputManager->Update();
		mWindow->HandleEvents();
	}

	void BAMEngine::Shutdown()
	{
		if (!mIsShutdowned)
		{
			BAMEINFO("Shutdown BAMEngine...");
			mGraphicsAPI->Shutdown();
			mGraphicsAPI.release();
			mSoundAPI.release();
			mWindow.release();
			BAMESUCCESS("Shutdown successful");
			mIsShutdowned = true;
		}
		else
			BAMEWARN("BAMEEngine is already shut down")
	}

	bool BAMEngine::IsCloseRequested() const
	{
		return mWindow->IsCloseRequested();
	}

	void BAMEngine::SetWindowTitle(std::string const& title) const
	{
		mWindow->SetTitle(title);
	}

	void BAMEngine::writeHeader(RendererType rendererType) const
	{
#if defined(_WIN32)
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		SetConsoleTextAttribute(hConsole, 10);
#endif
		std::cout << std::endl << std::endl <<
			"  //////////////////////////////////////////////////////////////////////////////            ##########" << std::endl <<
			"///                                                                          ///         ####        ####" << std::endl <<
			"///                                                                          ///       ###  ###    ###  ###" << std::endl <<
			"///   #####    #    ##     ## ###### ###  ###   ####  ### ###  ### ######   ///       ##   #   #  #   #   ## " << std::endl <<
			"///   #   #    #     ##   ##   #   #  ##   #   #   #   #   ##   #   #   #    ///     #      ###    ###      #" << std::endl <<
			"///   #   #   # #    ##   ##   # # #  # #  #  #        #   # #  #   # # #    ///    #            #           #" << std::endl <<
			"///   ####    # #    # # # #   ###    # #  #  #        #   # #  #   ###      ///    #         #    #         #" << std::endl <<
			"///   #   #  #   #   # # # #   # #    #  # #  #   ###  #   #  # #   # #      ///     ##        #     #     ##" << std::endl <<
			"///   #   #  #####   # # # #   #   #  #  # #  #    #   #   #  # #   #   #    ///      ###        # ##    ###" << std::endl <<
			"///   #   #  #   #   #  #  #   #   #  #   ##   #   #   #   #   ##   #   #    ///       ####           ####" << std::endl <<
			"///   ##### ### ### ### # ### ###### ###  ##    ###   ### ###  ##  ######   ///            ###########" << std::endl <<
			"///                                                                          ///             ##   ##" << std::endl <<
			"///                                                                          ///            ##     ##" << std::endl <<
			"///                                                                          ///            ##     ##" << std::endl <<
			"  ////////////////////////////////////////////////////////////////////////////           ######   ######" << std::endl << std::endl;


#if defined(_WIN32)
		SetConsoleTextAttribute(hConsole, 7);
#endif
		BAMEINFO("Running on " + PlattformHelper::GetPlattformInformation());
		BAMEINFO("Initialize BAMEEngine...");
		BAMEINFO(GetRendererAsString(rendererType))
	}

	void BAMEngine::Update(float frameTime)
	{
		mGraphicsAPI->Update(frameTime);
	}
}
