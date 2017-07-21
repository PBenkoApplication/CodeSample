#pragma once
#include "IShader.h"
#include "../../ParticleSystem/IParticleSystem.h"

namespace BAME
{
	class IParticleShader
	{
	public:
		IParticleShader();

		void UpdateParticleSystem(IParticleSystem* particleSystem);
	protected:
		IParticleSystem* mParticleSystem;
	};
}
