#include "ficha_1_0.h"

#include <stdio.h>

#include "utility.h"

int fatorial(int n)
{
    int out = 1;
    for (size_t i = 1; i <=n; ++i)
    {
        out *= i;
    }
    return out;
}

void ficha_1_0_ex_1()
{
    printf("Olá Mundo!\n");
}

void ficha_1_0_ex_2()
{
    int num1;
    int num2;
    int produto;

    // Get input
    printf("Introduza dois numeros inteiros\n");
    printf("Num1: ");
    scanf("%d", &num1);
    printf("Num2: ");
    scanf("%d", &num2);

    // Calculate
    produto = num1 * num2;

    // Output
    printf("  %d * %d = %d\n", num1, num2, produto);
}

void ficha_1_0_ex_3()
{
    float num1, num2, num3;
    float media;

    printf("Escreva tres valores para calcular a média\n");
    printf("num1: ");
    scanf("%f", &num1);
    printf("num2: ");
    scanf("%f", &num2);
    printf("num3: ");
    scanf("%f", &num3);

    media = (num1 + num2 + num3) / 3.0;

    printf("A média é: %10.2f", media);
    printf("Fatura\n\n");
}

void ficha_1_0_ex_4()
{
    int n   = 4;
    int fat = fatorial(n);

    printf("O Fatorial de %d é %d\n", n, fat);
}

void ficha_1_0_ex_5()
{
	int num1 , num2;
    float resultado;

    printf("Escreva dois numeros para ser divido um pelo outro\n");
    printf("numero 1:");
    scanf("%d", &num1);
    printf("numero 2:");
    scanf("%d", &num2);
    resultado = (float)num1 / (float)num2;
    printf("A divisao e: %f" , resultado);
}

void ficha_1_0_menu()
{
    int opcao;

    do
    {
        console_clear();
        printf("\n\n ####### Ficha 1.0 #######\n\n");
        printf("Bem vind@ à Ficha 1.0.\nInsira o número de um dos exercícios, ou zero(0) para sair.\n\n");
        printf("  1 - Olá Mundo\n");
        printf("  2 - Produto de dois numeros\n");
        printf("  3 - Média de três valores\n");
        printf("  4 - Fatorial de 4\n");
        printf("  5 - Divisao de dois numeros\n");
        printf("  0 - Sair\n\n");

        do
        {
            printf(" Selecione uma opção: ");
            scanf("%d", &opcao);

            if (!(opcao >= 0 && opcao <= 5))
            {
                printf("ATENÇÃO: Esse exercício não existem...\n");
            }
        } while (!(opcao >= 0 && opcao <= 5));

        printf("\n");
        switch (opcao)
        {
        case 1:
            console_clear();
            printf("\n\n ####### Ex 1 #######\n\n");
            ficha_1_0_ex_1();
            printf("\n ##### Fim Ex 1 #####\n\n");
            console_pause();
            break;
        case 2:
            printf("\n\n ####### Ex 2 #######\n\n");
            ficha_1_0_ex_2();
            printf("\n ##### Fim Ex 2 #####\n\n");
            break;
        case 3:
            printf("\n\n ####### Ex 3 #######\n\n");
            ficha_1_0_ex_3();
            printf("\n ##### Fim Ex 3 #####\n\n");
            break;
        case 4:
            printf("\n\n ####### Ex 4 #######\n\n");
            ficha_1_0_ex_4();
            printf("\n ##### Fim Ex 4 #####\n\n");
            break;
        case 5:
            printf("\n\n ####### Ex 5 #######\n\n");
            ficha_1_0_ex_5();
            printf("\n ##### Fim Ex 5 #####\n\n");
            break;
        case 0:
            printf("\nObrigado por usar este programa.\n");
            break;
        default:
            break;
        }
    } while(opcao != 0);

    printf("\n ##### Fim Ficha 1.0 #####\n\n");
	console_pause();
}
