#include "ficha_4_0.h"

#include <stdio.h>
#include <string.h>
#include "utility.h"

#define FICHA_4_0_STRING_SIZE 255

// --------------- Descrição ---------------
// Escrever um algoritmo que simule uma calculadora
// basica de numeros inteiros, recorrendo a:
//
//      a. Estruturas de decisao compostas
//      b. Estruturas de decisao multiplas
void ficha_4_0_ex_1()
{
    int operacao;
    int num1;
    int num2;
    int resultado;
    // Notificar ao utilizador as intrucoes de utilizado do programa

    printf("-----------------------------------\n"
           "|Escreva um valor inteiro:        |\n"
           "|                                 |\n"
           "| 1 - Soma                        |\n"
           "| 2 - Subtracao                   |\n"
           "|                                 |\n"
           "-----------------------------------\n");


    // Solicitar numeros
    input_get_int_range("Escolha a operacao desejada: ", "ATENÇÃO: O numero tem que ser entre 1 e 2\n", &operacao, 1, 2);



    // Fazer operacoes
    switch (operacao)
    {
    case 1:
        printf("Digita a sua soma: \n");
        input_get_int("Insira o valor desejado num1: ", &num1);
        input_get_int("Insira o valor desejado num2: ", &num2);
        
        resultado = num1 + num2;
        break;
    case 2:
        printf("Digita a sua subtracao: \n");
        input_get_int("Insira o valor desejado num1: ", &num1);
        input_get_int("Insira o valor desejado num2: ", &num2);

        resultado = num1 - num2;
        break;
    }

    // Apresentar o resultado
    printf("O seu resultado e %d\n", resultado);
}

// --------------- Descrição ---------------
// Um determinado club de futebol pretende classificar
// os seus atletas em categorias, tendo para isso
// contratado um programador para criar um programa
// que executasse esta tarefa. Foi criada uma tabela
// abaixo com a faixa etaria do atleta e correspondente
// categoria.
// 
//         IDADE   |   CATEGORIA
//      De 05 a 10 |   Infantil
//      De 11 a 15 |    Juvenil
//      De 16 a 20 |    Junior
//      De 21 a 25 |  Profissional
// 
// Construa um algoritmo que solicite o nome e a idade
// de um atleta e imprima a sua categoria.
void ficha_4_0_ex_2()
{
    char nome[FICHA_4_0_STRING_SIZE];
    char categoria[FICHA_4_0_STRING_SIZE];
    int  idade;
    
    // Notificar ao utilizador as intrucoes de utilizado do programa
    printf("Escreva o seu nome e a sua idade para saber a sua categoria\n\n");
    input_get_string("Digite o seu nome: ", nome, FICHA_4_0_STRING_SIZE);
    input_get_int_min("Digite a sua idade: ", "ATENÇÂO: A idade não pode ser menor que 0", &idade, 0);
    

    if ((idade >= 5) && (idade <= 10))
        strcpy(categoria, "Infantil");
    if ((idade >= 11) && (idade <= 15))
        strcpy(categoria, "Juvenil");
    if ((idade >= 16) && (idade <= 20))
        strcpy(categoria, "Junior");
    if ((idade >= 21) && (idade <= 25))
        strcpy(categoria, "Profissional");
    if ((idade < 5) && (idade > 25))
        strcpy(categoria, "Nao definida");
   
    printf("A sua categoria é %s\n", categoria);
}

// --------------- Descricao ---------------
// Faca um programa que receba o valor de uma venda,
// escolha a forma de pagamento no menu e mostre o total
// da venda final conforme as condicoes a seguir:
//    Venda a pronto - desconto de 10%
//    Venda a Prazo 30 dias - desconto de 5%
//    Venda a prazo 60 dias - mesmo preco
//    Venda a prazo 90 dias - acrescimo de 5%
//    Venda com cartao de debito - desconto de 8%
//    Venda com cartao de credito - desconto de 7%
void ficha_4_0_ex_3()
{
    int tipo_venda; // 1 - pronto, 2 - prazo 30 dias, 3 - prazo 60 dias, 4 - prazo 90 dias, 5 - cartao de debito, 6 - cartao de crédito
    float valor_venda;
    float novo_preco;

    
    printf("Tipos de venda:\n"
           " 1 - Venda a pronto - desconto de 10%\n"
           " 2 - Venda a Prazo 30 dias - desconto de 5%\n"
           " 3 - Venda a prazo 60 dias - mesmo preco\n"
           " 4 - Venda a prazo 90 dias - acrescimo de 5%\n"
           " 5 - Venda com cartao de debito - desconto de 8%\n"
           " 6 - Venda com cartao de credito - desconto de 7%\n"
           "\n");

    input_get_float_min("Indique o valor da venda (EUR): ", "ATENÇÂO: O valor nao pode ser menor que 0\n", &valor_venda, 0.0f);
    input_get_int_range("Indique o tipo de venda: ", "ATENÇÂO: O valor tem que ser entre 1 e 6\n", &tipo_venda, 1, 6);

    printf("\n");
    switch (tipo_venda)
    {
    case 1: // Venda a pronto - desconto de 10%
        novo_preco = valor_venda - (valor_venda * 0.10f);
        break;
    case 2: // Venda a Prazo 30 dias - desconto de 5%
        novo_preco = valor_venda - (valor_venda * 0.05f);
        break;
    case 3: // Venda a prazo 60 dias - mesmo preco
        novo_preco = valor_venda;
        break;
    case 4: // Venda a prazo 90 dias - acrescimo de 5%
        novo_preco = valor_venda + (valor_venda + 0.05f);
        break;
    case 5: // Venda com cartao de debito - desconto de 8%
        novo_preco = valor_venda - (valor_venda * 0.08f);
        break;
    case 6: // Venda com cartao de credito - desconto de 7%
        novo_preco = valor_venda - (valor_venda * 0.07f);
        break;
    }

    printf("Novo Preco: %.2f EUR\n", novo_preco);
}

void ficha_4_0_menu()
{
    int opcao;

    do
    {
        printf("\n\n ####### Ficha 4.0 #######\n\n");
        printf("Bem vindo à Ficha 4.0.\nInsira o número de um dos exercícios, ou zero(0) para sair.\n\n");
        printf("  1 - Calculadora Basica\n");
        printf("  2 - Clube de Futebol\n");
        printf("  3 - Vendas e Descontos\n");
        printf("  0 - Sair\n\n");

        do
        {
            printf(" Selecione uma opção: ");
            scanf("%d", &opcao);

            if (!(opcao >= 0 && opcao <= 10))
            {
                printf("ATENÇÃO: Esse exercício não existem...\n");
            }
        } while (!(opcao >= 0 && opcao <= 3));

        printf("\n");
        switch (opcao)
        {
        case 1:
            printf("\n\n ####### Ex 1 #######\n\n");
            ficha_4_0_ex_1();
            printf("\n ##### Fim Ex 1 #####\n\n");
            break;
        case 2:
            printf("\n\n ####### Ex 2 #######\n\n");
            ficha_4_0_ex_2();
            printf("\n ##### Fim Ex 2 #####\n\n");
            break;
        case 3:
            printf("\n\n ####### Ex 3 #######\n\n");
            ficha_4_0_ex_3();
            printf("\n ##### Fim Ex 3 #####\n\n");
            break;
        case 0:
            printf("\nObrigado por usar este programa.\n");
            break;
        default:
            break;
        }
    } while(opcao != 0);

    printf("\n ##### Fim Ficha 4.0 #####\n\n");
}