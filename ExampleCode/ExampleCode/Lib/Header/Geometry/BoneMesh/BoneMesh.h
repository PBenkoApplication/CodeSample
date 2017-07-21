#ifndef BONEMESH_H
#define BONEMESH_H
#include "../GeoTriangle3D.h"
//#include "../../Skinning/MeshBoneData.h"
#include "../VertexBone.h"

namespace BAME
{
	class BoneMesh :public GeoTriangle3D
	{
	public:
		BoneMesh();
		~BoneMesh();

		//void SetMeshBoneData(MeshBoneData const& meshBoneData);
		//void SetGlobalInverseTransform(Matrix4x4f const& globInvertTransf);
		//Matrix4x4f const& GetGlobalInverseTransform() const;;
		//MeshBoneData const& GetMeshBoneData() const;
		//void UpdateBones(float frametime);
		void SetVertexBoneList(std::vector<VertexBone> const& vertexBoneList);
		std::vector<VertexBone> const& GetVertexBoneList() const { return mVertexBoneList; };
		/*void SetVertexBoneList(std::vector<VertexBone> const& vertexList)
		{
			mVertexList = vertexList;
		}*/

		//void CalculateVertexBoneList();

		/*void UpdateNodeHierarchy(Node const& node, const Matrix4x4f& ParentTransform, std::map<std::string, unsigned> const& boneMapping, std::vector<Bone>& boneList);
		void SetNodeHierarchy(Node const& node)
		{
			mNodeHierarchy = node;
		}
*/
	private:
		/*MeshBoneData mMeshBoneData;
		Matrix4x4f mGlobalInverseTransform;*/
		std::vector<VertexBone> mVertexBoneList;
		//Node mNodeHierarchy;
		/*float mHeadTime;
		int sign = 1;
		float mLegTime;
		int legsign=1;*/
	};
}

#endif
