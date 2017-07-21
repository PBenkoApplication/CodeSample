#ifndef ILIGHT
#define ILIGHT
#include "../Material/ColorRGB.h"

namespace BAME
{
	class ILight
	{
	public:
		ILight();
		float GetIntensity() const;
		virtual ~ILight();

		void SetColor(ColorRGB const& color);

		ColorRGB const& GetColor() const;

		bool IsEnabled() const;
		void Enable();
		void Disable();
		void SetIntensity(float intesity);

	protected:
		ColorRGB mColor;
		bool mEnabled;
		float mIntensity;
	};
}
#endif
