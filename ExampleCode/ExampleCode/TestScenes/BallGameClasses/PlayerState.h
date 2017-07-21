#pragma once
#include <Mathematics/Vector2f.h>
#include "Box.h"

namespace BAME {
	class Vector3f;

	class PlayerState
	{
	public:
		PlayerState()= default;
		virtual ~PlayerState()=default;

		virtual void Move(Vector2f const& direction, Box& player)=0;

	};
}
