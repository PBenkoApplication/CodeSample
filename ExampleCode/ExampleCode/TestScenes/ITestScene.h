#ifndef ITESTSCENE_H
#define ITESTSCENE_H
#include "Core/InputAPI/InputManager.h"
#include "Audio/AudioPlayer.h"
#include "Core/SceneGraph/SceneManager.h"

namespace BAME
{
	class ITestScene
	{
	public:
		ITestScene(SceneManager& sceneManager, InputManager& inputManager, AudioPlayer& audioPlayer);
		virtual ~ITestScene();

		virtual void Init() = 0;

		virtual void Update(double frameTime) = 0;
		virtual void Render() = 0;
		virtual void Dispose() = 0;

	protected:

		SceneManager& mSceneManager;
		InputManager& mInputManager;
		AudioPlayer& mAudioPlayer;
	};
}
#endif
