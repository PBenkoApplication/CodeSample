#ifndef DIRECTXVERTEXBUFFER_H
#define DIRECTXVERTEXBUFFER_H
#include "../IVertexBuffer.h"
#include "../../../Geometry/Vertex.h"
#include <vector>
#include "../../Renderer/DirectX/DirectXHelper.h"
#include <d3d11.h>

namespace BAME
{
	class DirectXVertexBuffer : public IVertexBuffer
	{
	public:
		DirectXVertexBuffer(Microsoft::WRL::ComPtr<ID3D11Device> const& device, Microsoft::WRL::ComPtr<ID3D11DeviceContext> const& deviceContext, std::vector<Vertex> const& vertexList);
		DirectXVertexBuffer(Microsoft::WRL::ComPtr<ID3D11Device> const& device, Microsoft::WRL::ComPtr<ID3D11DeviceContext> const& deviceContext, const void* vertexList, size_t size);

		~DirectXVertexBuffer();

		Microsoft::WRL::ComPtr<ID3D11Buffer> const& GetBuffer() const;

		void Update(std::vector<Vertex> const& vertexList) override;
	private:
		Microsoft::WRL::ComPtr<ID3D11Buffer> mVertexBuffer;

		Microsoft::WRL::ComPtr<ID3D11DeviceContext> const& mDeviceContext;
		Microsoft::WRL::ComPtr<ID3D11Device> const& mDevice;
	};
}
#endif
