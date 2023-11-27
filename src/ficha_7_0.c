#include "ficha_7_0.h"

#include <stdio.h>

#include "utility.h"

#define PI 3.141592653f
#define FICHA_7_0_EX_3_SIZE 10
#define FICHA_7_0_EX_4_SIZE 11


void math_condence_minutes_to_hours(int minutos, int *out_horas, int *out_minutos)
{
	*out_horas = minutos/60;
    *out_minutos = (minutos % 60);
}

void math_radius_get_area_volume(float raio, float *area, float *volume)
{
	*area = PI * raio * raio;
	*volume = (4.0f * PI * raio * raio * raio) / 3.0;
}

void array_int_get_min_max(const int *arr, const int size, int *min, int *max)
{
	int i;
	*max = arr[i];
	*min = arr[i];
	for (i = 1; i < size; ++i)
	{
		if (arr[i] > *max) *max = arr[i];
		if (arr[i] < *min) *min = arr[i];
	}
}

void array_int_invert(int *arr, const int size)
{
	int i, temp;
	for (i = 0; i < size/2.0f; ++i)
	{
		temp = arr[i];
		arr[i] = arr[size-1-i];
		arr[size-1-i] = temp;
	}
}


// Crie uma função que receba um inteiro (minutos) e o endereço de duas variáveis
// inteiras (horas e minutos). A função, com base no primeiro parâmetro (exemplo:
// minutos = 75), calcula as horas e minutos (exemplo: 1 hora e 15 minutos).
void ficha_7_0_ex_1()
{
	int minutos_total;
	int horas;
	int minutos;
	
	console_clear();
	print_statement(
		"Ficha 7.0 - Exercício 1",
		"Crie uma função que receba um inteiro (minutos) e o endereço de duas variáveis\n"
		"inteiras (horas e minutos). A função, com base no primeiro parâmetro (exemplo:\n"
		"minutos = 75), calcula as horas e minutos (exemplo: 1 hora e 15 minutos).\n"
	);
	input_get_int_min("Introduza um numeros de minutos: ", "ATENÇÃO: O valor nao pode ser negativo.\n", &minutos_total, 1);
	math_condence_minutes_to_hours(minutos_total, &horas, &minutos);
	printf("%d minutos são %d horas e %d minutos.\n", minutos_total, horas, minutos);
	console_pause();
}


// Crie uma função que receba o raio de uma circunferência e o endereço de duas
// variáveis reais (área e volume). A função, com base no primeiros parâmetro,
// calcula a área do círculo circunscrito à circunferência (PI*r2) e o volume de uma
// esfera de raio dado ((4*PI*r3)/3).
void ficha_7_0_ex_2()
{
	float raio;
	float volume, area;

	console_clear();
	print_statement(
		"Ficha 7.0 - Exercício 2",
        "Crie uma função que receba o raio de uma circunferência e o endereço de duas\n"
        "variáveis reais (área e volume). A função, com base no primeiros parâmetro,\n"
        "calcula a área do círculo circunscrito à circunferência (PI*r2) e o volume de uma\n"
        "esfera de raio dado ((4*PI*r3)/3).\n"
	);
	input_get_float_min("Introduza o valor de um Raio: ", "ATENÇÃO: O valor tem que ser positivo.\n", &raio, 0.001);
	math_radius_get_area_volume(raio, &area, &volume);
	printf("A area de uma circumferencia de raio %.2% é %.2f.\n", raio, area);
	printf("O volume de uma circumferencia de raio %.2% é %.2f.\n", raio, volume);
	console_pause();
}


// Crie uma função que receba uma array de inteiros, o seu tamanho e o endereço
// de duas variáveis inteiras (max e min) e calcule o valor máximo e mínimo do
// array.
void ficha_7_0_ex_3()
{
	int arr[FICHA_7_0_EX_3_SIZE] = {
		1,2,3,4,5,6,7,8,9,10
	};
	int min, max;

	console_clear();
	print_statement(
		"Ficha 7.0 - Exercício 3",
		"Crie uma função que receba uma array de inteiros, o seu tamanho e o endereço\n"
		"de duas variáveis inteiras (max e min) e calcule o valor máximo e mínimo do\n"
		"array.\n"
	);
	array_int_get_min_max(arr, FICHA_7_0_EX_3_SIZE, &min, &max);
	printf("Min: %d\n", min);
	printf("Max: %d\n", max);
	console_pause();
}


// Crie uma função que receba um array de inteiros e o seu tamanho e inverta a
// ordem dos elementos.
void ficha_7_0_ex_4()
{
	int arr[FICHA_7_0_EX_4_SIZE] = {
		1,2,3,4,5,6,7,8,9,10,11
	};

	console_clear();
	print_statement(
		"Ficha 7.0 - Exercício 4",
		"Crie uma função que receba um array de inteiros e o seu tamanho e inverta a\n"
		"ordem dos elementos.\n"
	);
	printf("Array Original:\n");
	print_array_int(arr, FICHA_7_0_EX_4_SIZE);
	printf("\n");
	array_int_invert(arr, FICHA_7_0_EX_4_SIZE);
	printf("Array Invertido: \n");
	print_array_int(arr, FICHA_7_0_EX_4_SIZE);
	printf("\n");
	console_pause();
}


void ficha_7_0_menu()
{
    int opcao;

    do
    {
        console_clear();
		print_statement(
			"Ficha 7.0",
			"Insira o número de um dos exercícios, ou zero(0) para sair:\n\n"
			"  1 - \n"
			"  2 - \n"
			"  3 - Função para procurar os numeros minimos e maximos de um array\n"
			"  4 - Inverter array\n"
			"  0 - Sair\n"
		);
		input_get_int_range(" Selecione uma opção: ", "ATENÇÃO: Esse exercício não existe...\n", &opcao, 0, 4);
        printf("\n");
        switch (opcao)
        {
        case 1: ficha_7_0_ex_1(); break;
        case 2: ficha_7_0_ex_2(); break;
        case 3: ficha_7_0_ex_3(); break;
        case 4: ficha_7_0_ex_4(); break;
        }
    } while(opcao != 0);
}

