#ifndef ConstantBufferHelper_H
#define ConstantBufferHelper_H
#include "../../../Rendering/Buffer/DirectX/DirectXIndexBuffer.h"

namespace BAME
{
	class ConstantBufferHelper
	{
	public:
		//ConstantBufferHelper();
		//~ConstantBufferHelper();

		static HRESULT CreateConstantBuffer(Microsoft::WRL::ComPtr<ID3D11Device> const& device, size_t size, ID3D11Buffer** buffer, UINT cpuAccessFlags = 0, D3D11_USAGE useage = D3D11_USAGE_DEFAULT);
		static void UpdateConstantBuffer(ID3D11DeviceContext* deviceContext, ID3D11Buffer* buffer, void const* data, size_t dataSize);
	};

	//inline void UpdateConstantBuffer(ID3D11DeviceContext* deviceContext, ID3D11Buffer* buffer, void* data, size_t dataSize)
	//{
	//	D3D11_MAPPED_SUBRESOURCE mappedResource4;
	//	ZeroMemory(&mappedResource4, sizeof(D3D11_MAPPED_SUBRESOURCE));
	//	//	Disable GPU access to the vertex buffer data.
	//	deviceContext->Map(buffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedResource4);
	//	//	Update the vertex buffer here.
	//	memcpy(mappedResource4.pData, &data, dataSize);
	//	//	Reenable GPU access to the vertex buffer data.
	//	deviceContext->Unmap(buffer, 0);
	//};
}
#endif
