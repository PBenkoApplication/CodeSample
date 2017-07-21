#ifndef SHADERDATA_H
#define SHADERDATA_H
#include <vector>
#include "../Lighting/DirectLight.h"
#include "../Lighting/PointLight.h"
#include "../Lighting/SpotLight.h"

namespace BAME
{
	class ShaderData
	{
	public:
		ShaderData();
		~ShaderData();

		void SetDirectLightList(std::vector<DirectLight*> const& directLightList);
		void SetPointLightList(std::vector<PointLight*> const& pointLightList);
		void SetSpotLightList(std::vector<SpotLight*> const& spotLightList);


		std::vector<DirectLight*> const& GetDirectLightList() const;
		std::vector<PointLight*> const& GetPointLightList() const;
		std::vector<SpotLight*> const& GetSpotLightList() const;

	private:
		std::vector<DirectLight*> mDirectLightList;
		std::vector<PointLight*> mPointLightList;
		std::vector<SpotLight*> mSpotLightList;
	};
}
#endif
