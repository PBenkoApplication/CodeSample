#ifndef GAME_H
#define GAME_H

#include <Core/BAMEngine.h>
#include "Core/SceneGraph/IGame.h"
#include "../TestScenes/TestSceneHandler.h"


using namespace BAME;
using namespace std;

class Game: public IGame
{
public:
	Game();
	~Game();
	///Blablub
	void Init() override;
	void HandleInput();

	void Update(double frameTime) override;
	bool IsRunning() const;
	void Render() const;
	void Dispose() override;
private:
	std::unique_ptr<TestSceneHandler> mTestSceneHandler;

	std::string mGameTitle;
	BAMEngine mBAMEngine;
	bool mIsRunning;
	void UpdateWindowTitle(double frameTime);
	double mFrameTimeAmount = 0.0;
};

#endif
