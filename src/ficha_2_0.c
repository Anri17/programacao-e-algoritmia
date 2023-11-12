#include "ficha_2_0.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

enum
{
    SAIR      = 0,
    FICHA_2_1 = 1,
    FICHA_2_2 = 2,
    FICHA_2_3 = 3,
    FICHA_2_4 = 4,
    FICHA_2_5 = 5,
};

void ficha_2_0_menu()
{
    // Declaração de Variáveis
    int   opcao;
    // Declarar Variáveis Ficha 2_1
    float num1;
    float num2;
    float max;
    float double_max;
    // Declarar Variáveis Ficha 2_2
    float teste1;
    float teste2;
    float media;
    int   aprovado;
    float NOTA_APROVACAO;
    // Declarar Variáveis Ficha 2_3
    float num;
    // Declarar Variáveis Ficha 2_4
    int f4_num;
    int absolute;
    // Declarar Variáveis Ficha 2_5
    float exponent;
    float power;

	do
	{
		
	
		// Menu
		opcao = 0;
		printf("Resolusão da fica de trabalho 2\n"
			"\n"
			"  1 - Dobro do maior numero\n"
			"  2 - Classificação final de uma UI\n"
			"  3 - Número maior, menor ou igual a zero\n"
			"  4 - Valor absoluto de um numero\n"
			"  5 - Potências de dois\n"
			"  0 - Sair\n"
			"\n"
			"Escolha a sua opção: ");
		scanf("%d", &opcao);
		printf("\n");

		switch (opcao)
		{
		case FICHA_2_1:
			// Receber Entradas do Utilizador
			printf("   ### FICHA 2.1 ###\n"
				"Introduza dois Numeros\n");
			printf(" num1: ");
			scanf("%f", &num1);
			printf(" num2: ");
			scanf("%f", &num2);

			// Encontrar o máximo dos dois numeros
			if (num1 > num2)
				max = num1;
			else
				max = num2;

			// Calcular o Dobro do Máximo
			double_max = max * 2;

			// Apresentar Resultado
			printf("\n"
				"O maior numero é %.2f.\n"
				"O dobro de %.2f é %.2f.\n", max, max, double_max);
			break;
		case FICHA_2_2:
			// Definir constantes
			NOTA_APROVACAO = 9.5f;

			// Receber Entradas do Utilizador
			printf("Introduza a nota de dois testes.\n");
			do
			{
				printf(" Teste 1: ");
				scanf("%f", &teste1);
				if (teste1 < 0 || teste1 > 20.0f)
				{
					printf("ERRO: A nota do teste tem que ser entre 0 e 20.\n");
				}
			} while (teste1 < 0 || teste1 > 20.0f);
			do
			{
				printf(" Teste 2: ");
				scanf("%f", &teste2);
				if (teste2 < 0 || teste2 > 20.0f)
				{
					printf("ERRO: A nota do teste tem que ser entre 0 e 20.\n");
				}
			} while (teste2 < 0 || teste2 > 20.0f);

			// Calcular Media
			media = (teste1 + teste2) / 2.0f;

			// Verificar se esta aprovado
			aprovado = media >= NOTA_APROVACAO ? 1 : 0;

			// Apresentar Resulado
			if (aprovado)
			{
				printf("\n"
					"Está aprovado com média de %.2f.\n", media);
			}
			else if (!aprovado)
			{
				printf("\n"
					"Não está aprovado com média de %.2f.\n", media);
			}
			break;
		case FICHA_2_3:
			// Get User Input
			printf("Introduza um Numero: ");
			scanf("%f", &num);

			// Apresentar Resulado
			if (num == 0)
			{
				printf("O número introduzido é igual a zero!\n");
			}
			break;
		case FICHA_2_4:
			// Get User Input
			printf("Introduza um Numero: ");
			scanf("%d", &f4_num);

			absolute = f4_num > 0 ? f4_num : -f4_num;

			printf("O módulo de %d é %d.", f4_num, absolute);
			break;
		case FICHA_2_5:
			// Get User Input
			do
			{
				printf("Introduza um Numero para expoente: ");
				scanf("%f", &exponent);

				if (!(exponent >= -1 && exponent <= 2))
				{
					printf("ERRO: O expoente deve ser entre -1 e 2.\n");
				}
			} while (!(exponent >= -1 && exponent <= 2));


			// Calculate Power
			power = pow(2, exponent);

			// Display Value
			printf("\n"
				"2^%.2f = %.2f.\n", exponent, power);
			break;
		case SAIR:

			break;
		default:

			break;
		}

	} while (opcao != SAIR);
}
