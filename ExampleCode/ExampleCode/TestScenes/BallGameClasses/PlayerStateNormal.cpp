#include "PlayerStateNormal.h"


namespace BAME
{
	PlayerStateNormal::PlayerStateNormal()
	{
	}


	PlayerStateNormal::~PlayerStateNormal()
	{
	}

	void PlayerStateNormal::Move(Vector2f const& direction, Box& player)
	{
		player.Translate(direction);
	}
}