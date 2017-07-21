#ifndef ISOUNDSOURCE_H
#define ISOUNDSOURCE_H
#include "../ISoundSource.h"
#include <al.h>

namespace BAME
{
	class SoundSourceOpenAL :public ISoundSource
	{
	public:
		SoundSourceOpenAL(ISound* sound, float pitchFactor, float volume, Vector3f const& position, Vector3f const& velocity, bool looping);
		~SoundSourceOpenAL();
		void SetIndex(int index) override;
		void SetPitchFactor(float pitchFactor) override;
		void SetVolume(float volume) override;
		void SetPosition(Vector3f const& position) override;
		void SetVelocity(Vector3f const& velocity) override;
		void SetLooping(bool looping) override;
		int GetIndex() override;
		float GetPitchFactor() override;
		float GetVolume() override;
		Vector3f const& GetPosition() override;
		Vector3f const& GetVelocity() override;
		bool GetLooping() override;
		ALuint GetSoundSourceId();

	private:
		ALuint mSoundSourceId;
		int mIndex;
		float mPitchFactor;
		float mVolume;
		Vector3f mPosition;
		Vector3f mVelocity;
		bool mLooping;
	};
}
#endif
