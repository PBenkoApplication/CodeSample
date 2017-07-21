#pragma once
#include <Mathematics/Vector2f.h>
#include "Box.h"

namespace BAME
{
	class IGameObject
	{
	public:
		IGameObject()=default;
		virtual ~IGameObject()=default;
		
		virtual void Init(float width, float height, std::string const& texturePath, bool isVisible =false);
		virtual void Move(Vector2f const& direction);
		void SetPosition(Vector2f const& position);
		Vector2f GetPosition() const;
		Vector2f GetMiddlePosition() const;
		void SetMiddlePosition(Vector2f const& position);
		bool CheckCollision(IGameObject const& box) const;
		bool CheckCollisionSphere(IGameObject const& box, ePOSITION& info) const;

		void SetVisbility(bool isVisable);
		bool IsVisible() const;

		void manuellBind();

		Box mBox;
	};
}
