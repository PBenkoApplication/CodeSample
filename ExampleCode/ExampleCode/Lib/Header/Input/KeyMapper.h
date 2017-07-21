#ifndef KEYMAPPER_H
#define KEYMAPPER_H
#include "Key.h"

namespace BAME
{
	class KeyMapper
	{
	public:
		static int GetDirectXKey(Key const& key);
		static int GetDirectXSpecialKey(SpecialKey const& specialKey);
		static int GetDirectXMouseButton(MouseButton const& mouseButton);

		static int GetGLFWKey(Key const& key);
		static int GetGLFWSpecialKey(SpecialKey const& specialKey);
		static int GetGLFWMouseButton(MouseButton const& mouseButton);
	};
}
#endif 
