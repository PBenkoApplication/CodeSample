#ifndef SCENE_H
#define SCENE_H
#include "../Placement.h"
#include "../../../Graphics/Lighting/SpotLight.h"
#include "../../../Graphics/Lighting/DirectLight.h"
#include "../../../Graphics/Lighting/PointLight.h"
#include "../../../Geometry/TriangleMesh/Skybox.h"


namespace BAME
{
	class IParticleSystem;

	class Scene
	{
	public:

		void Add(Placement* place);

		Scene();
		~Scene();


		void Add(DirectLight* directLight);
		void Add(PointLight* pointLight);
		void Add(SpotLight* spotLight);
		std::vector<Placement*> const& GetPlacementList() const;
		std::vector<DirectLight*> const& GetDirectLightList() const;
		std::vector<PointLight*> const& GetPointLightList() const;
		std::vector<SpotLight*> const& GetSpotLightList() const;

		void SetSkybox(Skybox* skybox, std::string const& texturePath, bool isSRGB = false);

		void AddParticleSystem(IParticleSystem* particleSystem);

		bool IsLoaded() const;
		void MakeLoaded();

		Skybox* GetSkybox() const;
		std::string const& GetSkyboxPath() const;
		bool IsSkyboxsRGB() const;

		bool HasSkybox() const;

		bool AreBoundingBoxesShown() const;

		void ShowBoundingBoxes(bool showBoundingBoxes)
		{
			mShowBoundingBoxes = showBoundingBoxes;
		};

		void Update(float frameTime);

		std::vector<IParticleSystem*> const& GetParticleSystemList() const;

		bool IsShadowRenderingEnabled() const;

		void SetShadowRendering(bool enabled);
		void TraverseChilds(Placement* parent, Matrix4x4f const& parentMatrix) const;;

		

	protected:
		std::vector<Placement*> mPlacementList;

		Skybox* mGeoSkybox;

		std::vector<DirectLight*> mDirectLightList;
		std::vector<PointLight*> mPointLightList;
		std::vector<SpotLight*> mSpotLightList;

		std::vector<IParticleSystem*> mParticleSystemList;

		bool mIsLoaded;
		bool mUseSkybox;
		std::string mSkyboxTexPath;
		bool mIsSkyboxsRGB;

		bool mShowBoundingBoxes;

		bool mIsShadowRenderingEnabled;

	private:
		void TraversePlacements();
	};
}
#endif
