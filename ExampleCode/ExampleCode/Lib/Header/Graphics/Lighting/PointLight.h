#ifndef POINTLIGHT_H
#define POINTLIGHT_H
#include "ILight.h"
#include "../../Mathematics/Vector3f.h"
#include "../../Physics/BoundingVolumes/AABB.h"

namespace BAME
{
	class PointLight : public ILight
	{
	public:
		PointLight();
		~PointLight();

		void Init(const float radius, Vector3f const& position, const float minDistance = .0f, const float maxDistance = 5.f);
		Vector3f const& GetPosition() const;
		float GetMinDistance() const;
		float GetMaxDistance() const;

		void SetMinDistance(float minDist);
		void SetMaxDistance(float maxDist);
		void SetPosition(Vector3f const& position);

		AABB const& GetBoundingBox() const
		{
			return AABB(mMinDistance, mMaxDistance, 
				mMinDistance, mMaxDistance,
					mMinDistance, mMaxDistance);
		}
		bool IsInFrustum()const { return mIsinFrustum; }
		void SetInFrustum(bool inFrustum)
		{
			mIsinFrustum = inFrustum;
		}
	private:

		bool mIsinFrustum;
		float mRadius;
		float mMinDistance;
		float mMaxDistance;
		AABB mBoundingBox;

		Vector3f mPosition;

		
	};
}
#endif
