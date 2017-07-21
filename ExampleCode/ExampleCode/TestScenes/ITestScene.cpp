#include "ITestScene.h"

namespace BAME
{
	ITestScene::ITestScene(SceneManager& sceneManager, InputManager& inputManager, AudioPlayer& audioPlayer) :
		mSceneManager(sceneManager),
		mInputManager(inputManager),
		mAudioPlayer(audioPlayer)
	{
	}


	ITestScene::~ITestScene()
	{
	}
}
