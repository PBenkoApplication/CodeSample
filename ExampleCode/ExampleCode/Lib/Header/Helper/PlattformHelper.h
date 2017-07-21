#pragma once
#include <string>
#include <VersionHelpers.h>

namespace BAME
{
	class PlattformHelper
	{
	public:
		std::string static GetPlattformInformation()
		{
			std::string plattform;
#ifdef _WIN32
			plattform += "Windows ";
			if (IsWindowsVersionOrGreater(10, 0, 0))
				plattform += "10 ";
			else if (IsWindows8Point1OrGreater())
				plattform += "8.1 ";
			//define something for Windows (32-bit and 64-bit, this part is common)

#ifdef _WIN64
	//define something for Windows (64-bit only)
			plattform += "64 Bit ";
#elif plattform += "32 Bit ";
#endif

#elif __APPLE__
#include "TargetConditionals.h"
#if TARGET_IPHONE_SIMULATOR
			// iOS Simulator
#elif TARGET_OS_IPHONE
			// iOS device
#elif TARGET_OS_MAC
			// Other kinds of Mac OS
#else
#   error "Unknown Apple platform"
#endif
#elif __linux__
			// linux
#elif __unix__ // all unices not caught above

			// Unix
#elif defined(_POSIX_VERSION)
			// POSIX
#else
#   error "Unknown compiler"
#endif
			return plattform;
		}

	};
}
