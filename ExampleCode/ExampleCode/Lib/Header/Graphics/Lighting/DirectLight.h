#ifndef DIRECTLIGHT_H
#define DIRECTLIGHT_H
#include "ILight.h"
#include "../../Mathematics/Vector3f.h"

namespace BAME
{
	class DirectLight : public ILight
	{
	public:
		DirectLight();
		~DirectLight();
		void Init(Vector3f const& direction);
		Vector3f const& GetDirection() const;

	private:
		Vector3f mDirection;
	};
}

#endif
