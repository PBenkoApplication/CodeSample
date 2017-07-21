#ifndef PLACEMENT_H
#define PLACEMENT_H
#include <map>
#include <list>
#include <vector>
#include "../../Graphics/Lighting/ILight.h"
#include "../../Skinning/SkeletonMesh.h"
#include "Camera.h"

namespace BAME
{
	class IGeo3D;
	
	class Placement
	{
	public:
		Placement();
		~Placement();

		void AddCamera(Camera* cam);
		void AddLight(ILight* light);
		void AddGeo(IGeo3D* geo);
		
		void AddGeo(SkeletonMesh* skeletonMesh);
		void AddPlacement(Placement* placement);
		void SubPlacement(Placement* placement);
		Matrix4x4f const& GetWorldMatrix() const;
		void SetWorldMatrix(Matrix4x4f const& worldMatrix);
		std::vector<IGeo3D *> const& GetGeoList() const;
		std::vector<SkeletonMesh*> const& GetSkeletonMeshList() const;

		void Translate(Vector3f const& vec);

		void Rotate(const float angle, const Vector3f& axis);
		void Scale(Vector3f const& vec);
		void ResetTransformation();

		Placement* Search(Placement* node);
		Placement* Search(long key);
		long GetKey() const;
		Placement* GetParentNode() const;

		std::map<long, Placement*> const& GetChildNodeList() const;

		void SetCalculatedWorldMatrix(Matrix4x4f const& matrix);
		Matrix4x4f const& GetCalculatedWorldMatrix() const;
	protected:
		Placement* mParentNode;
		std::map<long, Placement*> mChildNodeList;
		long mKey;
		long mNextChildKey;
		std::list<long> mFreedKeyList;

	private:
		std::vector<IGeo3D*> mGeoList;
		std::vector<ILight*> mLightList;
		std::vector<Camera*> mCameraList;
		std::vector<SkeletonMesh*> mSkeletonMeshList;
		Matrix4x4f mWorldMatrix;
		Matrix4x4f mCalculatedWorldMatrix;
	};
}
#endif
