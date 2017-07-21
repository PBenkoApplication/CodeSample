#ifndef DIRECTXTEXTUREFACTORY_H
#define DIRECTXTEXTUREFACTORY_H
#include "ITextureFactory.h"
#include "../DirectX/DirectXTexture.h"

namespace BAME
{
	class DirectXTextureFactory : public ITextureFactory
	{
	public:
		DirectXTextureFactory(Microsoft::WRL::ComPtr<ID3D11Device> const& device, Microsoft::WRL::ComPtr<ID3D11DeviceContext> const& deviceContext);
		~DirectXTextureFactory();
	protected:
		void AddNewTextureToPool(std::string const& texturePath, bool isSRGB) override;
		void AddNewDDSCubeMapTextureToPool(std::string const& texturePath, bool isSRGB) override;
		/*std::unique_ptr<ITexture> CreateUnique_Texture(Texture const& texture) override;
		std::unique_ptr<ITexture> CreateUnique_DDSCubeTexture(Texture const& texture) override;*/
		//std::unique_ptr<ITexture> CreateSkyboxUnique_Texture(std::string const& front, std::string const& back, std::string const& left, std::string const& right, std::string const& top) override;
	private:
		Microsoft::WRL::ComPtr<ID3D11Device> const& mDevice;
		Microsoft::WRL::ComPtr<ID3D11DeviceContext> const& mDeviceContext;
	};
}
#endif
