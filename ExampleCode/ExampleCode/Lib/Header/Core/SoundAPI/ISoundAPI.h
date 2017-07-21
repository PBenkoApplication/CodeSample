#ifndef ISOUNDAPI_H
#define ISOUNDAPI_H
#include <vector>
#include "../../Audio/SoundSource/ISoundSource.h"
#include "../../Audio/SoundListener/ISoundListener.h"

namespace BAME
{
	class ISound;

	class ISoundAPI
	{
	public:
		ISoundAPI();
		virtual ~ISoundAPI();
		virtual void Init() =0;
		virtual void SetListener(ISoundListener* listener) = 0;
		virtual void SetListenerPosition(Vector3f const& position) = 0;
		virtual void SetListenerVelocity(Vector3f const& velocity) = 0;
		virtual void SetListenerOrientation(Vector3f const& orientationAt, Vector3f const& orientationUp) = 0;
		virtual void AddSoundSource(ISoundSource* soundSource) = 0;
		virtual void Play(ISoundSource* soundSource) = 0;
		virtual void Pause(ISoundSource* soundSource) = 0;
		virtual void Stop(ISoundSource* soundSource) = 0;
		virtual void Mute(ISoundSource* soundSource) = 0;
		virtual void UnMute(ISoundSource* soundSource) = 0;
		virtual ISoundSource* CreateSoundSource(ISound* sound, float pitchFactor, float volume, Vector3f const& position, Vector3f const& velocity, bool looping) = 0;
		virtual ISound* CreateSound(std::string const& filePath) = 0;
		virtual ISoundListener* CreateSoundListener() = 0;
		virtual void Update() = 0;
	protected:
		std::vector<ISoundSource*> mSoundSourceList;
		std::vector<ISound*> mSoundList;
		ISoundListener* mSoundListener;
	};
}
#endif
