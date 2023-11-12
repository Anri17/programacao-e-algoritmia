#include "ficha_2_1.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

// ---------------- Descrição ----------------
// Receba como entrada o nome de um produto, o seu preco
// unitario e a quantidade comprada. Escreva no ecran o
// nome do produto comprado e o valor total a ser pago,
// considerando que e aplicado um desconto a custo total
// de acordo com o numero de unidades adquiridas, segundo
// a informacao a seguir apresentada.
//     a. Ate 10 unidade: valor total
//     b. De 11 a 20 unidades: 10% de desconto
//     c. De 21 a 50 unidades: 20% de desconto
//     d. Acima de 50 unidades: 25% de desconto
void ficha_2_1_ex_1()
{
    // Declaração de Variáveisl
    // Produto
    char produto_nome[50];
    float produto_preco_unitario;

    // Compra
    int compra_quantidade;
    float compra_desconto_percentagem;
    float compra_desconto_valor;
    float compra_preco_total; // quantidade * preco_unitario
    float compra_preco_final; // desconto aplicado

    // Adquirir Dados Produto
    printf("Introduza os dados do produto.\n");
    printf("  Nome: ");
    scanf("%s", produto_nome);

    do {
        printf("  Preco Unitario: ");
        scanf("%f", &produto_preco_unitario);
        if (produto_preco_unitario <= 0) printf("ATENÇÃO: O preço unitário tem que ser positivo.\n");
    } while (produto_preco_unitario <= 0);

    // Adquirir Dados de Compra
    printf("\n");
    printf("Quandas unidades deseja comprar?\n");

    do {
        printf("  Quantidade: ");
        scanf("%d", &compra_quantidade);
        if (compra_quantidade <= 0) printf("ATENÇÃO: A quantidade de compra tem que ser positiva.\n");
    } while (compra_quantidade <= 0);

    // Calcular desconto
    if (compra_quantidade <= 10)
    {
        compra_desconto_percentagem = 0.0f; // 0%
    }
    else if ((compra_quantidade >= 11) && (compra_quantidade <= 20))
    {
        compra_desconto_percentagem = 0.10; // 10%
    }
    else if ((compra_quantidade >= 21) && (compra_quantidade <= 50))
    {
        compra_desconto_percentagem = 0.20f; // 20%
    }
    else
    {
        compra_desconto_percentagem = 0.25f; // 25%
    }

    // Calcular Preco Final
    compra_preco_total = produto_preco_unitario * compra_quantidade;
    compra_desconto_valor = compra_preco_total * compra_desconto_percentagem;
    compra_preco_final = compra_preco_total - compra_desconto_valor;

    // Apresentar Resultados
    // TODO: Apresentar Dados de outra Forma
    printf("\n");
    printf("   DADOS DE COMPRA\n");
    printf("Quantidade:      %d\n", compra_quantidade);
    printf("Produto:         %s\n", produto_nome);
    printf("Preco Unitario:  %.2f EUR\n", produto_preco_unitario);
    printf("Preco Total:     %.2f EUR\n", compra_preco_total);
    printf("Desconto:        %.2f %\n", (compra_desconto_percentagem*100));
    printf("Valor Desconto: -%.2f EUR\n", compra_desconto_valor);
    printf("Preco Final:     %.2f EUR\n", compra_preco_final);
}

// ---------------- Descrição ------------------
// Determinar e escrever no ecran o numero de digitos de
// um numero inteiro, fornecido pelo utilizador:
// Nota:
// Numero_Digitos(N) = parte_integral(log10(|N|))+X,
// sendo:
// - N o numero inteiro fornecido pelo utilizador
// - X = 1, se log10(|N|) for decimal;
// X =, se log10(|N|) for inteiro
void ficha_2_1_ex_2()
{
    // Declaração de Variáveisl
    int input_num;
    int num;
    int num_digitos;

    // Notificar o utilizador do proposito do programa
    printf("Este programa vai analizar um numero que for introduzido e notificar o numero de digitos que esse numero e constituido.\n");

    // Solicitar ao utilizador a introducao de um numero
    printf("\n");
    printf("Introduza um numero inteiro: ");
    scanf("%d", &input_num);

    // Obter o modulo do numero
    if (input_num < 0)
    {
        num = -input_num;
    }
    else
    {
        num =  input_num;
    }

    // Obter o numero de digitos do numero introduzido
    num_digitos = (int)(log10(num)) + 1;

    // Notificar ao Utilizador o numero de digitos do numero introduzido
    printf("\n");
    if (num_digitos == 1)
        printf("O numero %d e constituido por %d digito\n", input_num, num_digitos);
    else
        printf("O numero %d e constituido por %d digitos\n", input_num, num_digitos);

}

// --------------- Descrição ---------------
// Receba como entrada  três valores e os escreva no
// escran por ordem crescente
void ficha_2_1_ex_3()
{
    // Declaração de Variáveisl
    int num1;
    int num2;
    int num3;

    // Notificar o utilizador do proposito do programa
    printf("Este programa vai solicitar ao utilizador tres numeros e apresentalos por orgem crescente no ecran.\n");
    printf("\n");

    // Solicitar ao utilizador 3 numeros
    printf("Introduza tres valores\n");
    printf("Num1: ");
    scanf("%d", &num1);
    printf("Num2: ");
    scanf("%d", &num2);
    printf("Num3: ");
    scanf("%d", &num3);

    // Apresentar os numeros por ordem crescente
    if ((num1 <= num2) && (num2 <= num3))
    {
        printf("%d\n", num1);
        printf("%d\n", num2);
        printf("%d\n", num3);
    }
    else if ((num1 <= num3) && (num3 <= num2))
    {
        printf("%d\n", num1);
        printf("%d\n", num3);
        printf("%d\n", num2);
    }
    else if ((num2 <= num1) && (num1 <= num3))
    {
        printf("%d\n", num2);
        printf("%d\n", num1);
        printf("%d\n", num3);
    }
    else if ((num2 <= num3) && (num3 <= num1))
    {
        printf("%d\n", num2);
        printf("%d\n", num3);
        printf("%d\n", num1);
    }
    else if ((num3 <= num1) && (num1 <= num2))
    {
        printf("%d\n", num3);
        printf("%d\n", num1);
        printf("%d\n", num2);
    }
    else if ((num3 <= num2) && (num2 <= num1))
    {
        printf("%d\n", num3);
        printf("%d\n", num2);
        printf("%d\n", num1);
    }
}

// --------------- Descrição ---------------
// Para determinada conta bancaria, o utilizador deve
// fornecer o seu numero, o seu saldo, o tipo de
// operacao. Determinar e escrever o valor do saldo
// apos a operacao. Se o saldo final for negativo,
// deve ser fornecida ao utilizador a informacao "conta
// sem provimento"
void ficha_2_1_ex_4()
{
    // Declaração de Variáveisl
    // conta bancaria
    int conta_numero;
    float conta_saldo;

    int OPERACAO_LEVANTAR;
    int OPERACAO_DEPOSITAR;
    int OPERACAO_SAIR;
    int operacao; // valor dado pelo utilizador

    float operacao_saldo_novo;
    float operacao_valor;
    bool sair_do_programa;

    // Inicializar Variaveis
    sair_do_programa = false;
    operacao_saldo_novo = 0;



    // Notificar ao utilizador as instrucoes de utilizacao do programa
    printf("Este programa simula uma conta bancaria solicitando um numero e valor inicial, e inclui opcoes para levantar e depositar dinheiro.\n");
    printf("\n");

    // Solicitar ao utilizador os valores da conta bancaria
    printf("Introduza os dados da sua conta bancaria.\n");
    printf("\n");


    printf("   Numero de Conta Bancaria (Numero Inteiro): ");
    scanf("%d", &conta_numero);

    printf("   Saldo Inicial (EUR): ");
    scanf("%f", &conta_saldo);
    printf("\n\n\n");


    // Iniciar Programa Principal
    do
    {
        // Mostrar ao utilizador os dados da conta
        printf("   --- Dados da Conta ---\n");
        printf("Numero da conta Bancaria: %d\n", conta_numero);
        printf("Saldo:                    %.2f EUR\n", conta_saldo);
        printf("\n");

        if (conta_saldo < 0)
        {
            printf("Conta sem provimento.\n");
            printf("\n");
        }

        // Solicitar os utilizador a operacao bancaria que deseja efetual
        printf("Introduza a operacao que deseje efetuar:\n");
        printf("\n");
        printf("   1 - Levantar\n");
        printf("   2 - Depositar\n");
        printf("   0 - Sair\n");
        printf("\n");
        printf("Operacao: ");
        scanf("%d", &operacao);
        printf("\n");

        // Escolher a operacao em funcao do valor introduzido pelo utilizador
        switch (operacao)
        {
        case 1: // LEVANTAR
            do {
                printf("Introduza o valor que deseja levantar (EUR): ");
                scanf("%f", &operacao_valor);
                if (operacao_valor <= 0) printf("ATENÇÃO: O valor tem que ser positivo.\n");
            } while (operacao_valor <= 0);
            operacao_saldo_novo = conta_saldo - operacao_valor;
            printf("\n\n");
            printf(" Efetuando o Levantamento...\n");
            printf("Novo Saldo:\n\n");
            printf("%.2f EUR - %.2f EUR   -->  %.2f EUR\n\n\n\n", conta_saldo, operacao_valor, operacao_saldo_novo);
            conta_saldo = operacao_saldo_novo;
            break;
        case 2: // DEPOSITAR
            do {
                printf("Introduza o valor que deseja depositar (EUR): ");
                scanf("%f", &operacao_valor);
                if (operacao_valor <= 0) printf("ATENÇÃO: O valor tem que ser positivo.\n");
            } while (operacao_valor <= 0);
            operacao_saldo_novo = conta_saldo + operacao_valor;
            printf("\n\n");
            printf(" Efetuando o Deposito...\n\n");
            printf("Novo Saldo:\n");
            printf("%.2f EUR + %.2f EUR   -->  %.2f EUR\n\n\n\n", conta_saldo, operacao_valor, operacao_saldo_novo);
            conta_saldo = operacao_saldo_novo;
            break;
        case 0: // SAIR
            printf("Obrigado e tenha um bom dia.\n\n");
            sair_do_programa = true;
            break;
        default:
            printf("\n");
            printf("Operacao Desconhecida...\n\n\n");
            break;
        }
    } while (!sair_do_programa);
}

// --------------- Descrição ---------------
// Receba tres numeros distintos e escreva no ecran
// o menor deles
void ficha_2_1_ex_5()
{
    // Declaração de Variáveisl
    int num1;
    int num2;
    int num3;
    int min;

    // Notificar o utilizador do proposito do programa
    printf("Este programa vai solicitar ao utilizador tres numeros inteiros e apresentar o menor deles no ecran.\n\n");

    // Solicitar ao utilizador 3 numeros
    printf("Introduza tres numeros inteiros.\n");
    printf("Num1: ");
    scanf("%d", &num1);
    printf("Num2: ");
    scanf("%d", &num2);
    printf("Num3: ");
    scanf("%d", &num3);

    // Descobrir o numero mais pequeno os numeros por ordem crescent
    if (((num1 <= num2) && (num2 <= num3)) || ((num1 <= num3) && (num3 <= num2)))
        min = num1;
    else if (((num2 <= num1) && (num1 <= num3)) || ((num2 <= num3) && (num3 <= num1)))
        min = num2;
    else if (((num3 <= num1) && (num1 <= num2)) || ((num3 <= num2) && (num2 <= num1)))
        min = num3;

    // Apresentar o numero mais pequeno
    printf("\n\nO Número mais pequeno é %d\n", min);
}

// Menu da Ficha 2.1
void ficha_2_1_menu()
{
    int opcao;

    do
    {
        printf("\n\n ####### Ficha 2.1 #######\n\n");
        printf("Bem vind@ à Ficha 2.1.\nInsira o número de um dos exercícios, ou zero(0) para sair.\n\n");
        printf("  1 - Compra de um produto com desconto em função da sua quantidade\n");
        printf("  2 - Conta dos algarismos de um número\n");
        printf("  3 - Organização por ordem crescente de três números\n");
        printf("  4 - Conta Bancária\n");
        printf("  5 - Mínimo de três números\n");
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
            ficha_2_1_ex_1();
            printf("\n ##### Fim Ex 1 #####\n\n");
            break;
        case 2:
            printf("\n\n ####### Ex 2 #######\n\n");
            ficha_2_1_ex_2();
            printf("\n ##### Fim Ex 2 #####\n\n");
            break;
        case 3:
            printf("\n\n ####### Ex 3 #######\n\n");
            ficha_2_1_ex_3();
            printf("\n ##### Fim Ex 3 #####\n\n");
            break;
        case 4:
            printf("\n\n ####### Ex 4 #######\n\n");
            ficha_2_1_ex_4();
            printf("\n ##### Fim Ex 4 #####\n\n");
            break;
        case 5:
            printf("\n\n ####### Ex 5 #######\n\n");
            ficha_2_1_ex_5();
            printf("\n ##### Fim Ex 5 #####\n\n");
            break;
        case 0:
            printf("\nObrigado por usar este programa.\n");
            break;
        default:
            break;
        }
    } while(opcao != 0);

    printf("\n ##### Fim Ficha 2.1 #####\n\n");
}
