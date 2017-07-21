#ifndef ASSIMPOBJECTLOADER_H
#define ASSIMPOBJECTLOADER_H
#include <vector>
#include "../../Geometry/Vertex.h"
#include "../../Mathematics/Matrix4x4f.h"
#include "../../Geometry/BoneMesh/BoneMesh.h"
#include "../../Skinning/SkeletonMesh.h"
#include <unordered_map>
#include "../../Skinning/VertexBoneMapping.h"
#include "../../Skinning/SkinningAnimation.h"

struct aiAnimation;
struct aiNode;
struct aiMesh;
struct aiScene;

namespace BAME
{
	class MeshBoneData;


	class AssimpObjectLoader
	{
	
	public:
		
		static AssimpObjectLoader* GetInstance();
		//static bool LoadBoneMesh(const std::string& pFile, std::vector<BoneMesh>& boneMeshList);
		static bool LoadBoneMesh(const std::string& pFile, SkeletonMesh& skeletonMesh);
	private:
		AssimpObjectLoader();


		~AssimpObjectLoader();
		static bool LoadGeometryData(aiMesh* mesh, std::vector<Vertex>& vertexList);
		static bool LoadBones(aiMesh* mesh, unsigned numVertices, std::vector<VertexBoneMapping>& vertexBoneMapping);
		static void CalculateVertexBoneList(std::vector<Vertex> const& vertexList, std::vector<VertexBoneMapping> const& vertexBoneMapping, std::vector<VertexBone>& vertexBoneList);
		static Node CreateNodeHierachie(aiNode* aiNode);
		//static void BoneTransform(std::map<std::string, unsigned> const& boneMapping, std::vector<Bone>& boneList);
		static void UpdateNodeHierarchy(Node const& node, const Matrix4x4f& ParentTransform, std::map<std::string, unsigned> const& boneMapping, std::vector<Bone>& boneList);
		static void ReadNodeHeirarchy(aiNode* node, const Matrix4x4f& ParentTransform, std::map<std::string, unsigned> const& boneMapping, std::vector<Bone>& boneList);
		static void LoadAnimations(aiAnimation** const  aiAniList,unsigned numAnimations, std::unordered_map<std::string, SkinningAnimation>& animationList);
		static std::vector<Bone> mAllBones;
		static std::unordered_map<std::string, unsigned> mBoneNameIndexMapping;
		//	struct VertexBoneData
	//	{
	//void AddBoneData(unsigned BoneID, float Weight)
	//{
	//	for (unsigned i = 0; i < 10; i++) {
	//		if (Weights[i] == 0.0) {
	//			IDs[i] = BoneID;
	//			Weights[i] = Weight;
	//			return;
	//		}
	//	}

	//	// should never get here - more bones than we have space for
	//	assert(0);
	//}
	//		unsigned IDs[10];
	//		float Weights[10];
	//	};
//void AssimpObjectLoader::LoadBones(unsigned MeshIndex, const aiMesh* pMesh, std::vector<VertexBoneData>& Bones);
//		Matrix4x4f BoneTransform(float TimeInSeconds, std::vector<Matrix4x4f>& Transforms);
//		void UpdateNodeHierarchy(float AnimationTime, const aiNode* pNode, const Matrix4x4f& ParentTransform);
//		void CalcInterpolatedRotation(aiQuaternion& Out, float AnimationTime, const aiNodeAnim* pNodeAnim);
//		unsigned FindRotation(float AnimationTime, const aiNodeAnim* pNodeAnim);

		

		static const aiScene* mScene;
		static Matrix4x4f mGlobalInverseTransform;

		/*static std::vector<Bone> mBones;
		static std::map<unsigned, VertexBoneList> mBoneMapping;*/
		/*	struct VertexBoneData
		{
			unsigned IDs[NUM_BONES_PER_VEREX];
			float Weights[NUM_BONES_PER_VEREX];
		};
*/
		
	};
}
#endif