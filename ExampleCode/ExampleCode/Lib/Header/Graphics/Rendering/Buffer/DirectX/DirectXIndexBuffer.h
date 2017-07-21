#ifndef DIRECTXINDEXBUFFER_H
#define DIRECTXINDEXBUFFER_H
#include "../IIndexBuffer.h"
#include <vector>
#include "../../Renderer/DirectX/DirectXHelper.h"
#include "d3d11.h"

namespace BAME
{
	class DirectXIndexBuffer : public IIndexBuffer
	{
	public:
		DirectXIndexBuffer(Microsoft::WRL::ComPtr<ID3D11Device> const& device, Microsoft::WRL::ComPtr<ID3D11DeviceContext> const& deviceContext, std::vector<unsigned int> const& vertexList);
		~DirectXIndexBuffer();
		Microsoft::WRL::ComPtr<ID3D11Buffer> const& GetBuffer() const;
		void Update(std::vector<unsigned> const& indexList) override;
	private:
		Microsoft::WRL::ComPtr<ID3D11Buffer> mIndexBuffer;
		Microsoft::WRL::ComPtr<ID3D11DeviceContext> const& mDeviceContext;
	};
}
#endif
