#include "movingAverage.h"
#include <vector>
#include <iostream>


int main()
{
	// ������������� ��������
	// � ������� ������� �������� ����������� ��������
	std::vector<float> example{ 1, 2, 3, 4 };
	constexpr int window = 4;

	auto result = calculateSimpleMovingAverage(example, window);

	for (auto value : result)
	{
		std::cout << value << "\n";
	}

	return 0;
}