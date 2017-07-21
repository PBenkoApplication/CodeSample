#ifndef WRITECHAR_H
#define WRITECHAR_H
#include "../Mathematics/Vector2f.h"
#include "IGUIObject.h"
#include "../Geometry/TriangleMesh/GUIPlane.h"

namespace BAME
{
	class WriteChar : public IGUIObject
	{
	public:
		WriteChar(float width, float height, std::string const& normalPfad);
		~WriteChar();

		bool CheckHover(const float fPosX, const float fPosY) override;
		void OnMouseOver() override;
		void OnMouseOut() override;
		void OnMouseClickLeft() override;
		void OnMouseClickRight() override;


		float GetWidth() const;
		float GetHeight() const;
		void setPosition(Vector3f vec);
		Vector2f GetPosition() const;

	private:
		GUIPlane mGUIPlane;
		float mWidth;
		float mHeight;
	};
}

#endif
