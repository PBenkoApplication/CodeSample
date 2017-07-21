#ifndef ITEXTUREFACTORY_H
#define ITEXTUREFACTORY_H
#include <map>
#include <memory>

namespace BAME
{
	class Texture;
	class ITexture;
	typedef ITexture* ManagedTexturePtr;

	class ITextureFactory
	{
	public:
		ITextureFactory();
		virtual ~ITextureFactory();
		/*virtual std::unique_ptr<ITexture> CreateUnique_Texture(Texture const& texture) = 0;
		virtual std::unique_ptr<ITexture> CreateUnique_DDSCubeTexture(Texture const& texture) = 0;
	*/ //virtual std::unique_ptr<ITexture>CreateSkyboxUnique_Texture(std::string const& front, std::string const& back, std::string const& left, std::string const& right, std::string const& top) = 0;


		ManagedTexturePtr CreateManaged_Texture(Texture const& texture, bool isSRGB);

		ManagedTexturePtr CreateManaged_DDSCubeTexture(Texture const& texture, bool isSRGB);

	protected:
		std::map<std::string, std::unique_ptr<ITexture>> mTexturePool;
		virtual void AddNewTextureToPool(std::string const& texturePath, bool isSRGB) = 0;
		virtual void AddNewDDSCubeMapTextureToPool(std::string const& texturePath, bool isSRGB) = 0;
	};
}
#endif
