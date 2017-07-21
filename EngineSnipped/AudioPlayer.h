#ifndef AUDIOPLAYER_H
#define AUDIOPLAYER_H

#include <vector>
#include "../Core/SoundAPI/ISoundAPI.h"

namespace BAME
{
	class AudioPlayer
	{
	public:
		AudioPlayer();
		~AudioPlayer();
		void Init(ISoundAPI* soundAPI);
		void SetListener(ISoundListener* listener) const;
		void SetListenerPosition(Vector3f const& position) const;
		void SetListenerVelocity(Vector3f const& velocity) const;
		void SetListenerOrientation(Vector3f const& orientationAt, Vector3f const& orientationUp) const;
		void Add(ISoundSource* soundSource) const;
		void Play(ISoundSource* soundSource) const;
		void Pause(ISoundSource* soundSource) const;
		void Stop(ISoundSource* soundSource) const;
		void Mute(ISoundSource* soundSource) const;
		void UnMute(ISoundSource* soundSource) const;
		ISoundSource* CreateSoundSource(ISound* sound, float pitchFactor, float volume, Vector3f const& position, Vector3f const& velocity, bool looping) const;
		ISound* CreateSound(std::string const& filePath) const;
		ISoundListener* CreateSoundListener() const;

	private:
		ISoundAPI* mSoundApi;
	};
}
#endif
