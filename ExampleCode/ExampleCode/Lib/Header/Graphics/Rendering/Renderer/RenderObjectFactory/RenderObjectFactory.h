#ifndef IRENDEROBJECTFACTORY_H
#define IRENDEROBJECTFACTORY_H
#include "../RenderObject.h"

namespace BAME
{
	class ITextureFactory;
	class Skybox;

	class RenderObjectFactory
	{
	public:
		RenderObjectFactory(ITextureFactory* textureFactory);
		~RenderObjectFactory();


		RenderObject* CreateRenderObject(IGeo3D* geo, Placement* placement) const;
		RenderObject* CreateRenderObject(BoneMesh* geo, Placement* placement) const;
		RenderObject* CreateSkyboxRenderObject(Skybox* skybox, std::string const& filePath, bool isSRGB) const;
	protected:
		ITextureFactory* mTextureFactory;
	};
}
#endif
