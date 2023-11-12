#include "ficha_3_1.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "utility.h"

// --------------- Descrição ---------------
// Escrever um algoritmo para ler a quantidade de hora
// de trabalho de dois professores e o valor por hora
// recebido por cada um. Mostrar no ecran qual dos
// professores tem o maior vencimento total.
void ficha_3_1_ex_1()
{
    // Variáveis
    float professor1_horas_trabalho;
    float professor2_horas_trabalho;

    float professor1_eur_hora;
    float professor2_eur_hora;

    float professor1_vencimento_total;
    float professor2_vencimento_total;

    // Notificar ao utilizador as intrucoes de utilizado do programa
    printf("Este programa vai recolher as hora de trabalho e o valor por hora\n");
    printf("de dois professores e apresentar o que tem maior vencimento\n");
    printf("total.\n\n");

    // Solicitar os dados
    // prof 1
    printf("Professor 1\n");
    do {
        printf(" Horas de Trabalho (H): ");
        scanf("%f", &professor1_horas_trabalho);
        if (professor1_horas_trabalho <= 0) printf("ATENÇÃO: O numero de horas nao pode ser menor ou igual a 0.\n");
    } while (professor1_horas_trabalho <= 0);
    do {
        printf(" Vencimento por Hora (EUR): ");
        scanf("%f", &professor1_eur_hora);
        if (professor1_eur_hora <= 0) printf("ATENÇÃO: O vencimento por hora nao pode ser menor ou igual a 0.\n");
    } while (professor1_eur_hora <= 0);

   // prof 2
   printf("Professor 2\n");
    do {
        printf(" Horas de Trabalho (H): ");
        scanf("%f", &professor2_horas_trabalho);
        if (professor2_horas_trabalho <= 0) printf("ATENÇÃO: O numero de horas nao pode ser menor ou igual a 0.\n");
    } while (professor2_horas_trabalho <= 0);
    do {
        printf(" Vencimento por Hora (EUR): ");
        scanf("%f", &professor2_eur_hora);
        if (professor2_eur_hora <= 0) printf("ATENÇÃO: O vencimento por hora nao pode ser menor ou igual a 0.\n");
    } while (professor2_eur_hora <= 0);

    // Calcular o maior vencimento total
    professor1_vencimento_total = professor1_horas_trabalho * professor1_eur_hora;
    professor2_vencimento_total = professor2_horas_trabalho * professor2_eur_hora;


    // Apresentar Dados
    printf("\nVencimento Total do Professor 1: %.2f EUR/H\n", professor1_vencimento_total);
    printf("\nVencimento Total do Professor 2: %.2f EUR/H\n", professor2_vencimento_total);
    printf("\n");
    if (professor1_vencimento_total > professor2_vencimento_total)
        printf("O primeiro professor tem um vencimento maior que o segundo professor, com uma diferenca de %.2f EUR\n", (professor1_vencimento_total - professor2_vencimento_total));
    else if (professor1_vencimento_total < professor2_vencimento_total)
        printf("O segundo professor tem um vencimento maior que o primeiro professor, com uma diferenca de %.2f EUR\n", (professor2_vencimento_total - professor1_vencimento_total));
    else
        printf("Ambos os dois professores tem o mesmo vencimento total.");
}

// --------------- Descrição ---------------
// Escrever um algoritmo que determine o maior entre N
// numeros. A condicao de paragem e a entrada do valor 0,
// ou seja, o algoritmo deve processar o maior ate que a
// entrada seja igual a 0 (ZERO)
void ficha_3_1_ex_2()
{
    // Variáveis
    float numero;
    float maior;
    int contagem;


    // Inicializar variaveis
    maior    =  0; // o maior dos numeros introduzidos
    contagem =  0; // contar o numero de entradas do utilizador

    // Notificar ao utilizador as intrucoes de utilizado do programa
    printf("Este programa vai solicitar ao utilizador N numero\n");
    printf(" e determinar o maior deles. O programa para se solicitar\n");
    printf(" novas entrada quando o numero introduzido for 0 (ZERO).\n\n");

    // Solicitar os dados
    printf("Introduza uma lista de numeros.\n");
    printf("Insira 0 (ZERO) para acabar a introducao dos numero.\n");
    do {
        contagem = contagem + 1;
        printf(" %d> ", contagem);
        scanf("%f", &numero);
        if (numero > maior)
            maior = numero;
    } while (!(numero == 0));

    contagem = contagem - 1; // o ultimo que e 0 nao conta porque foi o comando de saida

    // Apresentar o maior numero
    printf("\nDos %d valores introduzidos (não contando o numero zero de saida), o maior numero foi %.2f.\n", contagem, maior);
}

// --------------- Descrição ---------------
// Escrever um algoritmo que determine o fatorial de um
// numero inteiro positivo fornecido como entrada.
// O algoritmo deve verificar se o numero introduzido
// pelo utilizador e inteiro positivo e, caso nao seja,
// escrever a mensagem "O numero introduzido nao e
// inteiro positivo. Introduza novo numero".
void ficha_3_1_ex_3()
{
    // Variáveis
    int num;
    int index;
    int fat;

    // Notificar ao utilizador as intrucoes de utilizado do programa
    printf("Este programa vai calcular o fatorial de um numero inserido pelo utilizador.\n\n");

    // Solicitar os dados
    do {
    printf("Introduza um numero: ");
    scanf("%d", &num);
    } while (num <= 0);

    // Calcular Fatorial
    index = 1;
    fat = 1;
    while (index <= num)
    {
        fat = fat * index;
        index = index + 1;
    }

    // Apresentar o resultado
    printf("\n\nO fatorial de %d é %d.\n", num, fat);
}

// --------------- Descrição ---------------
// Escrever um algoritmo que determine a soma dos numero
// impares pertencentes a um intervalo fornecido como
// entrada
void ficha_3_1_ex_4()
{
    // Variáveis
    float intervalo_min;
    float intervalo_max;
    int soma;
    int index;

    // Notificar ao utilizador as intrucoes de utilizado do programa
    printf("Este programa vai somar os numeros impares dentro de um intevalo introduzido pelo utilizador, e apresentar o resultado\n\n");

    // Solicitar os dados
    printf("Introduza o limite minino: ");
    scanf("%f", &intervalo_min);
    do {
        printf("Introduza o limite maximo: ");
        scanf("%f", &intervalo_max);
        if (intervalo_max <= intervalo_min) printf("ATENÇÃO: O intervalo máximo não pode ser menor ou igual ao intervalo mínimo.\n");
    } while (intervalo_max <= intervalo_min);

    // arrendondar para o proximo numero inteiro impar
    // (isto e porque o programa aceita numeros reais, mas o numero impares
    // e consecutiva soma sao inteiros)
    index = (int)intervalo_min;
    if (index < intervalo_min) // o numero inteiro convertido tem que estar dentro do intervalo
        index = index + 1;
    if ((index % 2) == 0) // caso seja par
        index = index + 1;

    // Somar numeros impares
    soma  = 0;
    while (index <= intervalo_max)
    {
        soma = soma + index;
        index = index + 2;
    }

    // Apresentar o resultado
   printf("\n\nA soma dos numeros impares dentro do intervalo %.2f - %.2f é %d.\n", intervalo_min, intervalo_max, soma);
}

// --------------- Descrição ---------------
// Escrever um algoritmo que receba como entradas as
// medidas dos 3 lados de um triangulo e, para alem de
// verificar se o triangulo e valido, devolva como saida
// a sua classificacao quanto aos lados.
// nota: Um triangulo so e valido o comprimento de cada
// um dos seus lados for menos que a soma dos outros dois.
// triangulo equilatro: 3 lados iguais;
// triangulo isosceles: 2 lados iguais;
// triangulo escaleno: 3 lados diferentes;
void ficha_3_1_ex_5()
{
    // Variáveis
    float medida_lado_a;
    float medida_lado_b;
    float medida_lado_c;

    // caracteristicas
    bool triangulo_valido;
    bool triangulo_equilatero;
    bool triangulo_isosceles;
    bool triangulo_escaleno;

    // Inicializar variaveis
    medida_lado_a = 0;
    medida_lado_b = 0;
    medida_lado_c = 0;

    triangulo_valido = false;
    triangulo_equilatero = false;
    triangulo_isosceles = false;
    triangulo_escaleno = false;

    // Notificar ao utilizador as intrucoes de utilizado do programa
    printf("Este programa vai informar as caracteristicas de um triangulo, soliciantdo a medidas do seus tres lados, indicando inclusive se este e valido ou nao.\n\n");

    // Solicitar os dados
    printf("Introduza as medidas dos tres lados de um triangulo.\n");
    while (medida_lado_a <= 0)// lado a
    {
        printf(" lado a: ");
        scanf("%f", &medida_lado_a);
        if (medida_lado_a <= 0)
            printf("A medida do lado tem que ser maior que 0.\n");
    }

    while (medida_lado_b <= 0) // lado b
    {
        printf(" lado b: ");
        scanf("%f", &medida_lado_b);
        if (medida_lado_b <= 0)
            printf("A medida do lado tem que ser maior que 0.\n");
    }

    while (medida_lado_c <= 0) // lado c
    {
        printf(" lado c: ");
        scanf("%f", &medida_lado_c);
        if (medida_lado_c <= 0)
            printf("A medida do lado tem que ser maior que 0.\n");
    }

    // Analizar as caracteristicas do triangulo
    triangulo_valido = (medida_lado_a < (medida_lado_b + medida_lado_c)) && (medida_lado_b < (medida_lado_a + medida_lado_c)) && (medida_lado_c < (medida_lado_a + medida_lado_b));
    if (triangulo_valido)
    {
        triangulo_equilatero = (medida_lado_a == medida_lado_b) && (medida_lado_b == medida_lado_c);
        if (!triangulo_equilatero)
        {
            triangulo_isosceles = (medida_lado_a == medida_lado_b) || (medida_lado_b == medida_lado_c) || (medida_lado_a == medida_lado_c);
            if (!triangulo_isosceles)
                triangulo_escaleno = true;
        }
    }


    // Apresentar o resultado
    printf("\n");
    if (triangulo_valido)
    {
            printf("O triângulo é válido e é um triângulo ");
        if (triangulo_equilatero)
            printf("equilatero.\n");
        if (triangulo_isosceles)
            printf("isosceles.\n");
        if (triangulo_escaleno)
            printf("escaleno.\n");
    }
    else
        printf("O triangulo nao e valido.\n");
}

// --------------- Descrição ---------------
// O Artur tem 1,50 metros e cresce 2 centimetros por
// ano, enquanto que a Alice tem 1,10 metros e cresce
// 3 centimetros por ano. Construa um algoritmo
// (pseudocodigo) que calcule e imprima quantos anos
// serao necessarios para que a Alice seja maior que o
// Artur.
void ficha_3_1_ex_6()
{
    // Variáveis
    float altura_artur;
    float altura_alice;

    float crescimento_artur;
    float crescimento_alice;

    int ano;


    // Inicializar variaveis
    altura_artur = 1.50; // metros
    altura_alice = 1.10; // metros

    crescimento_artur = 0.02; // metros/ano
    crescimento_alice = 0.03; // metros/ano

    ano = 0; // anos ate a alice ser maior que o artur


    // Notificar ao utilizador as intrucoes de utilizado do programa
    printf("Este programa vai informar quantos anos serao necessarios para que a Alice seja maior que o Artur, estando pre-definida a altura inicial do Artur e da Alice, e o crescimento anual de cada um.\n\n");

    printf("Altura\n");
    printf(" Artur: %.2f metros\n", altura_artur);
    printf(" Alice: %.2f metros\n", altura_alice);
    printf("\n");
    printf("Crescimento Anual:\n");
    printf(" Artur: +%.2f metros/ano\n", crescimento_artur);
    printf(" Alice: +%.2f metros/ano\n", crescimento_alice);


    // Contar quantos ano ate a alice ser maior que o artur
    while (altura_alice < altura_artur)
    {
        altura_alice = altura_alice + crescimento_alice;
        altura_artur = altura_artur + crescimento_artur;
        ano = ano + 1;
    }


   // Apresentar o resultado
   printf("\nPara que a Alice seja maior que o Artur,\nserão necessários %d anos, tendo\n", ano);
   printf("a Alice uma altura de %.2f metros e \n", altura_alice);
   printf("o Artur uma altura de %.2f metros.\n", altura_artur);
}

// --------------- Descrição ---------------
// Escrever um algoritmo que determine se um numero e
// primo.
// Nota: Um numero e primo se for apenas divisivel por
// si proprio e pela unidade, por exemplo: 1 e um numero
// primo (visto que e apenas divisivel por 11 e por 1),
// enquanto que 21 nao e primo, pois tem os seguintes
// divisores: 1, 3, 7 e 21.
// Escrever um algoritmo que determine o aluno melhor
// classificado e a media de uma turma.
void ficha_3_1_ex_7()
{
    // Variáveis
    int num;
    int index;
    bool e_primo;

    // Inicializar variaveis
    e_primo = true;

    // Notificar ao utilizador as intrucoes de utilizado do programa
    printf("Este programa consegue identificar se um numero introduzido e primo ou nao.\n\n");

    // Solicitar um numero
    do {
        printf("Introduza um numero: ");
        scanf("%d", &num);
        if (num <= 0) printf("ATENÇÃO: O numero tem que ser inteiro positivo.\n");
    } while (num <= 0);

    // Descobrir que o numero e primo
    if (num == 1)
        e_primo = false;
    else
    {
        index = (int)(num / 2.0f); // um numero nunca e divisivel por um outro que seja maior que a sua metade
        while ((e_primo) && (index > 0))
        {
            if (!(index == num) && !(index == 1))
                e_primo = !((num % index) == 0);
            index = index - 1;
        }
    }

    // Apresentar o resultado
    printf("\n");
    if (e_primo)
        printf("O numero é primo.\n");
    else
    printf("O numero não é primo.\n");
}

// --------------- Descrição ---------------
// Escrever um algoritmo que le uma sequencia de numeros
// inteiros terminada pelo numero zero e calcula o maior
// numero par e a sua posicao na sequencia de valores.
void ficha_3_1_ex_8()
{
    // Variáveis
    int num;
    int max_par;
    int max_pos;

    int conta_insercoes;

    // Inicializar variaveis
    conta_insercoes = 0;

    max_par = 0;
    max_pos = 0;

    // Notificar ao utilizador as intrucoes de utilizado do programa
    printf("Este programa vai apresentar o maior numero par de uma sequencia de numeros fornecisa pelo utilizador, sendo 0 (ZERO) o ultimo numero da sequencia.\n\n");

    // Contar quantos ano ate a alice ser maior que o artur
    num = -1;
    while (!(num == 0))
    {
        conta_insercoes = conta_insercoes + 1;
        printf(" %d> ", conta_insercoes);
        scanf("%d", &num);

        if ((num % 2 == 0) && (num > max_par))
        {
            max_par = num;
            max_pos = conta_insercoes;
        }
    }

    // Apresentar o resultado
    printf("\nO maior numero par introduzido foi %d na posicao %d da sequencia de valores.\n", max_par, max_pos);
}

// --------------- Descrição ---------------
// Escrever um algoritmo que devolva o maximo divisor
// comum (MDC) entre dois numeros positivos.
void ficha_3_1_ex_9()
{
    // Variáveis
    int num_a;
    int num_b;

    int min;
    int mdc;

    // Notificar ao utilizador as intrucoes de utilizado do programa
    printf("Este program vai apresentar o maximo divisor comum de dois numeros introduzidos.\n\n");

    // Solicitar numeros
    printf("Introduza dois numeros positivos\n");
    do {
        printf(" num a: ");
        scanf("%d", &num_a);
        if (num_a <= 0) printf("ATENÇÃO: O numero tem que ser maior que 0.");
    } while (num_a <= 0);

    do {
        printf(" num b: ");
        scanf("%d", &num_b);
        if (num_b <= 0) printf("ATENÇÃO: O numero tem que ser maior que 0.");
    } while (num_b <= 0);

    // procurar o mais pequeno dos dois
    if (num_a > num_b)
        min = num_b;
    else
        min = num_a;

    // Definir maximo divisor comum
    mdc = min;
    while (!(((num_a % mdc) == 0) && ((num_b % mdc) == 0)))
        mdc = mdc -1;

   // Apresentar o resultado
   printf("\nO maximo divisor comum é %d\n", mdc);
}

// --------------- Descrição ---------------
// Escrever um algoritmo que imprima os numero de 1 ate 30
// de 2 em 2.
void ficha_3_1_ex_10()
{
    // Variáveis
    int index;
    int max;


    // Notificar ao utilizador as intrucoes de utilizado do programa
    printf("Este program vai imprimir os numeros de 1 ate 30, de 2 em 2.\n\n");


    // Escrever o numeros de 1 a 30, de 2 em 2
    index = 1;
    max = 30;
    while (index <= max)
    {
        printf(" %d", index);
        index = index + 2;
    }
}

void ficha_3_1_menu()
{
    int opcao;

    do
    {
        printf("\n\n ####### Ficha 3.1 #######\n\n");
        printf("Bem vindo à Ficha 3.1.\nInsira o número de um dos exercícios, ou zero(0) para sair.\n\n");
        printf("  1 - Vencimento à hora de dois professores\n");
        printf("  2 - Procura do maior número de uma lista de números\n");
        printf("  3 - Fatorial de um Número\n");
        printf("  4 - Soma dos números impares dentro de um intervalo de números\n");
        printf("  5 - Análise de Triângulos\n");
        printf("  6 - Altura da Alice e do Artur\n");
        printf("  7 - Analizar se um número é primo\n");
        printf("  8 - Maior numero Par de uma sequência de números\n");
        printf("  9 - Maior Divisor Comum de Dois números Positivos\n");
        printf(" 10 - Imprimir os numeros entre 1 e 30, de 2 em 2\n");
        printf("  0 - Sair\n\n");

        do
        {
            printf(" Selecione uma opção: ");
            scanf("%d", &opcao);

            if (!(opcao >= 0 && opcao <= 10))
            {
                printf("ATENÇÃO: Esse exercício não existem...\n");
            }
        } while (!(opcao >= 0 && opcao <= 10));

        printf("\n");
        switch (opcao)
        {
        case 1:
            printf("\n\n ####### Ex 1 #######\n\n");
            ficha_3_1_ex_1();
            printf("\n ##### Fim Ex 1 #####\n\n");
            break;
        case 2:
            printf("\n\n ####### Ex 2 #######\n\n");
            ficha_3_1_ex_2();
            printf("\n ##### Fim Ex 2 #####\n\n");
            break;
        case 3:
            printf("\n\n ####### Ex 3 #######\n\n");
            ficha_3_1_ex_3();
            printf("\n ##### Fim Ex 3 #####\n\n");
            break;
        case 4:
            printf("\n\n ####### Ex 4 #######\n\n");
            ficha_3_1_ex_4();
            printf("\n ##### Fim Ex 4 #####\n\n");
            break;
        case 5:
            printf("\n\n ####### Ex 5 #######\n\n");
            ficha_3_1_ex_5();
            printf("\n ##### Fim Ex 5 #####\n\n");
            break;
        case 6:
            printf("\n\n ####### Ex 6 #######\n\n");
            ficha_3_1_ex_6();
            printf("\n ##### Fim Ex 6 #####\n\n");
            break;
        case 7:
            printf("\n\n ####### Ex 7 #######\n\n");
            ficha_3_1_ex_7();
            printf("\n ##### Fim Ex 7 #####\n\n");
            break;
        case 8:
            printf("\n\n ####### Ex 8 #######\n\n");
            ficha_3_1_ex_8();
            printf("\n ##### Fim Ex 8 #####\n\n");
            break;
        case 9:
            printf("\n\n ####### Ex 9 #######\n\n");
            ficha_3_1_ex_9();
            printf("\n ##### Fim Ex 9 #####\n\n");
            break;
        case 10:
            printf("\n\n ####### Ex 10 ######\n\n");
            ficha_3_1_ex_10();
            printf("\n ##### Fim Ex 10 ####\n\n");
            break;
        case 0:
            printf("\nObrigado por usar este programa.\n");
            break;
        default:
            break;
        }
    } while(opcao != 0);

    printf("\n ##### Fim Ficha 3.1 #####\n\n");
}