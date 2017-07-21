//#ifndef MESHBONEDATA_H
//#define MESHBONEDATA_H
//#include "VertexBoneMapping.h"
//#include "Bone.h"
//#include <vector>
//#include <map>
//
//
//namespace BAME
//{
//	class MeshBoneData
//	{
//	public:
//		MeshBoneData();
//		~MeshBoneData();
//
//		void SetBoneList(std::vector<Bone> const& boneList);
//		void SetVertexBoneMapping(std::vector<VertexBoneMapping> const& vertexBoneMappingList);
//
//		std::vector<Bone> const& GetBoneList() const;;
//		std::vector<VertexBoneMapping> const& GetVertexBoneMapping() const;;
//
//		void SetBoneNameMapping(std::map<std::string, unsigned> map);
//		std::map<std::string, unsigned> GetBoneNameMapping() const;;
//		
//
//	private:
//		std::vector<Bone> mBoneList;
//		std::vector<VertexBoneMapping> mVertexBoneMapping;
//		std::map<std::string, unsigned> mBoneNameMapping;
//	};
//}
//#endif