//#ifndef PLACEMENT_H
//#define PLACEMENT_H
//#include "../../Mathematics/Matrix4x4f.h"
//#include <vector>
//#include "SceneNode.h"
//#include <list>
//#include "../../Geometry/BoneMesh/BoneMesh.h"
//
//namespace BAME
//{
//	class SkeletonMesh;
//	//RotateItself und ScaleItself werden rausgeschmissen
//	//Stattdessen kann ein zusätzliches Placement an ein Placement gehängt werden
//	//Indem Speziellen fall von RotateItself gelte dann	
//	//Der Elternknoten enthält die Translation
//	//Der Kindknoten die Rotation
//
//	//Um die WorldMatrix zu bestimmen wird ausgehend vom Placement an dem das geo hängt 
//	//bis zum Elternknoten traversiert und die WorldMatrizen aufmultipliziert.
//	class IGeo3D;
//
//	class Placement final
//	{
//	public:
//
//		Placement();
//		~Placement();
//
//		void AddGeo(IGeo3D* geo);
//		//void AddGeo(BoneMesh* geo);
//		void AddGeo(SkeletonMesh* skeletonMesh);
//		void AddPlacement(Placement* placement);
//		void SubPlacement(Placement* placement);
//		Matrix4x4f const& GetWorldMatrix() const;
//		void SetWorldMatrix(Matrix4x4f const& worldMatrix);
//		std::vector<IGeo3D *> const& GetGeoList() const;
//		std::vector<SkeletonMesh*> const& GetSkeletonMeshList() const;
//
//		void Translate(Vector3f const& vec);
//
//		void Rotate(const float angle, const Vector3f& axis);
//		void Scale(Vector3f const& vec);
//		void ResetTransformation();
//
//		Placement* Search(Placement* node);
//		Placement* Search(long key);
//		long GetKey() const;
//		Placement* GetParentNode() const;
//
//		std::map<long, Placement*> const& GetChildNodeList() const;
//	protected:
//		Placement* mParentNode;
//		std::map<long, Placement*> mChildNodeList;
//		long mKey;
//		long mNextChildKey;
//		std::list<long> mFreedKeyList;
//
//	private:
//		std::vector<IGeo3D*> mGeoList;
//		//std::vector<BoneMesh*> mGeoBoneList;
//		std::vector<SkeletonMesh*> mSkeletonMeshList;
//		Matrix4x4f mWorldMatrix;
//	};
//}
//
//#endif
