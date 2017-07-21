#ifndef ITOPOLOGY_H
#define ITOPOLOGY_H
#include <vector>
#include "Vertex.h"

namespace BAME
{
	class ITopology
	{
	public:
		ITopology(std::vector<Vertex> const& vertices) : mVertices(vertices)
		{
		};

		virtual ~ITopology()
		{
		};

		std::vector<Vertex> const& GetVertices() const
		{
			return mVertices;
		};

		void SetVertices(std::vector<Vertex> const& vertices)
		{
			mVertices = vertices;
		}

	private:
		std::vector<Vertex> mVertices;
	};
}
#endif
