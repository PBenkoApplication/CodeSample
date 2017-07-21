#ifndef OBJECTLOADER_H
#define OBJECTLOADER_H
#include <vector>
#include "../Mathematics/Vector3f.h"
#include "../Mathematics/Vector2f.h"
#include "../Geometry/Vertex.h"
#include "../Geometry/TriangleMesh/WavefrontObject.h"

namespace BAME
{
	class ObjectLoader
	{
	public:
		ObjectLoader();
		~ObjectLoader();


		struct Object
		{
			std::vector<Vector3f> positionList;
			std::vector<Vector3f> normalList;
			std::vector<Vector2f> textureCoordList;
			std::vector<Vertex> vertexList;
		};

		static bool LoadObject(std::string const& filePath, std::vector<WavefrontObject>& wavefrontObject);
		static bool LoadObjectFaster(std::string const& filePath, std::vector<WavefrontObject>& wavefrontObject);

	private:
		static void split(const std::string& s, char delim, std::vector<std::string>& elems);
		static std::vector<std::string> split(const std::string& s, char delim);

		struct IndexTriplet
		{
			int pos;
			int norm;
			int tex;
		};


		struct Geo
		{
			std::vector<std::vector<IndexTriplet>> faceList;
		};
	};
}
#endif
