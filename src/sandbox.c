#include "sandbox.h"

#include <stdio.h>

#include "utility.h"


#include "ficha_7_0.h"

#define ROWS 3
#define COLUMNS 4
#define SIZE 10

void sandbox()
{
	console_clear();

	int i, j;
	int matrix[ROWS][COLUMNS];
	int arr[SIZE] = { 1,2,3,4,5,6,7,8,9,10 };
	float average;


	ficha_7_0_ex_1();
	
	average = math_average_arr_int(arr, SIZE);

	for (i = 0; i < ROWS; ++i)
	{
		for (j = 0; j < COLUMNS; ++j)
		{
			matrix[i][j] = i*COLUMNS+j;
		}
	}

	print_matrix((int*)matrix, ROWS, COLUMNS);

	console_pause();
}