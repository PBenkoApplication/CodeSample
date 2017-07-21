#ifndef POINT_H
#define POINT_H
#include "../ITopology.h"

namespace BAME
{
	class Point :public ITopology
	{
	public:
		Point(Vertex const& v1);
		~Point();
	};
}
#endif
