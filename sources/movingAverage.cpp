#include "movingAverage.h"
#include <vector>


template<typename T>
std::vector<T> calculateSimpleMovingAverage(const std::vector<T>& values, int windowSize)
{
	// Вектор значений простых скользящих средних (при инициализации присваиваем нули)
	std::vector<T> sma(values.size(), 0.0);

	// Считаем "стартовое" значение скользящего среднего
	T sum = 0;
	int i;
	for (i = 0; i < windowSize; ++i)
		sum += values[i];
	sma[windowSize - 1] = sum / windowSize;

	// Далее расчитываем простое скользящее среднее с использованием значения на предыдущем шаге
	for (; i < values.size(); ++i)
		sma[i] = sma[i - 1] + (values[i] - values[i - windowSize]) / windowSize;

	return sma;
}

// Создаём экземпляры функций с конкретно float и double типом
template std::vector<float> calculateSimpleMovingAverage<float>(const std::vector<float>&, int);
template std::vector<double> calculateSimpleMovingAverage<double>(const std::vector<double>&, int);