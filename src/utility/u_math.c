#include "u_math.h"


float math_average_arr_int(const int *arr, const int size)
{
	int i;
	int sum;
	float average;
	sum = 0;
	i = 0;
	while (i < size)
	{
		sum += *(arr+i);
		++i;
	}
	average = sum / (float)size;
	return average;
}
