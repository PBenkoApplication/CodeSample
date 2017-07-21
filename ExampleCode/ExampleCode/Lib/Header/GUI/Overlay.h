#ifndef OVERLAY_H
#define OVERLAY_H
#include "../Geometry/TriangleMesh/GUIPlane.h"

namespace BAME
{
	class Overlay
	{
	public:
		Overlay();
		Overlay(const float width, const float height);
		~Overlay();
		float GetWidth() const;
		float GetHeight() const;

	private:
		GUIPlane mGUIPlane;
		float mWidth;
		float mHeight;
	};
}
#endif
