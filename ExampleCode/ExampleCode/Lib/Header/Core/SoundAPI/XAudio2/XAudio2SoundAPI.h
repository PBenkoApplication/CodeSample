#ifndef XAUDIO2SOUNDAPI
#define XAUDIO2SOUNDAPI
#include "../ISoundAPI.h"
#include <Audio.h>

namespace BAME
{
	class XAudio2SoundAPI :public ISoundAPI
	{
	public:
		XAudio2SoundAPI();
		~XAudio2SoundAPI();
		void Init() override;
		void SetListener(ISoundListener* listener) override;
		void SetListenerPosition(Vector3f const& position) override;
		void SetListenerVelocity(Vector3f const& velocity) override;
		void SetListenerOrientation(Vector3f const& orientationAt, Vector3f const& orientationUp) override;
		void AddSoundSource(ISoundSource* soundSource) override;
		void Play(ISoundSource* soundSource) override;
		void Pause(ISoundSource* soundSource) override;
		void Stop(ISoundSource* soundSource) override;
		void Mute(ISoundSource* soundSource) override;
		void UnMute(ISoundSource* soundSource) override;

		void Update() override;
	private:
		std::unique_ptr<DirectX::AudioEngine> m_audEngine;
		bool m_retryAudio;
	};
}
#endif
