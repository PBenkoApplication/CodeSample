#pragma once
#include "PlayerState.h"
#include "Box.h"
#include "IGameObject.h"

namespace BAME
{
	class Player : public IGameObject
	{
	public:
		Player();
		~Player();

		void SetState(PlayerState* playerstate);

		void Move(Vector2f const& direction) override;
		Box mPlayerBox;
		PlayerState* mPlayerState;
	};
}
