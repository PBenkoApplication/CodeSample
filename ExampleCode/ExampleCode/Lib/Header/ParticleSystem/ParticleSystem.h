#ifndef PARTICLESYSTEM_H
#define PARTICLESYSTEM_H
#include "IParticleSystem.h"


namespace BAME
{

	class ParticleSystem : public IParticleSystem
	{
	public:
		ParticleSystem();
		~ParticleSystem();


		void AddParticle(Particle const& particle);
		void SpawnParticle();
		std::vector<Particle> const& Update(float frameTime) override;

		void Init(unsigned int particleCount,float particleWidth=1.f, float particleHeight = 1.f, Vector3f const& velocity=Vector3f::Zero(), Vector3f const& acceleration = Vector3f::Zero(), Mechanics const& mechanics = Mechanics::Dynamic, float strength = 1.0f);
		void InitStatic(std::vector<Particle> const& particles, float particleWidth = 1.f, float particleHeight = 1.f);

		void SetStrength(float strength);
		float GetStrength() const;	
		
	private:

		std::vector<Particle> mActiveParticleList;
		std::stack<Particle> mDeadParticleList;

		float mLastSpawn;
		float mStrength;
	};
}

#endif
