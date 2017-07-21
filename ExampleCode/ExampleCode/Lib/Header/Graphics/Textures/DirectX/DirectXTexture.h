#ifndef DIRECTXTEXTURE_H
#define DIRECTXTEXTURE_H
#include <d3d11.h>
#include <wrl/client.h>
#include <string>
#include "../ITexture.h"


namespace BAME
{
	class DirectXTexture : public ITexture
	{
	public:
		//DirectXTexture();
		~DirectXTexture();
		DirectXTexture(std::string const& fileName, Microsoft::WRL::ComPtr<ID3D11Device> const& device, Microsoft::WRL::ComPtr<ID3D11DeviceContext> const& deviceContext,  bool isSRGB, bool dds = false);
		//DirectXTexture(std::string const& fileName, Microsoft::WRL::ComPtr<ID3D11Device> const& device, Microsoft::WRL::ComPtr<ID3D11DeviceContext> const& deviceContext, std::string const& front, std::string const& back, std::string const& left, std::string const& right, std::string const& top);

		Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> const& GetShaderResourceView() const
		{
			return mShaderResourceView;
		}

	private:
		Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> mShaderResourceView;
	};
}
#endif
