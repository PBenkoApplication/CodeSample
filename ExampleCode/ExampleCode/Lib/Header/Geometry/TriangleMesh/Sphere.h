// Dateiname:Sphere.h
// Author: Patrick Benkowitsch
// Letztes Änderungsdatum: 15.08.2015 16:57
#ifndef Sphere_H
#define Sphere_H

#include "../GeoTriangle3D.h"

namespace BAME
{
	class Sphere : public GeoTriangle3D
	{
	public:
		Sphere(const float size = 1.0f, const unsigned int player = 25, const unsigned int pheight = 25);

		~Sphere();
	};
}
#endif
