#ifndef WAVEFRONTOBJECT_H
#define WAVEFRONTOBJECT_H

#include "../GeoTriangle3D.h"
#include "SimpleGeo.h"

namespace BAME
{
	class WavefrontObject : public GeoTriangle3D
	{
	public:
		WavefrontObject()
		{
		};

		//WavefrontObject(std::string const& path);
		~WavefrontObject();
		void Init(std::vector<Vertex> vertexList, std::vector<unsigned int> indexList);
		void Init(std::vector<Vertex> vertexList, std::vector<unsigned> indexList, bool calculateTangentSpace);
		//std::vector<SimpleGeo> SpecialLoad(std::string const& path);
	};
}

#endif
