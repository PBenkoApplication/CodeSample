#ifndef TERRAIN_H
#define TERRAIN_H
#include "../GeoTriangle3D.h"
#include "../../Mathematics/PerlinNoise.h"

namespace BAME
{
	class Terrain : public GeoTriangle3D
	{
	public:
		Terrain();
		Terrain(const float startX, const float startZ, const float width, const float depth, PerlinNoise perlinNoise);


		~Terrain();

		float GetWidth() const
		{
			return mWidth;
		};

		float GetDepth() const
		{
			return mDepth;
		};

	private:


		float mWidth;
		float mDepth;
	};
}
#endif
