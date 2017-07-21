#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H
#include "../Graphics/Textures/TextureFactory/ITextureFactory.h"


namespace BAME
{
	class RessourceManager
	{
	public:
		void Init(ITextureFactory* textureFactory);

		ManagedTexturePtr LoadTexture(std::string const& path, bool isSRGB) const;
		static RessourceManager* GetInstance();
		private:
			ITextureFactory* mTextureFactory;
		~RessourceManager();
		RessourceManager();
		
	};

}

#endif