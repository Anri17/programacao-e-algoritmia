#include "ficha_3_0.h"

#include <stdio.h>
#include <stdlib.h>

#include "utility.h"

#define EX_4_NUM_PESSOAS 4
#define EX_4_STRING_SIZE 32
#define EX_5_NUM_COUNT 10
#define EX_6_NUM_PESSOAS 6

// --------------- Descricao ---------------
// Escrever um algoritmo que implica no ecran a soma
// dos primeiros 100 numeros inteiros positivos
void ficha_3_0_ex_1()
{
	int soma;
	int i;

    // Dizer o Propósito do Programa
    printf("Este programa vai imprimir a soma dos 100 primeiros numeros inteiro.\n\n");

	// Calcular a soma dos 100 primeiros numeros
    soma = 0;
	i = 1;
	while (i <= 100)
    {
		soma += i;
		++i;
    }

	// Imprimir resultado
	printf("  Soma dos 100 primeiros numeros positivos: %d\n", soma);
}


// --------------- Descricao ---------------
// Escrever um algoritmo que recebe por parte do
// utilizador um numero inteiro n e imprime no ecran
// o resultado da seguinte operacao:
//       S = 1/1 + 1/2 + 1/3 + 1/4 + ... + 1/n
void ficha_3_0_ex_2()
{
    int   num;
    int   i;
	float s;

	// Notificar ao utilizador as intrucoes de utilizado do programa
    printf("Este programa vai fazer a se guinte operação\n"
           "    S = 1/1 + 1/2 + 1/3 + 1/4 + … + 1/n\n"
           "sendo 'n' um numero inteiro positivo dado pelo utilizador.\n"
           "\n");
    
	// Pedir um numero ao utilizador
	input_get_int_min("Introduza o valor de 'n': ", "ATENÇÂO: 'n' tem que ser maior que 0.\n", &num, 1);

    // Calcular S e apresentar equacao e resultado
    s = 0;
	printf("\n");
    printf(" S = ");
    for (i = 1; i <= num; ++i)
    {
        // Imprimir parte da conta
        if (i == num)
        {
            printf("1/%d = ", i);
            if (!(i % 10))
            {
                printf("\n   = ");
            }
        }
        else
        {
            printf("1/%d + ", i);
            if (!(i % 10))
            {
                printf("\n   + ");
            }
        }

        // Fazer parte da conta
        s = 1.0f / i;
    }
    // Apresentar Resultado Final
    printf("%.5f\n", s);
}


// --------------- Descricao ---------------
// Escrever um algoritmo que calcule e imprima no ercan
// a tabuada de um numero inteiro positivo introduzido
// pelo utilizador
void ficha_3_0_ex_3()
{
    int num;
    int linhas;
	int resultado;
    int i;

	// Notificar ao utilizador as intrucoes de utilizado do programa
	printf("Este programa vai calcular e apresentar a tabuada de numero inteiro introduzido pelo utilizador.\n\n");

	// Solicitar o numero da tabuada ao utilizador
	input_get_int_min("Introduza o número da tabuada: ", "ATENÇÃO: O numero tem que ser inteiro positivo\n", &num, 1);
	input_get_int_min("Introduza quantas linhas para imprimir: ", "ATENÇÃO: O numero tem que ser inteiro positivo\n", &linhas, 1);
   
	// Calcular e apresentar a tabuada do numero introduzido
	printf("\n ----- Tabuada do %d -----\n\n", num);
    for (i = 1; i <= linhas; ++i)
    {
		// Fazer a conta
		resultado = i * num;
		// Imprimir a conta
        printf("%d * %d = %d\n", num, i, resultado);
    }
}


// --------------- Descricao ---------------
// Escrever um algoritmo que receba, por parte do
// utilizador, o nome, a idade, a altura e o peso de
// 10 pessoas e imprima no ecran:
//     a) A quantidade de pessoas com idade superior a
//        50 anos.
//     b) A media das alturas das pessoas com idades
//        compreendidas entre os 10 e os 20 anos.
//     c) A percentagem de pessoas com peso inferior
//        a 40 Kg, de entre todas as pessoas introduzidas
//     d) O nome, idade, altura e peso da pessoa mais
//        velha e da pessoa mais nova
void ficha_3_0_ex_4()
{
    struct Pessoa
    {
        char  nome[EX_4_STRING_SIZE];
        int   idade;
        int   altura;
        float peso;
    };

	struct Pessoa pessoas[EX_4_NUM_PESSOAS];
	struct Pessoa pessoa_velha;
	struct Pessoa pessoa_nova;

    int num_pessoas_superior_50_anos;

    float media_altura_pessoas_entre_10_20_anos;
	int   soma_altura_pessoas_entre_10_20_anos;
	int   num_pessoas_entre_10_20_anos;

	int   num_pessoas_peso_inferior_40kg;
	float percentagem_pessoas_peso_inferior_40kg;

    int i;


	// // Notificar ao utilizador as intrucoes de utilizado do programa
	printf("Este programa vai recolher a apresentar os dados de 10 pessoas, relativo aos peso, idade, nome e altura.\n\n");


    // Recolher dados das pessoas
    for (i = 0; i < EX_4_NUM_PESSOAS; ++i)
    {
        printf("Pessoa %d\n", i+1);
		input_get_string("  nome: ", pessoas[i].nome, EX_4_STRING_SIZE);
		input_get_int_min("  idade: ", "ATENÇÃO: A idade não pode ser negativa.\n", &pessoas[i].idade, 1);
		input_get_int_min("  altura (cm): ", "ATENÇÃO: A altura nao pode ser negativa.\n", &pessoas[i].altura, 1);
		input_get_float_min("  peso (kg): ", "ATENÇÃO: O peso nao pode ser negativo.\n", &pessoas[i].peso, 1);
    }


    // Contar o numero de pessoas com idade superior a 50
    num_pessoas_superior_50_anos = 0;
    for (i = 0; i < EX_4_NUM_PESSOAS; ++i)
    {
        if (pessoas[i].idade > 50) ++num_pessoas_superior_50_anos;
    }


    // Calcular a media das idades comprendida entre os 10 e 20 anos
	soma_altura_pessoas_entre_10_20_anos = 0;
	num_pessoas_entre_10_20_anos = 0;
	for (i = 0; i < EX_4_NUM_PESSOAS; ++i)
	{
		if (pessoas[i].idade >= 10 && pessoas[i].idade <= 20)
		{
			soma_altura_pessoas_entre_10_20_anos = soma_altura_pessoas_entre_10_20_anos + pessoas[i].altura;
			num_pessoas_entre_10_20_anos += 1; 
		}
	}
	if (num_pessoas_entre_10_20_anos > 0)
		media_altura_pessoas_entre_10_20_anos = (float)soma_altura_pessoas_entre_10_20_anos / (float)num_pessoas_entre_10_20_anos;
	else
		media_altura_pessoas_entre_10_20_anos = 0;


    // Calcular a percentagem de pessoas com peso inferior a
	// 40kg de todas as pessoas introduzidas
	for (i = 0; i < EX_4_NUM_PESSOAS; ++i)
	{
		if (pessoas[i].peso < 40) num_pessoas_peso_inferior_40kg += 1;
	}
	percentagem_pessoas_peso_inferior_40kg = num_pessoas_peso_inferior_40kg / (float)EX_4_NUM_PESSOAS;



	// Procurar pessoa mais velha e pessoa mais nova
	pessoa_velha.idade = pessoas[0].idade;
	pessoa_nova.idade = pessoas[0].idade;
	for (i = 0; i < EX_4_NUM_PESSOAS; ++i)
	{
		// Pessoa mais velha
		if (pessoa_velha.idade < pessoas[i].idade)
		{
			pessoa_velha = pessoas[i];
		}
		// Pessoa mais nova
		if (pessoa_nova.idade >= pessoas[i].idade)
		{
			pessoa_nova = pessoas[i];
		}
	}


    // Apresentar resultados
	printf("\n");
	printf("Número de pessoas com idade superior a 50: %d\n", num_pessoas_superior_50_anos);
	printf("Média da altura das pessoa entre os 10 e 20 anos: %.2f cm\n", media_altura_pessoas_entre_10_20_anos);
	printf("Percentagem de pessoas com peso inferior a 40kg e todas as pessoas introduzidas: %.2f%\n", percentagem_pessoas_peso_inferior_40kg * 100);
	printf("Pessoa mais velha:\n");
	printf("  Nome:   %s\n", pessoa_velha.nome);
	printf("  Idade:  %d anos\n", pessoa_velha.idade);
	printf("  Altura: %d cm\n", pessoa_velha.altura);
	printf("  Peso:   %.2f kg\n", pessoa_velha.peso);
	printf("Pessoa mais nova:\n");
	printf("  Nome:   %s\n", pessoa_nova.nome);
	printf("  Idade:  %d anos\n", pessoa_nova.idade);
	printf("  Altura: %d cm\n", pessoa_nova.altura);
	printf("  Peso:   %.2f kg\n", pessoa_nova.peso);
}


// --------------- Descricao ---------------
// Escrever um algoritmo que receba, por parte do
// utilizador, 10 numeros inteiros positios e imprima no
// ecran a quantidade de numeros entre 20 e 40.
void ficha_3_0_ex_5()
{
	int numeros[EX_5_NUM_COUNT];
	int i;
	int num_numeros_entre_20_40;


	// Notificar ao utilizador as intrucoes de utilizado do programa
	printf("Este programa vai aceitar do utilizador 10 numeros e apresentar quantos desses numeros são entre 20 e 40\n\n");


	// Solicitar os dados das pessoas
	for (i = 0; i < EX_5_NUM_COUNT; ++i)
	{
		do {
			printf(" Num %d: ", i+1);
			scanf("%d", &numeros[i]);
			if (!((numeros[i]) >= 1)) printf("ATENÇÃO: O numero tem que ser positivo.\n");
		} while (!((numeros[i]) >= 1));
	}


	// Contar os numeros entre 20 e 40
	num_numeros_entre_20_40 = 0;
	for (i = 0; i < EX_5_NUM_COUNT; ++i)
	{
		if (numeros[i] > 20 && numeros[i] < 40)
			num_numeros_entre_20_40++;
	}
	

	// Apresentar a conta dos numeros
	printf("\n");
	printf("Número de números entre 20 e 40: %d\n", num_numeros_entre_20_40);
}


// --------------- Descricao ---------------
// Escrever um algoritmo que receba como entradas a
// idade e o sexo de seis pessoas e imprima no ecran
//     a) A media das idades do grupo de pessoas
//        introduzido
//     b) A media das idades das pessoas do sexo
//        feminino
void ficha_3_0_ex_6()
{
	int   idade[EX_6_NUM_PESSOAS];
	char  sexo[EX_6_NUM_PESSOAS];
	int   i;
	int   soma_idade_total;
	float media_idade_total;

	int   soma_idade_sexo_feminino;
	int   num_idade_sexo_feminino;
	float media_idades_sexo_feminino;


	// Notificar ao utilizador as intrucoes de utilizado do programa
	printf("Este programa vai recolher a idade e o sexo de 6 pessoas e apresentar a media total das idades e a media da idade das pessoas do sexo feminino.\n\n");


	// Solicitar os dados das pessoas
	for (i = 0; i < EX_6_NUM_PESSOAS; ++i)
	{
		printf("Pessoa %d\n", i+1);
		input_get_int_min(" idade: ", "ATENÇÃO: A idade tem que ser positiva\n", &idade[i], 1);
		input_get_char_constraint(" sexo (F/M): ", "ATENÇÃO: Caractére inválido.\n", "fmFM", &sexo[i]);
	}


	// Calcular media das idades
	soma_idade_total = 0;
	for (i = 0; i < EX_6_NUM_PESSOAS; ++i)
	{
		soma_idade_total = soma_idade_total + idade[i];
	}
	media_idade_total = soma_idade_total / (float)EX_6_NUM_PESSOAS;


	// Calcular media das idades das pessoas do sexo Feminino
	soma_idade_sexo_feminino = 0;
	num_idade_sexo_feminino  = 0;
	for (i = 0; i < EX_6_NUM_PESSOAS; ++i)
	{
		if (sexo[i] == 'F' || sexo[i] == 'f')
		{
			soma_idade_sexo_feminino = soma_idade_sexo_feminino + idade[i];
			num_idade_sexo_feminino  = num_idade_sexo_feminino + 1;
		}
	}
	
	if (num_idade_sexo_feminino > 0)
		media_idades_sexo_feminino = soma_idade_sexo_feminino / num_idade_sexo_feminino;
	else
		media_idades_sexo_feminino = 0;


	// Apresentar a conta dos numeros
	printf("\n");
	printf("Media Total das Idades: %.2f\n", media_idade_total);
	printf("Media das Idades das pessoas do sexo feminino: %.2f\n", media_idades_sexo_feminino);
}

enum
{
    SAIR = 0,
    FICHA_3_1 = 1,
    FICHA_3_2 = 2,
    FICHA_3_3 = 3,
    FICHA_3_4 = 4,
    FICHA_3_5 = 5,
    FICHA_3_6 = 6
};

// Menu da Ficha 3.0
void ficha_3_0_menu()
{
    int opcao;

	do
	{
		printf("Resolução da ficha 3\n"
			"\n"
			"  1 - Imprimir 100 numeros inteiros\n"
			"  2 - Imprimir operação S = 1/1 + 1/2 + ... + 1/n\n"
			"  3 - Imprimir tabuada de um número\n"
			"  4 - Dados sobre Pessoas\n"
			"  5 - Numeros entre 20 e 40\n"
			"  6 - Média das idades\n"
			"  0 - Sair\n"
			"\n"
			"Selecione uma ficha: ");
		scanf("%d", &opcao);

		switch(opcao)
		{
		case FICHA_3_1: ficha_3_0_ex_1(); break;
		case FICHA_3_2: ficha_3_0_ex_2(); break;
		case FICHA_3_3: ficha_3_0_ex_3(); break;
		case FICHA_3_4: ficha_3_0_ex_4(); break;
		case FICHA_3_5: ficha_3_0_ex_5(); break;
		case FICHA_3_6: ficha_3_0_ex_6(); break;
		case SAIR: break;
		default: break;
		}
	}
	while (opcao != SAIR);
}