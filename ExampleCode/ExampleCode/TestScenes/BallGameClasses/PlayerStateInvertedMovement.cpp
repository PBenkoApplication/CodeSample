#include "PlayerStateInvertedMovement.h"
#include "Box.h"

namespace BAME
{

	PlayerStateInvertedMovement::PlayerStateInvertedMovement()
	{
	}


	PlayerStateInvertedMovement::~PlayerStateInvertedMovement()
	{
	}

	void PlayerStateInvertedMovement::Move(Vector2f const& direction, Box & player)
	{
		player.Translate(-1*direction);
	}

}
