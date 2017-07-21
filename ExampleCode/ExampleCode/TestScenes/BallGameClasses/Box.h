#ifndef BOX_H
#define BOX_H
#include "GUI/Button.h"
#include "BoundingBox.h"

namespace BAME
{
enum class ePOSITION
		{
			LEFT,
			RIGHT,
			TOP,
			BOTTOM
		};
	class Box
	{
	public:
		

		Box();
		void Init(float width, float height, std::string const& texturePath);
		~Box();
		void Translate(Vector2f const& translation);
		void SetMiddlePosition(Vector2f const& position);
		void SetPosition(Vector2f const& position);
		bool CheckCollision(Box const& box) const;
		bool CheckCollisionSphere(Box const& box, ePOSITION& info) const;
		Button* GetButton();
		Vector2f GetMiddlePos() const;
		Vector2f GetPosition() const;

		void SwitchOn();
		void SwitchOff();
		bool IsVisible() const;

	private:
		Button mGeo;
		Vector3f mPosition;
		float mHalfSizeX;
		float mHalfSizeY;

	};
}
#endif
