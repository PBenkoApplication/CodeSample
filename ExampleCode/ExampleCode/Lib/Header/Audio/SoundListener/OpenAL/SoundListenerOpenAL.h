#ifndef SOUNDLISTENEROPENAL_H
#define SOUNDLISTENEROPENAL_H
#include "../ISoundListener.h"

namespace BAME
{
	class SoundListenerOpenAL : public ISoundListener
	{
	public:
		SoundListenerOpenAL();
		~SoundListenerOpenAL();

		void SetPosition(const Vector3f& position) override;
		void SetVelocity(const Vector3f& velocity) override;
		void SetOrientationAt(const Vector3f& orientationAt) override;
		void SetOrientationUp(const Vector3f& orientationUp) override;
	};
}
#endif
