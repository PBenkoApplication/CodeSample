
#include "AudioPlayer.h"
#include "../Mathematics/Vector3f.h"


namespace BAME
{
	AudioPlayer::AudioPlayer():
		mSoundApi(nullptr)
	{
	}


	AudioPlayer::~AudioPlayer()
	{
	}

	void AudioPlayer::Init(ISoundAPI* soundAPI)
	{
		mSoundApi = soundAPI;
	}

	void AudioPlayer::SetListener(ISoundListener* listener) const
	{
		mSoundApi->SetListener(listener);
	}

	void AudioPlayer::SetListenerPosition(Vector3f const& position) const
	{
		mSoundApi->SetListenerPosition(position);
	}

	void AudioPlayer::SetListenerVelocity(Vector3f const& velocity) const
	{
		mSoundApi->SetListenerVelocity(velocity);
	}

	void AudioPlayer::SetListenerOrientation(Vector3f const& orientationAt, Vector3f const& orientationUp) const
	{
		mSoundApi->SetListenerOrientation(orientationAt, orientationUp);
	}

	void AudioPlayer::Add(ISoundSource* soundSource) const
	{
		mSoundApi->AddSoundSource(soundSource);
	}

	void AudioPlayer::Play(ISoundSource* soundSource) const
	{
		mSoundApi->Play(soundSource);
	}

	void AudioPlayer::Pause(ISoundSource* soundSource) const
	{
		mSoundApi->Pause(soundSource);
	}

	void AudioPlayer::Mute(ISoundSource* soundSource) const
	{
		mSoundApi->Mute(soundSource);
	}

	void AudioPlayer::UnMute(ISoundSource* soundSource) const
	{
		mSoundApi->UnMute(soundSource);
	}

	ISoundSource* AudioPlayer::CreateSoundSource(ISound* sound, float pitchFactor, float volume, Vector3f const& position, Vector3f const& velocity, bool looping) const
	{
		return mSoundApi->CreateSoundSource(sound, pitchFactor, volume, position, velocity, looping);
	}

	ISound* AudioPlayer::CreateSound(std::string const& filePath) const
	{
		return mSoundApi->CreateSound(filePath);
	}

	ISoundListener* AudioPlayer::CreateSoundListener() const
	{
		return mSoundApi->CreateSoundListener();
	}

	void AudioPlayer::Stop(ISoundSource* soundSource) const
	{
		mSoundApi->Stop(soundSource);
	}
}
