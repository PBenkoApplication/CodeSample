// Dateiname:Plane.h
// Author: Patrick Benkowitsch
// Letztes Änderungsdatum: 25.08.2015 21:08
#ifndef Plane_H
#define Plane_H


#include "../GeoTriangle3D.h"

namespace BAME
{
	class Plane : public GeoTriangle3D
	{
	public:
		Plane(const float size = 1.0f);
		Plane(const float width, const float depth);
		Plane(const float width, const float depth, const int tiledWidth, const int tiledHeight);
		~Plane();
	};
}
#endif // Plane_H
