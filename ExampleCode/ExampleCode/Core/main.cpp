#include "Game.h"
#include <Core/Timer.h>


int main(int argc, char** argv)
{
	Game game;
	game.Init();
	Timer timer;
	double elapsedTime = 0.0;
	timer.Start();
	while (game.IsRunning())
	{
		game.Update(elapsedTime);
		game.Render();
		elapsedTime = timer.ElapsedTime();
		timer.Start();
	}

	game.Dispose();

	return 0;
}
