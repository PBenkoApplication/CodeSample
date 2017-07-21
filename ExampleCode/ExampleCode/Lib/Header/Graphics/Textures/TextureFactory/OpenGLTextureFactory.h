#ifndef OPENGLTEXTUREFACTORY_H
#define OPENGLTEXTUREFACTORY_H
#include "ITextureFactory.h"
#include "../OpenGL/OpenGLTexture.h"

namespace BAME
{
	class OpenGLTextureFactory : public ITextureFactory
	{
	public:
		OpenGLTextureFactory();
		~OpenGLTextureFactory();
	protected:
		void AddNewTextureToPool(std::string const& texturePath, bool isSRGB) override;
		void AddNewDDSCubeMapTextureToPool(std::string const& texturePath, bool isSRGB) override;
		/*std::unique_ptr<ITexture> CreateUnique_Texture(Texture const& texture) override;
		std::unique_ptr<ITexture> CreateUnique_DDSCubeTexture(Texture const& texture) override;
	*/ //std::unique_ptr<ITexture> CreateSkyboxUnique_Texture(std::string const& front, std::string const& back, std::string const& left, std::string const& right, std::string const& top) override;
		/*private:
			std::map<std::string, OpenGLTexture*> mOpenGLTextureMap;
			std::list<std::string> mTexturePathList;*/
	};
}
#endif
