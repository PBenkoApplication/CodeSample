#ifndef ISOUND_H
#define ISOUND_H
#include <string>

namespace BAME
{
	class ISound
	{
	public:
		ISound();
		virtual ~ISound();
		virtual std::string const& GetFilePath() { return mFilePath; };
	protected:
		std::string mFilePath;
	};
}
#endif
