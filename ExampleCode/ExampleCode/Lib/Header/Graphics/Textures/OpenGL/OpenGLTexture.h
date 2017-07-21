#ifndef OPENGLTEXTURE_H
#define OPENGLTEXTURE_H
#include <string>
#include "../ITexture.h"


namespace BAME
{
	class OpenGLTexture : public ITexture
	{
	public:
		OpenGLTexture();
		~OpenGLTexture();
		OpenGLTexture(std::string const& fileName);

		int GetID() const;
		void Bind() const;

	private:
		int mId;
	};
}
#endif
