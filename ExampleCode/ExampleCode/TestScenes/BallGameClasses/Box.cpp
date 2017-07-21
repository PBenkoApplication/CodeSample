#include "Box.h"

namespace BAME
{
	Box::Box():
	            mHalfSizeX(0),
	            mHalfSizeY(0)
	{
	}

	void Box::Init(float width, float height, std::string const& texturePath)
	{
		

		mGeo.Init(width, height, texturePath, texturePath);

		mHalfSizeX = width / 2;
		 mHalfSizeY = height/2;

		mPosition = Vector3f(mHalfSizeX, mHalfSizeY, 1.0f);
	}

	Box::~Box()
	{
	}

	void Box::Translate(Vector2f const& translation)
	{
		Vector2f newPosition = mGeo.GetPosition() + translation;
		SetPosition(Vector2f(newPosition.GetX(), newPosition.GetY()));
	}
	void Box::SetMiddlePosition(Vector2f const& position)
	{
		mPosition = Vector3f(position.GetX(), position.GetY(), 1);
		mGeo.SetPosition(Vector3f(position.GetX()- mHalfSizeX, position.GetY()-mHalfSizeY, 1));
	}
	void Box::SetPosition(Vector2f const& position)
	{
		mPosition = Vector3f(position.GetX() + mHalfSizeX, position.GetY() + mHalfSizeY, 1);
		mGeo.SetPosition(Vector3f(position.GetX(), position.GetY(), 1));
		
	}

	bool Box::CheckCollision(Box const& box) const
	{
		if (abs(mPosition.GetX() - box.mPosition.GetX()) < mHalfSizeX + box.mHalfSizeX)
		{
			if (abs(mPosition.GetY() - box.mPosition.GetY()) < mHalfSizeY + box.mHalfSizeY)
			{
				return true;
			}
		}

		return false;
	}

	bool Box::CheckCollisionSphere(Box const& box, ePOSITION& info) const
	{
		float minX = box.mPosition.GetX() - box.mHalfSizeX;
		float maxX = box.mPosition.GetX() + box.mHalfSizeX;

		float minY = box.mPosition.GetY() - box.mHalfSizeY;
		float maxY = box.mPosition.GetY() + box.mHalfSizeY;

		float d = .0f;

		float radius = mHalfSizeX;

		//Check X
		float e = mPosition.GetX() - minX;
		if (e < 0.f)
		{
			if (e < -radius)return false;

			d = d + e*e;
			info = ePOSITION::LEFT;
		}
		else
		{
			e = mPosition.GetX() - maxX;
			if (e>0)
			{
				if (e > radius)return false;

				d = d + e*e;
				info = ePOSITION::RIGHT;
			}

			
		}

		//Check Y
		e = mPosition.GetY() - minY;
		if (e < 0.f)
		{
			if (e < -radius)return false;

			d = d + e*e;
			info = ePOSITION::BOTTOM;
		}
		else
		{
			e = mPosition.GetY() - maxY;
			if (e>0)
			{
				if (e > radius)return false;

				d = d + e*e;
				info = ePOSITION::TOP;
			}
		}

		if (d > radius*radius)return false;

		return true;
	}

	Button* Box::GetButton()
	{
		return &mGeo;
	}

	Vector2f  Box::GetMiddlePos() const
	{
		return Vector2f(mPosition.GetX(), mPosition.GetY());
	}

	Vector2f  Box::GetPosition() const
	{
		return mGeo.GetPosition();
	}

	void Box::SwitchOn()
	{
		mGeo.SwitchOn();
	}

	void Box::SwitchOff()
	{
		mGeo.SwitchOff();
	}

	bool Box::IsVisible() const
	{
		return mGeo.IsVisible();
	}
}
