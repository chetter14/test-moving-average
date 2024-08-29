#include "movingAverage.h"
#include <vector>


template<typename T>
void calculateSimpleMovingAverage(const std::vector<T>& values)
{
	// Реализовать алгоритм здесь
}

// Создаём экземпляры функций с конкретно float и double типом
template void calculateSimpleMovingAverage<float>(const std::vector<float>&);
template void calculateSimpleMovingAverage<double>(const std::vector<double>&);