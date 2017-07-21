#ifndef SIMPLEGEO_H
#define SIMPLEGEO_H

#include "../GeoTriangle3D.h"
#include "../Primitives/Triangle.h"

namespace BAME
{
	class SimpleGeo : public GeoTriangle3D
	{
	public:
		SimpleGeo();

		SimpleGeo(std::vector<unsigned int> const& indexlist, std::vector<Vertex> const& vertexList);

		~SimpleGeo();
	};
}
#endif
