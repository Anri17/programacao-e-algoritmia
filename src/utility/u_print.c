#include "u_print.h"

#include <stdio.h>

void print_matrix(const int * matrix, const int rows, const int columns)
{
	int i, j;
	for (i = 0; i < rows; ++i)
	{
		for (j = 0; j < columns; ++j)
		{
			if (j == columns-1)
				printf("%d\n", *(matrix + i*columns + j));
			else
				printf("%d, ", *(matrix + i*columns + j));
		}
	}
}

void print_statement(const char *title, const char* body)
{
	printf("\t\t - %s -\n", title);
	printf("\n");
	printf(body);
	printf("\n");
}

void print_array_int(const int *arr, const int size)
{
	int i;
	for (i = 0; i < size; ++i)
	{
		if (i+1 == size) printf("%d", arr[i]);
		else printf("%d, ", arr[i]);
	}
}
