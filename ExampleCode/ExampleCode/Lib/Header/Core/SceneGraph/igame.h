#ifndef IGAME_H
#define IGAME_H
#include "Core/SceneGraph/SceneManager.h"
#include "Core/InputAPI/InputManager.h"

namespace BAME
{
	class IGame
	{
	public:
		IGame()
		{
		}

		virtual ~IGame()
		{
		}

		virtual void Init() =0;
		virtual void Update(double frameTime) =0;
		virtual void Dispose() =0;
	protected:
		SceneManager mSceneManager;
		InputManager mInputManager;
		AudioPlayer mAudioPlayer;
	};
}
#endif
