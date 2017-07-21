#ifndef SPOTLIGHT_H
#define SPOTLIGHT_H
#include "ILight.h"
#include "../../Mathematics/Vector3f.h"

namespace BAME
{
	class SpotLight : public ILight
	{
	public:
		SpotLight();
		~SpotLight();

		void Init(Vector3f const& direction, Vector3f const& position, float minSpotAngle, float maxSpotAngle, float tightness);

		Vector3f const& GetDirection() const;

		Vector3f const& GetPosition() const;

		void SpotTo(Vector3f const& spotPoint);

		float GetMinSpotAngle() const;

		float GetMaxSpotAngle() const;

		float GetTightness() const;

		void SetMinSpotAngle(float minSpotAngle);

		void SetMaxSpotAngle(float maxSpotAngle);

		void SetTightness(float tightness);

		void SetPosition(Vector3f const& pos);

	private:
		Vector3f mDirection;
		float mMinSpotAngle;
		float mMaxSpotAngle;
		float mTightness;
		Vector3f mPosition;
	};
}
#endif
