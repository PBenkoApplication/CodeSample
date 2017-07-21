#ifndef SIMPLECUBE_H
#define SIMPLECUBE_H
#include "Quad.h"

namespace BAME
{
	class Cube : public Quad
	{
	public:

		Cube(const float size = 1.0f);
		~Cube();
	};
}
#endif
