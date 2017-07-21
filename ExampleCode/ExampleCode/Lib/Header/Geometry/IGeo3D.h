#ifndef IGEO3D_H
#define IGEO3D_H
#include <vector>
#include "ITopology.h"
#include "Vertex.h"
#include "Topology.h"
#include "../Graphics/Material/Material.h"

namespace BAME
{
	class IGeo3D
	{
	public:
		explicit IGeo3D(Topology topology);
		virtual ~IGeo3D();


		std::vector<Vertex> const& GetVertexList() const;

		std::vector<unsigned int> const& GetIndexList() const;

		Topology GetTopology() const;

		std::vector<ITopology> const& GetItsTopologyList() const;
		void Add(ITopology const& topology);
		void AddList(std::vector<ITopology> const& topologyList);
		virtual void BuildVertexList() = 0;
		virtual void BuildIndexList() = 0;

		const Material* GetMaterial() const;


		void SetMaterial(const Material* material);

		bool IsVisible() const;

		void SwitchOn();

		void SwitchOff();

		bool hasVertexListChanged() const { return mHasVertexListChanged; }

		void SetVertexList(std::vector<Vertex> const& vertexList);
		void SetIndexList(std::vector<unsigned int> const& IndexList);

		void SetHasVertexListChanged(bool hasChanged);
	protected:
		const Material* mMaterial;

		bool mIsVisible;
		Topology mTopology;
		std::vector<ITopology> mTopologyList;
		std::vector<Vertex> mVertexList;
		std::vector<unsigned int> mIndexList;

		bool mHasVertexListChanged;
	};
}

#endif
