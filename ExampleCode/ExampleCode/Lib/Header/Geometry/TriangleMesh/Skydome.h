#ifndef SKYDOME_H
#define SKYDOME_H
#include "Sphere.h"

namespace BAME
{
	class Skydome : public Sphere
	{
	public:
		Skydome();
		~Skydome();

	private:
		ColorRGB mApexColor, mCenterColor;
	};
}
#endif
