#ifndef TIMER_H
#define TIMER_H

#include <chrono>

class Timer
{
private:
	std::chrono::system_clock::time_point start;

public:
	void launch()
	{
		start = std::chrono::system_clock::now();
	}

	double getDuration()
	{
		const auto now = std::chrono::system_clock::now();
		const std::chrono::duration<double> delta = now - start;
		return delta.count();
	}
};

#endif	// TIMER_H