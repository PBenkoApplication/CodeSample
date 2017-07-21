#ifndef SOUNDSOURCEOPENAL_H
#define SOUNDSOURCEOPENAL_H
#include "../../Mathematics/Vector3f.h"
#include "../Sound/ISound.h"

namespace BAME
{
	class ISoundSource
	{
	public:
		ISoundSource(ISound* sound);
		virtual ~ISoundSource();
		virtual void SetIndex(int index) =0;
		virtual void SetPitchFactor(float pitchFactor) = 0;
		virtual void SetVolume(float volume) = 0;
		virtual void SetPosition(Vector3f const& position) = 0;
		virtual void SetVelocity(Vector3f const& velocity) = 0;
		virtual void SetLooping(bool looping) = 0;
		virtual int GetIndex() = 0;
		virtual float GetPitchFactor() = 0;
		virtual float GetVolume() = 0;
		virtual Vector3f const& GetPosition() = 0;
		virtual Vector3f const& GetVelocity() = 0;
		virtual bool GetLooping() = 0;

	private:
		ISound* mSound;
	};
}
#endif
