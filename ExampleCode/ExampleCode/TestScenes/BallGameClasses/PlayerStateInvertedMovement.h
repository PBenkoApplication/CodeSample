#pragma once
#include "PlayerState.h"
#include <Mathematics/Vector2f.h>
#include "Box.h"

namespace BAME
{
	class PlayerStateInvertedMovement : public PlayerState
	{
	public:
		PlayerStateInvertedMovement();
		~PlayerStateInvertedMovement();
		void Move(Vector2f const& direction, Box& player) override;
	};
}
