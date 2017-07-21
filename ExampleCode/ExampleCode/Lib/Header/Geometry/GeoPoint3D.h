#ifndef IGEOPOINTS3D_H
#define IGEOPOINTS3D_H
#include "IGeo3D.h"

namespace BAME
{
	class GeoPoint3D : public IGeo3D
	{
	public:
		GeoPoint3D();
		~GeoPoint3D();
		void BuildVertexList() override;
		void BuildIndexList() override;
	};
}
#endif
