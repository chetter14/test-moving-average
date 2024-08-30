#ifndef MOVING_AVERAGE_H
#define MOVING_AVERAGE_H

#include <vector>

template<typename T>
std::vector<T> calculateSimpleMovingAverage(const std::vector<T>& values, int windowSize);

#endif	// MOVING_AVERAGE_H