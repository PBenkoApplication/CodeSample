#ifndef THREADEDOBJECTLOADER_H
#define THREADEDOBJECTLOADER_H
#include <unordered_map>
#include "ppl.h"
#include "../Geometry/TriangleMesh/WavefrontObject.h"
#include "ObjectLoader.h"

namespace BAME
{
	class ThreadedObjectLoader
	{
	public:
		ThreadedObjectLoader();
		~ThreadedObjectLoader();

		static void AddToLoadList(std::string const& source, std::vector<WavefrontObject>& dest);

		static bool LoadAllObjects();

	private:
		static std::unordered_map<std::string, std::vector<WavefrontObject>&> mWorkList;
	};
}

#endif
