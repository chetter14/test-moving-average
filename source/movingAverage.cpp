#include "movingAverage.h"
#include <vector>


template<typename T>
void calculateSimpleMovingAverage(const std::vector<T>& values)
{
	// ����������� �������� �����
}

// ������ ���������� ������� � ��������� float � double �����
template void calculateSimpleMovingAverage<float>(const std::vector<float>&);
template void calculateSimpleMovingAverage<double>(const std::vector<double>&);