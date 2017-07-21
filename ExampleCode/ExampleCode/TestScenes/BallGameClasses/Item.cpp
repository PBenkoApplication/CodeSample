#include "Item.h"
#include <Core/GraphicsAPI/IGraphicsAPI.h>

namespace BAME
{


	ItemType Item::GetItemType() const
	{
		return mItemType;
	}

	void Item::Init(float width, float height, ItemType itemType)
	{
		std::string texturePath = "";

		switch (itemType)
		{
		case ItemType::SpeedUpBall:
			texturePath = "Resources/PowerUpSpeed.png";
			break;
		case ItemType::InvertPlayerMovement:
			texturePath = "Resources/PowerInvertPlayerMovement.png";
			break;
		case ItemType::NoCollisionBall:
			texturePath = "Resources/PowerUp.png";
			break;
		case ItemType::StickyBall:
			texturePath = "Resources/PowerUpSticky.png";
			break;
		default: ;

		}

		mItemType = itemType;

		IGameObject::Init(width, height, texturePath);
		SetVisbility(false);
	}

	void Item::SetActive(Vector2f const& position)
	{
		SetPosition(position);
		SetVisbility(true);
	}

	void Item::Kill()
	{
		SetVisbility(false);
	}
}
