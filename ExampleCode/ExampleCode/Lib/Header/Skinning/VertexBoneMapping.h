#ifndef VERTEXBONEMAPPING_H
#define VERTEXBONEMAPPING_H
#include <array>

namespace BAME
{
#define MAX_BONES 4
	class VertexBoneMapping
	{
	public:
		VertexBoneMapping();
		~VertexBoneMapping();

		void AddBone(unsigned BoneIndex, float Weight);

		std::array<unsigned, MAX_BONES> const& GetBoneIds() const
		{
			return mBoneIndex;
		}

		std::array<float, MAX_BONES> const& GetBoneWeights() const
		{
			return mWeights;
		}

		
		std::array<unsigned, MAX_BONES> mBoneIndex;
		std::array<float, MAX_BONES> mWeights;

		int mNextIndex = 0;
	};
}
#endif


