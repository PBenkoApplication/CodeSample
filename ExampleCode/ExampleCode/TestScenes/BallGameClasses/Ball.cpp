#include "Ball.h"
namespace BAME
{
	Ball::Ball()
	{
	}


	Ball::~Ball()
	{
	}

	void Ball::SetDirection(Vector2f const& direction)
	{
		mDirection = direction;
	}

	void Ball::SetSpeed(float speed)
	{
		mBallSpeed = speed;
	}
}
