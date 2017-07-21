#ifndef HELPER_H
#define HELPER_H

namespace BAME
{
	namespace Helper
	{
		// Safely deletes Objects
		template <typename T>
		inline void SafeDelete(T& ptr)
		{
			if (ptr)
			{
				delete ptr;
				ptr = nullptr;
			}
		}
	}
}
#endif
