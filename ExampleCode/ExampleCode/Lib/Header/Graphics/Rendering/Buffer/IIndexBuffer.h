#ifndef IINDEXBUFFER_H
#define IINDEXBUFFER_H
#include "IBuffer.h"
#include <vector>

namespace BAME
{
	class IIndexBuffer : public IBuffer
	{
	public:
		IIndexBuffer()
		{
		};

		virtual ~IIndexBuffer()
		{
		};

		virtual void Update(std::vector<unsigned> const& indexList) = 0;
	};
}
#endif
