#include <pch.h>
#include "timer.h"

unsigned int Timer::Mark()
{
	std::chrono::steady_clock::time_point tempMark = lastMark;
	lastMark = std::chrono::steady_clock::now();
	return  std::chrono::duration_cast<std::chrono::milliseconds>(lastMark - tempMark).count();
}
