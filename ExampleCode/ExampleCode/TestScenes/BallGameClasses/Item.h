#pragma once
#include "IGameObject.h"

namespace BAME
{
	enum class ItemType
	{
		SpeedUpBall,
		InvertPlayerMovement,
		NoCollisionBall,
		StickyBall,
		No_Item
	};

	class Item : public IGameObject
	{
	public:
		explicit Item()=default;
		~Item()=default;

		ItemType mItemType;
		ItemType GetItemType() const;
		void Init(float width, float height, ItemType itemType);

		void SetActive(Vector2f const& position);
		void Kill();

	private:
		void Init(float width, float height, std::string const& texturePath,  bool isVisible = false) override{};
	};
}
