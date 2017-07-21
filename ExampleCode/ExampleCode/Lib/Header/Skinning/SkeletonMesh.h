#ifndef SKELETONMESH_H
#define SKELETONMESH_H
#include <vector>
#include "../Geometry/BoneMesh/BoneMesh.h"
#include "Node.h"
#include <map>
#include "Bone.h"
#include <unordered_map>
#include "SkinningAnimation.h"

namespace BAME
{
	class SkeletonMesh
	{
	public:
		SkeletonMesh();
		~SkeletonMesh();

		
		void SetNodeHierarchy(Node const& node);
		BoneMesh* GetBoneMeshList();
		void SetBoneMeshList(std::vector<BoneMesh> const& boneMeshList);
		void SetGlobalInverseTransform(Matrix4x4f const& globalInverseTransform);
		void SetBoneList(std::vector<Bone> const& boneList);
		void SetBoneOrder(std::unordered_map<std::string, unsigned> const& boneOrder);
		void UpdateBones(float frameTime);
		void Init(std::vector<Bone> const& boneList, std::unordered_map<std::string, unsigned> const& boneOrder, Node const& nodeHierarchy,
			std::vector<BoneMesh> const& boneMeshList);
		void Init(std::vector<Bone> const& boneList, std::unordered_map<std::string, unsigned> const& boneOrder, Node const& nodeHierarchy,
			std::vector<BoneMesh> const& boneMeshList, std::unordered_map<std::string, SkinningAnimation>const& animationList);
		std::vector<Bone>const& GetBoneList() const;
		std::vector<Matrix4x4f> const& GetBoneMatrixList() const;
		void SetMaterial(Material* material);
		unsigned GetNumberBoneMeshes() const;
		private:

		void UpdateNodeHierarchy(Node const& node, const Matrix4x4f& ParentTransform);


		std::vector<BoneMesh> mBoneMeshList;

		std::vector<Bone> mBoneList;
		std::unordered_map<std::string, unsigned> mBoneOrder;
		Matrix4x4f mGlobalInverseTransform;
		Node mNodeHierarchy;

		std::vector<Matrix4x4f> mFinalBoneTransformMatrixList;

		float mHeadTime;
		int sign = 1;
		float mLegTime;
		int legsign=1;
		std::unordered_map<std::string, SkinningAnimation> mAnimationList;
	};
}
#endif
