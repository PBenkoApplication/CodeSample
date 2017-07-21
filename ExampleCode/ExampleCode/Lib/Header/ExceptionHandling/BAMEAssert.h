#ifndef BAMEASSERT_H
#define BAMEASSERT_H
#define BAMEASSERT(cond, message) { _BAMEAssert(cond, message, __FILE__, __LINE__); }


#include <string>
#include <iostream>
#include <stdio.h>

namespace BAME
{
	inline void _BAMEAssert(bool cond, std::string const& message, std::string file, int line)
	{
		if (!cond)
		{
			std::cerr << message << "in File: " << file << "@ Line: " << line << std::endl;
			getchar();
			exit(EXIT_FAILURE);
			//abort();
		}
	}
}

#endif
