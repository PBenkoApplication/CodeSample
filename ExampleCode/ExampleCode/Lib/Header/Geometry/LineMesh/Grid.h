#ifndef IGRID_H
#define IGRID_H
#include "../GeoLine3D.h"


namespace BAME
{
	class Grid : public GeoLine3D
	{
	public:
		explicit Grid();
		Grid(const int size);
		~Grid();
	};
}
#endif
