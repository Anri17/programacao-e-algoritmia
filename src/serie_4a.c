#include "serie_4a.h"

#include <stdio.h>
#include <math.h>

#include "utility.h"

#define EX_3_MATRIX_SIZE 2

void formula_resolvente(float a, float b, float c, float *raiz_a, float *raiz_b);
float get_max(float *a, float *b);
char matrix_is_inverse(int matrix_a[EX_3_MATRIX_SIZE][EX_3_MATRIX_SIZE], int matrix_b[EX_3_MATRIX_SIZE][EX_3_MATRIX_SIZE]);


void serie_4a_ex_1();
void serie_4a_ex_2();
void serie_4a_ex_3();

void serie_4a_menu()
{
	int opcao;

	// procedimentos
	do
	{
		console_clear();
		print_statement(
			"Série de Problemas 4 A",
			"Insira o número de um dos exercícios, ou zero(0) para sair:\n\n"
			"  1 - Formula Resolvente\n"
			"  2 - Valor maximo usando ponteiros e funções\n"
			"  3 - Verificar se duas matrizes são inversas uma da outra\n"
			"  0 - Sair\n"
		);
		input_get_int_range(" Selecione uma opção: ", "ATENÇÃO: Esse exercício não existe...\n", &opcao, 0, 3);
		switch (opcao) {
			case 1: serie_4a_ex_1(); break;
			case 2: serie_4a_ex_2(); break;
			case 3: serie_4a_ex_3(); break;
		}
	} while (opcao != 0);
}


// Crie uma função que receba os coeficientes de um polinómio de 2º grau e o
// endereço de duas variáveis reais (raízes do polinómio). A função, com base nos
// três primeiros parâmetros, calcula as raízes do polinómio, as quais são impressas
// no écran, a partir do programa principal. 
void serie_4a_ex_1()
{
	// variáveis
	float coef_a, coef_b, coef_c;
	float raiz_a, raiz_b;

	// procedimentos
	console_clear();
	print_statement(
		"Série de Problemas 4 A - Exercício 1",
		"Crie uma função que receba os coeficientes de um polinómio de 2º grau e o\n"
		"endereço de duas variáveis reais (raízes do polinómio). A função, com base nos\n"
		"três primeiros parâmetros, calcula as raízes do polinómio, as quais são impressas\n"
		"no écran, a partir do programa principal.\n"
	);
	input_get_float("Introduza o coeficiente A: ", &coef_a);
	input_get_float("Introduza o coeficiente B: ", &coef_b);
	input_get_float("Introduza o coeficiente C: ", &coef_c);
	formula_resolvente(coef_a, coef_b, coef_c, &raiz_a, &raiz_b);
	printf("\n Raiz A: %.2f\n", raiz_a);
	printf(" Raiz B: %.2f\n\n", raiz_b);
	console_pause();
}

// Crie uma função que receba duas variáveis passadas por referência e devolva o
// maior dos dois valores
void serie_4a_ex_2()
{
	// variáveis
	float a, b, max;

	// procedimentos
	console_clear();
	print_statement(
		"Série de Problemas 4 A - Exercício 2",
		"Crie uma função que receba duas variáveis passadas por referência e devolva o\n"
		"maior dos dois valores\n"
	);
	printf("Introduza dois valores:\n");
	input_get_float(" A: ", &a);
	input_get_float(" B: ", &b);
	max = get_max(&a, &b);
	printf("\n O valor maximo é %.2f\n\n", max);
	console_pause();
}

// Crie uma função que recebe duas matrizes de inteiros, de dimensão 2x2 e o
// endereço de uma variável. A função devolve ‘S’ ou ‘N’, consoante uma das
// matrizes seja, ou não, a inversa da outra matriz. Na função principal deve ser
// impressa no écran a mensagem “As matrizes fornecidas são matrizes inversas
// uma da outra”, caso a função retorne ‘S’ e “As matrizes fornecidas não são
// matrizes inversas uma da outra”, caso a função retorne ‘N’.
// Nota: Uma matriz quadrada A diz-se invertível se e só se: A^-1 A = A A-1 = I, onde I
// é a matriz identidade
void serie_4a_ex_3()
{
	// variáveis
	int i, j;
	int matrix_a[EX_3_MATRIX_SIZE][EX_3_MATRIX_SIZE];
	int matrix_b[EX_3_MATRIX_SIZE][EX_3_MATRIX_SIZE];
	char char_inversa;

	// procedimentos
	console_clear();
	print_statement(
		"Série de Problemas 4 A - Exercício 1",
		"Crie uma função que recebe duas matrizes de inteiros, de dimensão 2x2 e o\n"
		"endereço de uma variável. A função devolve ‘S’ ou ‘N’, consoante uma das\n"
		"matrizes seja, ou não, a inversa da outra matriz. Na função principal deve ser\n"
		"impressa no écran a mensagem “As matrizes fornecidas são matrizes inversas\n"
		"uma da outra”, caso a função retorne ‘S’ e “As matrizes fornecidas não são\n"
		"matrizes inversas uma da outra”, caso a função retorne ‘N’.\n"
		"Nota: Uma matriz quadrada A diz-se invertível se e só se: A^-1 A = A A-1 = I, onde I\n"
		"é a matriz identidade\n"
	);
	printf("\nIntroduza os valores de uma matriz A\n");
	for (i = 0; i < EX_3_MATRIX_SIZE; ++i)
	{
		for (j = 0; j < EX_3_MATRIX_SIZE; ++j)
		{
			printf(" A%d%d> ", j+1, i+1);
			input_get_int("", &matrix_a[i][j]);
		}
	}
	printf("\nIntroduza os valores de uma matriz B\n");
	for (i = 0; i < EX_3_MATRIX_SIZE; ++i)
	{
		for (j = 0; j < EX_3_MATRIX_SIZE; ++j)
		{
			printf(" B%d%d> ", j+1, i+1);
			input_get_int("", &matrix_b[i][j]);
		}
	}
	printf("\nMatriz A:\n");
	print_matrix((int *)matrix_a, EX_3_MATRIX_SIZE, EX_3_MATRIX_SIZE);
	printf("\nMatriz B:\n");
	print_matrix((int *)matrix_b, EX_3_MATRIX_SIZE, EX_3_MATRIX_SIZE);
	
	char_inversa = matrix_is_inverse(matrix_a, matrix_b);


	switch (char_inversa)
	{
	case 'S':
		printf("As matrizes fornecidas são matrizes inversas uma da outra\n\n");
		break;
	case 'N':
		printf("As matrizes fornecidas não são matrizes inversas uma da outra\n\n");
		break;
	}
	console_pause();
}


void formula_resolvente(float a, float b, float c, float *raiz_a, float *raiz_b)
{
	float delta = sqrt(b*b - 4.0f*a*c);
	*raiz_a = ((-b + delta) / (2.0f * a));
	*raiz_b = ((-b - delta) / (2.0f * a));
}

float get_max(float *a, float *b)
{
	return *a > *b ? *a : *b;
}

char matrix_is_inverse(int matrix_a[EX_3_MATRIX_SIZE][EX_3_MATRIX_SIZE], int matrix_b[EX_3_MATRIX_SIZE][EX_3_MATRIX_SIZE])
{
	int i, j;
	int y, x;
	int resultado;
	for (i = 0; i < EX_3_MATRIX_SIZE; ++i)
	{
		for (j = 0; j < EX_3_MATRIX_SIZE; ++j)
		{
			resultado = 0;
			for (y = x = 0; y < EX_3_MATRIX_SIZE && x < EX_3_MATRIX_SIZE; ++x, ++y)
			{
				resultado += matrix_a[i][x] * matrix_b[y][j];
			}
			if (i == j && resultado != 1 ||
			    i != j && resultado != 0) return 'N';
		}
	}
	return 'S';
}