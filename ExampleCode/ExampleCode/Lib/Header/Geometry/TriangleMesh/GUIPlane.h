// Dateiname:Plane.h
// Author: Patrick Benkowitsch
// Letztes Änderungsdatum: 25.08.2015 21:08
#ifndef GUIPlane_H
#define GUIPlane_H

#include "../GeoTriangle3D.h"

namespace BAME
{
	class GUIPlane : public GeoTriangle3D
	{
	public:
		GUIPlane(const float size = 1.0f);
		GUIPlane(const float width, const float height);
		~GUIPlane();
	};
}
#endif // Plane_H
