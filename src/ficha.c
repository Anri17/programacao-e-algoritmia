#include "fichas.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utility.h"

#define FICHAS_STRING_SIZE 255

void fichas_menu()
{
    char opcao[FICHAS_STRING_SIZE];
    
    do
    {
        console_clear();
        printf("\n\n ####### Programação e Algoritmia #######\n\n");
        printf("Bem vind@. Estas são as fichas do curso de Programação e Algoritmia.\n");
        printf("Insira o numero fichas (ex.: 1.1, 4.0), ou zero(0) para sair.\n\n");
        printf("  1.0 - Ficha 1.0\n");
        printf("  1.1 - Ficha 1.1\n");
        printf("  2.0 - Ficha 2.0\n");
        printf("  2.1 - Ficha 2.1\n");
        printf("  3.0 - Ficha 3.0\n");
        printf("  3.1 - Ficha 3.1\n");
        printf("  4.0 - Ficha 4.0\n");
        //printf("  5.0 - Ficha 5.0\n");
        //printf("  fr1 - Frequência 1\n");
        printf("  0   - Sair\n\n");
        
        input_get_string(" Selecione uma opção: ", opcao, FICHAS_STRING_SIZE);

        printf("\n");
        if (!strcmp(opcao, "1.0"))
        {
            ficha_1_0_menu();
        }
        else
        if (!strcmp(opcao, "1.1"))
        {
            ficha_1_1_menu();
        }
        else
        if (!strcmp(opcao, "2.0"))
        {
            ficha_2_0_menu();
        }
        else
        if (!strcmp(opcao, "2.1"))
        {
            ficha_2_1_menu();
        }
        else
        if (!strcmp(opcao, "3.0"))
        {
            ficha_3_0_menu();
        }
        else
        if (!strcmp(opcao, "3.1"))
        {
            ficha_3_1_menu();
        }
        else
        if (!strcmp(opcao, "4.0"))
        {
            ficha_4_0_menu();
        }
        else
        if (!strcmp(opcao, "0"))
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








