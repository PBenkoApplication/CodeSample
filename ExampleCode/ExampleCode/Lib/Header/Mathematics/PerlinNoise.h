#ifndef PERLINNOISE_H
#define PERLINNOISE_H

namespace BAME
{
	class PerlinNoise
	{
	public:

		// Constructor
		PerlinNoise();
		PerlinNoise(double persistence, double frequency, double amplitude, int octaves, int randomseed);

		// Get Height
		double GetHeight(double x, double y) const;

		// Get
		double GetPersistence() const;
		double GetFrequency() const;
		double GetAmplitude() const;
		int GetOctaves() const;
		int GetRandomSeed() const;

		// Set
		void Set(double persistence, double frequency, double amplitude, int octaves, int randomseed);
		void SetPersistence(double persistence);
		void SetFrequency(double frequency);
		void SetAmplitude(double amplitude);
		void SetOctaves(int octaves);
		void SetRandomSeed(int randomseed);

	private:
		double Total(double i, double j) const;
		double GetValue(double x, double y) const;
		double Interpolate(double x, double y, double a) const;
		double Noise(int x, int y) const;

		double mPersistence, mFrequency, mAmplitude;
		int mOctaves, mRandomSeed;
	};
}
#endif
