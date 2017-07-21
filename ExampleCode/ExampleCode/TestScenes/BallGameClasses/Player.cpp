#include "Player.h"
#include <GUI/GUIHandler.h>
#include "PlayerStateNormal.h"

namespace BAME
{

	Player::Player():
	mPlayerState(new PlayerStateNormal())
	{
	}


	Player::~Player()
	{
		delete mPlayerState;
	}




	void Player::SetState(PlayerState* playerstate)
	{
		delete mPlayerState;
		mPlayerState = playerstate;
	}

	void Player::Move(Vector2f const& direction)
	{
		mPlayerState->Move(direction, mBox);
	}
}
