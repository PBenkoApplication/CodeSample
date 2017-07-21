#ifndef ISOUNDOPENAL_H
#define ISOUNDOPENAL_H
#include "../ISound.h"
#include <al.h>
#include <string>

namespace BAME
{
	class SoundOpenAL : public ISound
	{
	public:
		SoundOpenAL(std::string const& filePath);
		~SoundOpenAL();
		ALuint GetBufferId() const;

	private:
		ALuint mBufferId;
	};
}
#endif
