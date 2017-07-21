#ifndef GEOLINE3D_H
#define GEOLINE3D_H
#include "IGeo3D.h"

namespace BAME
{
	class GeoLine3D : public IGeo3D
	{
	public:
		GeoLine3D() : IGeo3D(Topology::LINE)
		{
		};

		~GeoLine3D()
		{
		};

	protected:
		void BuildVertexList() override;
		void BuildIndexList() override;
	};
}
#endif 
