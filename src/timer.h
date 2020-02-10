#pragma once

#include<chrono>

class Timer
{
public:
	// return milliseconds passed since last mark
	unsigned int Mark();

private:
	std::chrono::steady_clock::time_point lastMark = std::chrono::steady_clock::now();

};