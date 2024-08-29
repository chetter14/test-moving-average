#include "movingAverage.h"
#include "timer.h"
#include <vector>
#include <iostream>
#include <random>
#include <array>


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
	std::cout << "\n\n";
}

void floatPerformanceTest(const std::vector<float>& values, int window)
{
	std::cout << "Float performance test with window = " << window << ":\n";
	Timer timer;
	timer.launch();

	calculateSimpleMovingAverage(values, window);

	double duration = timer.getDuration();
	std::cout << "\tResult time duration: " << duration << "s\n\n";
}

void doublePerformanceTest(const std::vector<double>& values, int window)
{
	std::cout << "Double performance test with window = " << window << ":\n";
	Timer timer;
	timer.launch();

	calculateSimpleMovingAverage(values, window);

	double duration = timer.getDuration();
	std::cout << "\tResult time duration: " << duration << "s\n\n";
}

int main()
{
	validityTest1();
	validityTest2();

	// Генерируем значения: 
	std::random_device seed;
	std::mt19937 gen{ seed() };
	std::uniform_real_distribution<> dist{ 1, 10 };

	std::vector<float> floatVect(1'000'000, 0.0);
	std::vector<double> doubleVect(1'000'000, 0.0);
	for (int i = 0; i < 1'000'000; ++i)
	{
		int randomNumber = dist(gen);
		floatVect[i] = randomNumber;
		doubleVect[i] = randomNumber;
	}

	std::array<int, 6> windowSizes{ 4, 8, 16, 32, 64, 128 };
	
	for (int i = 0; i < 6; ++i)
		floatPerformanceTest(floatVect, windowSizes[i]);
	std::cout << "\n";

	for (int i = 0; i < 6; ++i)
		doublePerformanceTest(doubleVect, windowSizes[i]);

	return 0;
}