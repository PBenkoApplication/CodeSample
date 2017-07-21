#pragma once
#include <Mathematics/Vector2f.h>
#include "Box.h"
#include "IGameObject.h"

namespace BAME {

	class Ball: public IGameObject
	{
	public:
		Ball();
		~Ball();

		void SetDirection(Vector2f const& direction);
		void SetSpeed(float speed);

		float mBallSpeedNormal = 0.6;
		float mBallSpeed;
		Vector2f mDirection;

		Box mPlayerBox;
		//PlayerState* mPlayerState;
	};
}
