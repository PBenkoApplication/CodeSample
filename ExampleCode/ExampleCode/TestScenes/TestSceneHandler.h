#ifndef TESTSCENEHANDLER_H
#define TESTSCENEHANDLER_H
#include "ITestScene.h"
#include "TestSceneEnum.h"
#include <map>


namespace BAME
{
	class TestSceneHandler
	{
	public:

		TestSceneHandler();

		~TestSceneHandler();

		void SetActiveScene(TestSceneEnum sceneType);
		void Init(SceneManager& sceneManager, InputManager& inputManager, AudioPlayer& audioPlayer);

		void Update(double frameTime);
		void Dispose();

	private:
		std::map<TestSceneEnum, std::unique_ptr<ITestScene>> mSceneList;
		TestSceneEnum mActiveScene;
	};
}
#endif
