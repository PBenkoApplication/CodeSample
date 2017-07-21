#include "IGameObject.h"
#include <GUI/GUIHandler.h>

namespace BAME
{
	void IGameObject::Init(float width, float height, std::string const& texturePath, bool isVisible)
	{
		mBox.Init(width, height, texturePath);
		
		GUIHandler::Get().Add(mBox.GetButton());
		SetVisbility(isVisible);
	}


	void IGameObject::Move(Vector2f const& direction)
	{
		mBox.Translate(direction);
	}

	void IGameObject::SetPosition(Vector2f const& position)
	{
		mBox.SetPosition(position);
	}

	Vector2f IGameObject::GetPosition() const
	{
		return mBox.GetPosition();
	}

	Vector2f IGameObject::GetMiddlePosition() const
	{
		return mBox.GetMiddlePos();
	}

	bool IGameObject::CheckCollision(IGameObject const& box) const
	{
		return mBox.CheckCollision(box.mBox);
	}

	bool IGameObject::CheckCollisionSphere(IGameObject const& box, ePOSITION& info) const
	{
		return mBox.CheckCollisionSphere(box.mBox, info);
	}

	void IGameObject::SetMiddlePosition(Vector2f const& position)
	{
		mBox.SetMiddlePosition(position);
	}

	void IGameObject::SetVisbility(bool isVisable)
	{
		if (isVisable)
		{
			mBox.SwitchOn();
		}
		else
		{
			mBox.SwitchOff();
		}
	}

	bool IGameObject::IsVisible() const
	{
		return mBox.IsVisible();
	}

	void IGameObject::manuellBind()
	{
		GUIHandler::Get().Add(mBox.GetButton());
	}
}
