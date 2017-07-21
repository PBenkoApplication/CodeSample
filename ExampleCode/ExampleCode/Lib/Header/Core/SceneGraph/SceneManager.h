#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H
#include "Scene/Scene.h"
#include "Camera.h"
#include <unordered_map>
#include "../../Graphics/Rendering/Renderer/RenderObject.h"
#include "../../Graphics/Rendering/Renderer/RenderObjectFactory/RenderObjectFactory.h"
#include "../../Physics/BoundingVolumes/AABB.h"


namespace BAME
{
	class SceneManager
	{
	public:
		SceneManager();
		void CleanUpRenderObjectLists();
		~SceneManager();

		Scene* GetActiveScene();

		void SetActiveScene(std::string const& name);

		void SetActiveCamera(Camera* camera);

		Camera* GetActiveCamera() const;

		void Init(RendererType renderertype, ITextureFactory* textureFactory);

		Scene* CreateScene(std::string const& name);
		void UpdateRenderObjectWorldMatrix(RenderObject* renderObj) const;
		void Update(float deltaTime);
		void CreateChildRenderObjects(Placement* parentPlacement);
		void LoadScene(Scene* scene);
		void CreateRenderObjectHierarchy(Scene* scene);

		std::vector<RenderObject*> const& GetLineObjectList() const;
		std::vector<RenderObject*> const& GetTriangleObjectList() const;
		std::vector<RenderObject*> const& GetPointObjectList() const;
		std::vector<RenderObject*> const& GetGUIObjectList() const;
		std::vector<RenderObject*> const& GetDebugObjectList() const;
		std::vector<std::vector<RenderObject*>> const& GetBoneObjectList() const;
		std::vector<SkeletonMesh*> const& GetSkeletonMeshList() const; ;

		RenderObject* GetSkyboxObject() const;
		void CreateAABB(IGeo3D* geo, Placement* placement);


	private:

		void CreateRenderObject(Placement* placement);
		std::list<AABB> mAABBList;
		std::vector<IGeo3D*> mAABBGeo;
		Material* mMatAABB;
		std::unordered_map<std::string, Scene*> mSceneList;
		std::string mActiveScene;
		Camera* mCamera;
		RendererType mRendererType;
		std::vector<RenderObject*> mTriangleObjectList;
		std::vector<RenderObject*> mLineObjectList;
		std::vector<RenderObject*> mPointObjectList;
		std::vector<RenderObject*> mGUIObjectList;
		std::vector<RenderObject*> mDebugObjectList;
		//std::vector<RenderObject*> mBoneObjectList;
		std::unique_ptr<RenderObject> mSkyboxObject;
		std::vector<std::vector<RenderObject*>> mBoneObjectList;
		std::vector<SkeletonMesh*> mSkeletonMeshList;

		RenderObjectFactory* mRenderObjectFactory;
	};
}
#endif
