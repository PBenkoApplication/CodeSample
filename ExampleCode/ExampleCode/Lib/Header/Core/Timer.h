#ifndef TIMER_H
#define TIMER_H
#include <chrono>

namespace BAME
{
	class Timer
	{
	public:
		Timer();
		~Timer();
		void Start();
		double ElapsedTime() const;
		double Timer::ElapsedTimeAsNano() const;
	private:
		std::chrono::high_resolution_clock::time_point mStart;
		bool isRunning = true;
	};
}

#endif
