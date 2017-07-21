#ifndef SKINNINGANIMATION_H
#define SKINNINGANIMATION_H
#include "AnimationNode.h"
#include <list>
#include <deque>
namespace BAME
{
	class SkinningAnimation
	{
	public:
		SkinningAnimation();
		~SkinningAnimation();

		std::vector<AnimationNode> const& GetAffectedNodeList() const
		{
			return mAffectedNodeList;
		}

		float GetDuration() const
		{
			return mDuration;
		}

		std::string const& GetName() const
		{
			return mName;
		}

		void Init(std::string const& name, std::vector<AnimationNode> const& animationNodes, float duration)
		{
			mName = name;
			mAffectedNodeList = animationNodes;
			mDuration = duration;
		}

	private:
			std::vector<AnimationNode> mAffectedNodeList;
		float mDuration;
		std::string mName;
	};
}
#endif