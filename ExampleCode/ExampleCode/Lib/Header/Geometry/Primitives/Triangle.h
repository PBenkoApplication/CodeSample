#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "../ITopology.h"


namespace BAME
{
	class Triangle : public ITopology
	{
	public:
		Triangle(Vertex const& v1, Vertex const& v2, Vertex const& v3) :
			ITopology({v1,v2,v3})
		{
		};

		~Triangle()
		{
		};

	private:
	};
}
#endif
