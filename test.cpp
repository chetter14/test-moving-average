#include "movingAverage.h"
#include <vector>
#include <iostream>

void validityTest1()
{
	std::cout << "Doing validity test1:\n";
	std::cout << "\t1) { 1, 2, 3, 4 } , window = 4\n";

	std::vector<float> example{ 1, 2, 3, 4 };
	constexpr int window = 4;

	auto result = calculateSimpleMovingAverage(example, window);

	std::cout << "\tExpected: 0 0 0 2.5\n";
	std::cout << "\tReal: ";
	for (auto value : result)
		std::cout << value << " ";
	std::cout << "\n\n";
}

void validityTest2()
{
	std::cout << "Doing validity test2:\n";
	std::cout << "\t1) { 1.2 , 2.4 , 3.6, 4.8, 6.0, 7.2 } , window = 4\n";

	std::vector<float> example{ 1.2 , 2.4 , 3.6, 4.8, 6.0, 7.2 };
	constexpr int window = 4;

	auto result = calculateSimpleMovingAverage(example, window);

	std::cout << "\tExpected: 0 0 0 3 4.2 5.4\n";
	std::cout << "\tReal: ";
	for (auto value : result)
		std::cout << value << " ";
	std::cout << "\n";
}



int main()
{
	validityTest1();
	validityTest2();


	// Сгенерировать значения
	// И вызвать функцию простого скользящего среднего

	return 0;
}