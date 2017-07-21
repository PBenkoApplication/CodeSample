#ifndef OPENALSOUNDAPI_H
#define OPENALSOUNDAPI_H
#include "../ISoundAPI.h"

namespace BAME
{
	class OpenALSoundAPI : public ISoundAPI
	{
	public:
		OpenALSoundAPI();
		~OpenALSoundAPI();
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
		ISoundSource* CreateSoundSource(ISound* sound, float pitchFactor, float volume, Vector3f const& position, Vector3f const& velocity, bool looping) override;
		ISound* CreateSound(std::string const& filePath) override;
		ISoundListener* CreateSoundListener() override;
	};
}
#endif
