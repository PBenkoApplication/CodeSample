#include "TestSceneHandler.h"
#include "ExceptionHandling/BAMELog.h"
#include "TestScene3D.h"
#include "TestSceneBallGame.h"

namespace BAME
{
	TestSceneHandler::TestSceneHandler(): mActiveScene(TestSceneEnum::NONE)
	{
	}

	TestSceneHandler::~TestSceneHandler()
	{
		mSceneList.clear();
	}

	void TestSceneHandler::SetActiveScene(TestSceneEnum sceneType)
	{
		if (mSceneList.count(sceneType) > 0)
		{
			if (mActiveScene == TestSceneEnum::NONE || mActiveScene != sceneType)
			{
				mActiveScene = sceneType;
				mSceneList[sceneType]->Init();
			}
			else
			{
				BAMEWARN("Selected Scene is already active");
			}
		}
		else
		{
			BAMEWARN("Can't select Scene. SceneList is empty");
		}
	}

	void TestSceneHandler::Init(SceneManager& sceneManager, InputManager& inputManager, AudioPlayer& audioPlayer)
	{
		mSceneList.emplace(TestSceneEnum::GAME_BREAK_OUT_2D, std::move(std::make_unique<TestSceneBallGame>(sceneManager, inputManager, audioPlayer)));
		mSceneList.emplace(TestSceneEnum::SCENE_3D, std::move(std::make_unique<TestSceneBenko>(sceneManager, inputManager, audioPlayer)));
	}

	void TestSceneHandler::Update(double frameTime)
	{
		mSceneList[mActiveScene]->Update(frameTime);
	}

	void TestSceneHandler::Dispose()
	{
		mSceneList[mActiveScene]->Dispose();
	}
}
