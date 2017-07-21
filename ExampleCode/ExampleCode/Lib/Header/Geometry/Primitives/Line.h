#ifndef LINE_H
#define LINE_H
#include "../ITopology.h"

namespace BAME
{
	class Line : public ITopology
	{
	public:
		Line(Vertex const& v1, Vertex const& v2);
		~Line();
	};
}
#endif
