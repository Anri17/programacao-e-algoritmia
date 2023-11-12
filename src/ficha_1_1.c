#include "ficha_1_1.h"

#include <stdio.h>
#include <stdlib.h>

#include "utility.h"

// --------------- Descrição ---------------
// Calcular a area e o perimetro de um retangulo, sendo o
// seu comprimento e a sua largura valores fornecidos
// pelo utilizador.
void ficha_1_1_ex_1()
{
    // Variáveis
    float largura;
    float altura;
    float perimetro;
    float area;

    // Notificar o utilizador do proposito do programa
    printf("Este programa vai calcular a area e o perimetro de um retangulo, dada a sua largura e altura.\n\n");

    // Solicitar ao utilizador que introduza os dados do retangulo
    printf("Introduza os dados do retangulo.\n");
    printf("Largura: ");
    scanf("%f", &largura);
    printf("Altura:  ");
    scanf("%f", &altura);

    // Calcular o perimetro e a area do retangulo
    perimetro = (largura * 2.0f) + (altura * 2.0f);
    area = largura * altura;

    // Notificar ao utilizador o resultado das contas
    printf("\n");
    printf("Perimetro: %.2f\n", perimetro);
    printf("Area:      %.2f\n", area);
}

// --------------- Descri;\ao -----------------
// Calcular a soma, subtracao, multiplicacao e divisao de
// dois numeros fornecidos pelo utilizador.
void ficha_1_1_ex_2()
{
    // Variáveis
    float num1;
    float num2;
    float soma;
    float subtracao;
    float multiplicacao;
    float divisao;

    // Notificar o utilizador do proposito do programa
    printf("Este programa vai calcular a apresentar a soma, subtracao, multiplicacao e divisao de dois numero introduzidos.\n\n");

    // Solicitar ao utilizador que introduza dois numeros
    printf("Introduza dois numeros.\n");
    printf("Num1: ");
    scanf("%f", &num1);
    printf("Num2: ");
    scanf("%f", &num2);

    // Calcular a soma, subtracao, multiplicacao e divisao
    soma          = num1 + num2;
    subtracao     = num1 - num2;
    multiplicacao = num1 * num2;
    divisao       = num1 / num2;

    // Notificar ao utilizador o resultado das contas
    printf("\n");
    printf("soma:          %.2f + %.2f = %.2f\n", num1, num2, soma);
    printf("subtracao:     %.2f - %.2f = %.2f\n", num1, num2, subtracao);
    printf("multiplicacao: %.2f * %.2f = %.2f\n", num1, num2, multiplicacao);
    printf("divisao:       %.2f / %.2f = %.2f\n", num1, num2, divisao);
}

// --------------- Descrição ----------------
// Ler dois valores numericos forneceidos pelo utilizador
// para as variaveis A e B, e fetuar a troca dos valores
// de forma a que a variavel passe a ter o valor da
// variavel B e a variavel B passe a ter o valor da
// variavel A. Apresentar os valores trocados.
void ficha_1_1_ex_3()
{
    // Variáveis
    float A;
    float B;
    float temp;

    // Notificar o utilizador do proposito do programa
    printf("Este programa vai receber dois numeros, A e B, e depois vai trocar esses dois valores.\n\n");

    // Soliciar ao utilizador que introduza dois numeros
    printf("Introduza dois numeros.\n");
    printf("A: ");
    scanf("%f", &A);
    printf("B: ");
    scanf("%f", &B);

    // Fazer a troca dos valores
    temp = A;
    A = B;
    B = temp;

    // Notificar ao utilizador o resultado da troca dos numeros
    printf("\n");
    printf("Valores trocados:\n");
    printf("A: %.2f\n", A);
    printf("B: %.2f\n", B);
}

// --------------- Descrição ----------------
// Receba o preco de custo de um produto e informe o
// utilizador do valor de venda correspondente, sendo
// que: o valor de venda obtem-se acrescendo ao valor de
// custo uma percentagem fornecida pelo utilizador.
void ficha_1_1_ex_4()
{
    // Variáveis
    float preco_custo;
    float valor_venda;
    float valor_acrescido;
    float valor_acrescido_percentagem;

    // Notificar ao utilizador o proposito do programa
    printf("Este programa vai calcular o valor de venda de um produto, dado o respetivo preco de custo e percentagem do valor acrescido.\n\n");

    // Solicitar ao utilizador que introduza os dados relacionados ao produto
    printf("Introduza os dados do produto.\n");
    printf("Preco de custo (EUR): ");
    scanf("%f", &preco_custo);
    printf("Valor acrescido (%):  ");
    scanf("%f", &valor_acrescido_percentagem);

    // Calcular o valor acrescido e valor final de venda do produto
    valor_acrescido = preco_custo * valor_acrescido_percentagem / 100.0f;
    valor_venda = preco_custo + valor_acrescido;

    // Notificar o utilizador dos dados do produto e seu respetivo valor final de venda
    printf("\n");
    printf("Preco de custo            ->   %6.2f EUR\n", preco_custo);
    printf("Valor acrescido (%6.2f%) -> + %6.2f EUR\n", valor_acrescido_percentagem, valor_acrescido);
    printf("-----------------------------------------------------\n");
    printf("Valor final de venda:          %6.2f EUR\n", valor_venda);
}

// --------------- Descrição ----------------
// Receba, por parte do utilizador, o valor da velocidade
// de um veiculo em km/h e devolva o valor correspondente
// em m/s
void ficha_1_1_ex_5()
{
    // Variáveis
    float kilometros_hora;
    float metros_segundo;

    // Notificar ao utilizador o proposito do programa
    printf(" - Conversor de velocidade -\n\n");
    printf("Este program vai converter a velocidade de um veiculo de km/h para m/s.\n\n");
    printf("Legenda:\n");
    printf("   km/h -> Quilometros por Hora\n");
    printf("   m/s  -> Metros por Segundo\n\n");

    // Solicitar ao utilizador que introduza a velocidade em km/h
    printf("Introduza a velocidade do seu veiculo em km/h: ");
    scanf("%f", &kilometros_hora);

    // Calcular a velocidade de km/h para m/s
    metros_segundo = kilometros_hora * 1000 / 3600;

    // Notificar ao utilizador o valor convertido
    printf("\n");
    printf("   %.2f km/h -> %.2f m/s\n", kilometros_hora, metros_segundo);
}

void ficha_1_1_menu()
{
    int opcao;

    do
    {
        console_clear();
        printf("\n\n ####### Ficha 1.1 #######\n\n");
        printf("Bem vind@ à Ficha 1.1.\nInsira o número de um dos exercícios, ou zero(0) para sair.\n\n");
        printf("  1 - Area e Perímetro de um Retângulo\n");
        printf("  2 - Soma, Subtração, Multiplicação e Divisão de Dois Números\n");
        printf("  3 - Troca de valores entre duas variáveis A e B\n");
        printf("  4 - Valor de Venda de um Produto\n");
        printf("  5 - Conversor de km/h para m/s\n");
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
            printf("\n\n ####### Ex 1 #######\n\n");
            ficha_1_1_ex_1();
            printf("\n ##### Fim Ex 1 #####\n\n");
            break;
        case 2:
            printf("\n\n ####### Ex 2 #######\n\n");
            ficha_1_1_ex_2();
            printf("\n ##### Fim Ex 2 #####\n\n");
            break;
        case 3:
            printf("\n\n ####### Ex 3 #######\n\n");
            ficha_1_1_ex_3();
            printf("\n ##### Fim Ex 3 #####\n\n");
            break;
        case 4:
            printf("\n\n ####### Ex 4 #######\n\n");
            ficha_1_1_ex_4();
            printf("\n ##### Fim Ex 4 #####\n\n");
            break;
        case 5:
            printf("\n\n ####### Ex 5 #######\n\n");
            ficha_1_1_ex_5();
            printf("\n ##### Fim Ex 5 #####\n\n");
            break;
        case 0:
            printf("\nObrigado por usar este programa.\n");
            break;
        default:
            break;
        }
    } while(opcao != 0);

    printf("\n ##### Fim Ficha 1.1 #####\n\n");

    console_pause();
}