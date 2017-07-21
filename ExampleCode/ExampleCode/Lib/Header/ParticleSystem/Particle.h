#ifndef PARTICLE_H
#define PARTICLE_H
#include "../Mathematics/Vector3f.h"
#include "../Graphics/Material/ColorRGB.h"

namespace BAME
{
	class Particle
	{
		friend class IParticleSystem;

	public:
		Particle();
		Particle(float width, float height, Vector3f const& position, float lifetime=1.f, Vector3f const& velocity=Vector3f::Zero());
		~Particle();

		void Update(float frameTime);

		bool IsAlive() const;

		void Kill();

		void Revive(Vector3f const& position, float width, float height, float lifetime = 1.f, Vector3f const& velocity = Vector3f::Zero());
		void Revive(Vector3f const& position, float lifeTime);
		void Revive(Vector3f const& position, float width, float height, float lifeTime);
		float GetWidth() const;
		float GetHeight() const;
		Vector3f const& GetVelocity() const;
		Vector3f const& GetAcceleration() const;

		void SetVelocity(Vector3f const& velocity);
		void SetAcceleration(Vector3f const& velocity);

		ColorRGB const& GetColor() const;

		void SetColor(ColorRGB const& color);

	private:
		Vector3f mVelocity;
		Vector3f mAcceleration;
		Vector3f mPosition;
		bool mIsAlive;
		float mLifetime;
		float mWidth;
		float mHeight;

		ColorRGB mColor;

		float mRadius;
		float newAngle;
	};
}
#endif
