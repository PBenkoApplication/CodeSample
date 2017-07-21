#ifndef COLORRGB_H
#define COLORRGB_H

#include "../../Mathematics/Vector4f.h"


namespace BAME
{
	class ColorRGB
	{
	public:
		ColorRGB();
		ColorRGB(const float r, const float g, const float b, const float a = 1.0);
		~ColorRGB();

		float GetRed() const;
		float GetBlue() const;
		float GetGreen() const;
		float GetAlpha() const;

		void SetRed(const float value);
		void SetBlue(const float value);
		void SetGreen(const float value);
		void SetAlpha(const float value);

		Vector4f ToVector4f() const;
	private:

		float mRed, mGreen, mBlue, mAlpha;
	};
}

#endif
