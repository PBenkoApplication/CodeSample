#pragma once
#include "PlayerState.h"

namespace BAME
{
	class PlayerStateNormal : public PlayerState
	{
	public:
		PlayerStateNormal();
		~PlayerStateNormal();
		void Move(Vector2f const& direction, Box& player) override;
	};
}
