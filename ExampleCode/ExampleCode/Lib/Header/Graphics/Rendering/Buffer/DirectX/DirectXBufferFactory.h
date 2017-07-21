#ifndef DIRECTXBUFFERFACTORY_H
#define DIRECTXBUFFERFACTORY_H
#include "../IBufferFactory.h"
#include <d3d11.h>
#include <wrl/client.h>


namespace BAME
{
	class DirectXBufferFactory : public IBufferFactory
	{
	public:

		DirectXBufferFactory(Microsoft::WRL::ComPtr<ID3D11Device> const& device, Microsoft::WRL::ComPtr<ID3D11DeviceContext> const& deviceContext);
		~DirectXBufferFactory();

		IVertexBuffer* CreateVertexBuffer(std::vector<Vertex> const& vertexList) override;
		IIndexBuffer* CreateIndexBuffer(std::vector<unsigned int> const& indexList) override;
		IVertexBuffer* CreateVertexBoneBuffer(std::vector<VertexBone> const& vertexList) override;
		Microsoft::WRL::ComPtr<ID3D11Device> const& mDevice;
		Microsoft::WRL::ComPtr<ID3D11DeviceContext> const& mDeviceContext;
	};
}
#endif
