#include "fichas.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utility.h"
#include "sandbox.h"

#define FICHAS_STRING_SIZE 255

void fichas_menu()
{
    char opcao[FICHAS_STRING_SIZE];
    do
    {
        console_clear();
        print_statement(
            "Programação e Algoritmia",
            "Bem vind@. Estas são as fichas do curso de Programação e Algoritmia.\n"
            "Insira o número de uma ficha (ex.: 1.1, 4.0), ou zero(0) para sair.\n"
            "  sandbox - sandbox program\n"
            "\n"
            "  1.0     - Ficha 1.0\n"
            "  1.1     - Ficha 1.1\n"
            "  2.0     - Ficha 2.0\n"
            "  2.1     - Ficha 2.1\n"
            "  3.0     - Ficha 3.0\n"
            "  3.1     - Ficha 3.1\n"
            "  4.0     - Ficha 4.0\n"
            "  6.0     - Ficha 6.0\n"
            "  7.0     - Ficha 7.0\n"
            "  serie4  - Série de Problemas nº4\n"
            "  serie4a - Série de Problemas nº4 A\n"
            "  frec1   - Frequência 1\n"
            "  0   - Sair\n"
        );
        input_get_string(" Selecione uma opção: ", opcao, FICHAS_STRING_SIZE);
        printf("\n");
        if (!strcmp(opcao, "sandbox")) sandbox();
        else if (!strcmp(opcao, "1.0")) ficha_1_0_menu();
        else if (!strcmp(opcao, "1.1")) ficha_1_1_menu();
        else if (!strcmp(opcao, "2.0")) ficha_2_0_menu();
        else if (!strcmp(opcao, "2.1")) ficha_2_1_menu();
        else if (!strcmp(opcao, "3.0")) ficha_3_0_menu();
        else if (!strcmp(opcao, "3.1")) ficha_3_1_menu();
        else if (!strcmp(opcao, "4.0")) ficha_4_0_menu();
        else if (!strcmp(opcao, "6.0")) ficha_6_0_menu();
        else if (!strcmp(opcao, "7.0")) ficha_7_0_menu();
        else if (!strcmp(opcao, "serie4")) serie_4_menu();
        else if (!strcmp(opcao, "serie4a")) serie_4a_menu();
        else if (!strcmp(opcao, "frec1")) frequencia_1_menu();
        else if (!strcmp(opcao, "0"))
        {
            printf("Obrigado por usar este programa.\n");
            console_pause();
        }
        else
        {
            printf("Opção Desconhecida...\n");
            console_pause();
        }
    } while (strcmp(opcao, "0"));
}
