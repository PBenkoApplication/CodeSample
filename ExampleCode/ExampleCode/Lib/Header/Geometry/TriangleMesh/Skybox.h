#ifndef SKYBOX_H
#define SKYBOX_H
#include "../GeoTriangle3D.h"

namespace BAME
{
	class Skybox : public GeoTriangle3D
	{
	public:
		Skybox();
		explicit Skybox(float size);
		~Skybox();
	};
}
#endif
