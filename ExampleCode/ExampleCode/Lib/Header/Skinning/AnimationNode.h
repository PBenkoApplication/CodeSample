#ifndef ANIMATIONNODE_H
#define ANIMATIONNODE_H
#include <vector>
#include "../Mathematics/Quaternion.h"

namespace BAME
{
	class AnimationNode
	{
	public:
		struct RotationKey
		{
			Quaternion mValue;
			float mTime;
		};
		struct ScalingKey
		{
			Vector3f mValue;
			float mTime;
		};
		struct PositionKey
		{
			Vector3f mValue;
			float mTime;
		};

		AnimationNode();
		AnimationNode(std::vector<RotationKey> const& rotKeyList, std::vector<ScalingKey> const& scaleKeyList, std::vector<PositionKey> const& poKeyList);
		~AnimationNode();

		std::vector<RotationKey> const& GetRotationKeyList() const;

		std::vector<ScalingKey> const& GetScalingKeyList() const;

		std::vector<PositionKey> const& GetPositionKeyList() const;

	private:
		std::vector<RotationKey> mRotationKeyList;
		std::vector<ScalingKey> mScalingKeyList;
		std::vector<PositionKey> mPositionKeyList;

	};
}
#endif
