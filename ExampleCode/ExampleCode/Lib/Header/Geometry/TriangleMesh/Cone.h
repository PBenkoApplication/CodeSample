#ifndef CONE_H
#define CONE_H
#include "..\GeoTriangle3D.h"
namespace BAME
{
	class Cone : public GeoTriangle3D
	{
	public:
		explicit Cone();
		Cone(float radius, float length, int subdivisions);
		~Cone();
	};
}
#endif // CONE_H


