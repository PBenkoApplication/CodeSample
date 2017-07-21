#include "Game.h"
#include <Core/Timer.h>
#include <Core/SceneGraph/SceneManager.h>
#include "ExceptionHandling/BAMELog.h"
#include "ObjectLoader/Assimp/AssimpObjectLoader.h"

using namespace std;

Game::Game(): mIsRunning(false)
{
}


Game::~Game()
{
}

void Game::Init()
{
	mGameTitle = "BAMEngine DevGame";
	Timer initTimer;
	initTimer.Start();
	mBAMEngine.Init(RendererType::DirectX11_Forward, SOUNDAPITYPE::OPENAL_API, &mSceneManager, &mInputManager, &mAudioPlayer, 1280, 720, mGameTitle.c_str());

	mTestSceneHandler = std::make_unique<TestSceneHandler>();

	mTestSceneHandler->Init(mSceneManager, mInputManager, mAudioPlayer);
	
	mTestSceneHandler->SetActiveScene(TestSceneEnum::SCENE_3D);

	BAMESUCCESS(string("Time for Init: ") + std::to_string(initTimer.ElapsedTime()) + string(" seconds"));


	mIsRunning = true;
}

void Game::HandleInput()
{
	if (mInputManager.GetKey(Key::ESCAPE))
	{
		mIsRunning = false;
	}
}

void Game::Update(double frameTime)
{
	mBAMEngine.HandleEvents();
	if (mBAMEngine.IsCloseRequested())
	{
		mIsRunning = false;
		return;
	}
	UpdateWindowTitle(frameTime);

	mTestSceneHandler->Update(frameTime);

	
	HandleInput();

	mBAMEngine.Update(frameTime);
}

bool Game::IsRunning() const
{
	return mIsRunning;
}

void Game::Render() const
{
	mBAMEngine.RenderScene();
}

void Game::Dispose()
{
	mTestSceneHandler->Dispose();
	mBAMEngine.Shutdown();
}

void Game::UpdateWindowTitle(double frameTime)
{
	mFrameTimeAmount += frameTime;

	if (mFrameTimeAmount > 1)
	{
		mBAMEngine.SetWindowTitle(mGameTitle + " FPS: " + std::to_string(int(1 / (frameTime))));
		mFrameTimeAmount = 0.0;
	}
}
