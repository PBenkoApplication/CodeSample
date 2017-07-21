#ifndef MATERIALCOLLECTION_H
#define MATERIALCOLLECTION_H
#include "Material.h"

namespace BAME
{
	class MaterialCollection
	{
	public:
		enum class MaterialType
		{
			Emerald,
			Jade,
			Obsidian,
			Pearl,
			Ruby,
			Turquoise,
			Brass,
			Bronze,
			Chrome,
			Copper,
			Gold,
			Silver,

			PlasticBlack,
			PlasticCyan,
			PlasticGreen,
			PlasticRed,
			PlasticWhite,
			PlasticYellow,

			RubberBlack,
			RubberCyan,
			RubberGreen,
			RubberRed,
			RubberWhite,
			RubberYellow,
		};


		MaterialCollection();
		~MaterialCollection();
		static Material GetMaterial(const MaterialType matType);

		/*private:
			static std::unordered_map<MaterialType, Material*> mMaterialList;*/
	};
}
#endif
