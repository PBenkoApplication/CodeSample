#ifndef IPARTICLESYSTEM_H
#define IPARTICLESYSTEM_H
#include <vector>
#include "Particle.h"
#include <stack>
#include "../Graphics/Rendering/Buffer/BufferHandler.h"
#include "../Graphics/Textures/ITexture.h"

namespace BAME
{
	enum class Mechanics
	{
		Static,
		Dynamic
	};
	class IParticleSystem
	{
	public:
		//IParticleSystem(int maxParticleCount);
		IParticleSystem();
		virtual ~IParticleSystem();

		//Gibt eine Liste der zu zeichnenden Particle zurück
		virtual std::vector<Particle> const& Update(float frameTime) = 0;

		Mechanics const& GetMechanics() const;

		void SetMechanics(Mechanics const& mechanics);
		void SetTexture(std::string const& path, bool isSRGB = false);
		int GetVertexBufferID() const;
		ITexture* GetTexture() const;
		bool IsTextureUsed() const;
		float GetWidth() const;
		float GetHeight() const;
		unsigned int GetParticleCount() const;

		void UpdateSystem(float frameTime);
		
	protected:
		float mParticleWidth;
		float mParticleHeight;
		Mechanics mMechanics;
		int mMaxParticleCount;
		bool mIsInit;
	private:
		int mVertexBufferID;
		std::vector<Vertex> mVertexBuffer;
		ITexture* mTexture;
		bool mIsTextureUsed;
	};
}
#endif
