// Dateiname:Quad.h
// Author: Patrick Benkowitsch
// Letztes Änderungsdatum: 27.08.2015 13:50
#ifndef Quad_H
#define Quad_H
#include "../GeoTriangle3D.h"

namespace BAME
{
	class Quad : public GeoTriangle3D
	{
	public:
		explicit Quad();
		Quad(const float width, const float height, const float depth);
		Quad(float minX, float maxX, float minY, float maxY, float minZ, float maxZ);

		~Quad();

		float GetWidth() const;
		void SetWidth(const float value);

		float GetHeight() const;
		void SetHeight(const float value);

		float GetDepth() const;
		void SetDepth(const float value);

	private:

		float mWidth;
		float mHeight;
		float mDepth;
	};
}
#endif // Quad_H
