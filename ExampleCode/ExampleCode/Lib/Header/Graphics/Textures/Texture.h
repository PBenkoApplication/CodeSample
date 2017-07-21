#ifndef TEXTURE_H
#define TEXTURE_H
#include <string>

namespace BAME
{
	class Texture
	{
	public:
		Texture();

		explicit Texture(std::string const& path);
		std::string const& GetPath() const;

		virtual ~Texture()
		{
		};

	protected:
		std::string mPath;
	};
}
#endif
