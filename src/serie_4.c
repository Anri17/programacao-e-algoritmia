#include "serie_4.h"


#include <stdio.h>

#include "utility.h"


void calcular_perimetro_area_quadrado(float comprimento, float *area, float *perimetro)
{
	*area = comprimento * comprimento;
	*perimetro = comprimento * 4;
}


// Crie uma função que receba o comprimento do lado de um quadrado e o
// endereço de duas variáveis reais (perímetro e área). A função, com base no
// primeiro parâmetro, calcula o perímetro e a área do quadrado.
void serie_4_ex_1()
{
	float comprimento;
	float perimetro, area;

	console_clear();
	print_statement(
		"Série de Problemas 4 - Exercício 1",
		"Crie uma função que receba o comprimento do lado de um quadrado e o\n"
		"endereço de duas variáveis reais (perímetro e área). A função, com base no\n"
		"primeiro parâmetro, calcula o perímetro e a área do quadrado.\n"
	);
	input_get_float_min("Introduza o comprimento do lado de um quadrado: ", "ATENÇÃO: O valor não pode ser negativo, ou demasiado curto\n", &comprimento, 0.0001f);
	calcular_perimetro_area_quadrado(comprimento, &area, &perimetro);
	printf("\n");
	printf(" A area do quadrado é %.2f\n", area);
	printf(" A perimetro do quadrado é %.2f\n\n", perimetro);
	console_pause();
}


// Crie uma função que efetue a troca dos valores de duas variáveis passadas por
// referência.
void serie_4_ex_2()
{
	// variáveis

	// procedimentos
	console_clear();
	print_statement(
		"Série de Problemas 4 - Exercício 2",
		"Crie uma função que efetue a troca dos valores de duas variáveis passadas por\n"
		"referência.\n"
	);
	


	
	console_pause();
}


// Crie uma função que recebe uma matriz de inteiros, de dimensão 4x4 e o
// endereço de uma variável. A função devolve ‘S’ ou ‘N’, consoante a matriz seja,
// ou não, uma matriz simétrica. Na função principal deve ser impressa no écran a
// mensagem “Matriz simétrica”, caso a função retorne ‘S’ e “Matriz não
// simétrica”, caso a função retorne ‘N’.
// Nota: Uma matriz A diz-se simétrica se e só se A = A^T.
void serie_4_ex_3()
{
	// variáveis

	// procedimentos
	console_clear();
	print_statement(
		"Série de Problemas 4 - Exercício 3",
		"Crie uma função que recebe uma matriz de inteiros, de dimensão 4x4 e o\n"
		"endereço de uma variável. A função devolve ‘S’ ou ‘N’, consoante a matriz seja,\n"
		"ou não, uma matriz simétrica. Na função principal deve ser impressa no écran a\n"
		"mensagem “Matriz simétrica”, caso a função retorne ‘S’ e “Matriz não\n"
		"simétrica”, caso a função retorne ‘N’.\n"
		"Nota: Uma matriz A diz-se simétrica se e só se A = A^T.\n"
	);



	
	console_pause();
}

void serie_4_menu()
{
	// variáveis
	int opcao;

	// procedimentos
	do
	{
		console_clear();
		print_statement(
			"Série de Problemas 4",
			"Insira o número de um dos exercícios, ou zero(0) para sair:\n\n"
			"  1 - Area e Perimetro de um quadrado, usando funções e endereços\n"
			"  2 - NÃO RESOLVIDO\n"
			"  3 - NÃO RESOLVIDO\n"
			"  0 - Sair\n"
		);
		input_get_int_range(" Selecione uma opção: ", "ATENÇÃO: Esse exercício não existe...\n", &opcao, 0, 3);
		switch (opcao)
		{
		case 1: serie_4_ex_1(); break;
		case 2: serie_4_ex_2(); break;
		case 3: serie_4_ex_3(); break;
		}
	} while (opcao != 0);
	
}