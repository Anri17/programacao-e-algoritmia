#include "frequencia_1.h"

#include <stdio.h>
#include <stdbool.h>

#include "utility.h"

void frequencia_1_ex_1()
{
    float num1;
    float num2;
    float distancia_num1;
    float distancia_num2;

    printf("\n\n"
           "   ########## Exercício 1 ##########\n\n");
    printf("O seguinte algoritmo irá solicitar ao utilizador dois numeros, verificar e motrar qual deles\n"
           "está mais proximo do valor de 100. Caso os dois numeros seja iguais, o algoritmo mostra 0.\n"
           "\n");
    printf("Introduza dois numeros\n");
    printf(" num 1: ");
    scanf("%f", &num1);
    printf(" num 2: ");
    scanf("%f", &num2);
    printf("\n");

    // procurar a distancia entre os numeros introduzidos e 100
    distancia_num1 = num1 - 100.0f;
    distancia_num2 = num2 - 100.0f;

    // Converter as distancia para valores absolutos
    if (distancia_num1 < 0) distancia_num1 = -distancia_num1;
    if (distancia_num2 < 0) distancia_num2 = -distancia_num2;

    // Verificar qual a distancia mais curta, ou seja, qual o numero mais proximo de 100
    if (distancia_num1 < distancia_num2)
    {
        printf("O numero mais proximo de 100 é %.2f.\n", num1);
    }
    else if (distancia_num2 < distancia_num1)
    {
        printf("O numero mais proximo de 100 é %.2f.\n", num2);
    }
    else if (distancia_num1 == distancia_num2 && num1 != num2)
    {
        // verificar caso em que a distancia é a mesma, mas os numeros introduzido sao simetricamente distantes: ex 50 e 150
        printf("Os dois números, %.2f e %.2f, estão à mesma distância do valor 100.\n", num1, num2);
    }
    else // os numeros são iguais
    {
        printf("O numeros são iguais: 0.\n");
    }


    printf("\n"
           "   #################################\n\n");
}

void frequencia_1_ex_2()
{
    float f_intermedio_1;
    float f_intermedio_2;
    float i_intermedio_1;
    float i_intermedio_2;
    int num1;
    int num2;

    printf("\n\n"
           "   ########## Exercício 2 ##########\n\n");
    printf("O seguinte algoritmo verificar se os ultimos digitos de dois numeros inteiros positivo introduzidos\n"
           "pelo utilizador são iguais.\n"
           "\n");
    do
    {
        printf("Introduza um numero: ");
        scanf("%d", &num1);
        if (num1 <= 0)
        {
            printf("ATENÇÃO: O número tem que ser inteiro e positivo.\n");
        }
    } while (num1 <= 0);
    do
    {
        printf("Introduza outro numero: ");
        scanf("%d", &num2);
        if (num2 <= 0)
        {
            printf("ATENÇÃO: O número tem que ser inteiro e positivo.\n");
        }
    } while (num2 <= 0);
    printf("\n");

    f_intermedio_1 = num1 / 10.0f;
    f_intermedio_2 = num2 / 10.0f;
    i_intermedio_1 = (int)f_intermedio_1;
    i_intermedio_2 = (int)f_intermedio_2;
    f_intermedio_1 = f_intermedio_1 - i_intermedio_1;
    f_intermedio_2 = f_intermedio_2 - i_intermedio_2;

    // Apresentar Resultado
    if (f_intermedio_1 == f_intermedio_2)
    {
        printf("O ultimos dois digitos são iguais.\n");
    }
    else
    {
        printf("O ultimos dois digitos não são iguais.\n");
    }

    printf("\n"
           "   #################################\n\n");
}

void frequencia_1_ex_3()
{
    float a_rect_top;
    float a_rect_right;
    float a_rect_bottom;
    float a_rect_left;

    float b_rect_top;
    float b_rect_right;
    float b_rect_bottom;
    float b_rect_left;

    float intercept_top;
    float intercept_right;
    float intercept_bottom;
    float intercept_left;

    float intercept_width;
    float intercept_height;
    float intercept_area;

    bool interceptam;

    printf("\n\n"
           "   ########## Exercício 3 ##########\n\n");
    printf("O seguinte algoritmo verifica e retorna a area de interseção de dois retângulos, dados os pontos dos dois retangulos\n"
           "\n");

    printf("Pontos do Retangulo A\n");
    printf(" Ponto Inferior (Baixo): ");
    scanf("%f", &a_rect_bottom);
    printf(" Ponto Esquerdo (Esquerda): ");
    scanf("%f", &a_rect_left);
    do
    {
        printf(" Ponto Superior (Cima): ");
        scanf("%f", &a_rect_top);
        if (a_rect_top <= a_rect_bottom)
        {
            printf("ATENÇÃO: O ponto superior não pode ser menor ou igual que o ponto inferior.\n");
        }
    } while (a_rect_top <= a_rect_bottom);
    do
    {
        printf(" Ponto Direto (Direita): ");
        scanf("%f", &a_rect_right);
        if (a_rect_right <= a_rect_left)
        {
            printf("ATENÇÃO: O ponto direito não pode ser menor ou igual que o ponto esquerdo.\n");
        }
    } while (a_rect_right <= a_rect_left);

    printf("\nPontos do Retangulo B\n");
    printf(" Ponto Inferior (Baixo): ");
    scanf("%f", &b_rect_bottom);
    printf(" Ponto Esquerdo (Esquerda): ");
    scanf("%f", &b_rect_left);
    do
    {
        printf(" Ponto Superior (Cima): ");
        scanf("%f", &b_rect_top);
        if (b_rect_top <= b_rect_bottom)
        {
            printf("ATENÇÃO: O ponto superior não pode ser menor ou igual que o ponto inferior.\n");
        }
    } while (b_rect_top <= b_rect_bottom);
    do
    {
        printf(" Ponto Direto (Direita): ");
        scanf("%f", &b_rect_right);
        if (b_rect_right <= b_rect_left)
        {
            printf("ATENÇÃO: O ponto direito não pode ser menor ou igual que o ponto esquerdo.\n");
        }
    } while (b_rect_right <= b_rect_left);
    printf("\n");

    interceptam = a_rect_top  < b_rect_bottom &&
                  a_rect_left < b_rect_right  &&
                  b_rect_top  < a_rect_bottom &&
                  b_rect_left < a_rect_right;

    if (interceptam)
    {
        printf("A interseção dos retângulos é nula.\n");
    }
    else
    {
        if (a_rect_bottom < b_rect_top && a_rect_bottom > b_rect_top)
        {
            intercept_bottom = a_rect_bottom;
        }
        else intercept_bottom = b_rect_bottom;

        if (a_rect_top > b_rect_bottom && a_rect_top < b_rect_top)
        {
            intercept_top = a_rect_top ;
        }
        else intercept_top = b_rect_top;

        if (a_rect_right > b_rect_left && a_rect_right < b_rect_right)
        {
            intercept_right = a_rect_right;
        }
        else intercept_right = b_rect_right;


        if (a_rect_left < b_rect_right && a_rect_left > b_rect_left)
        {
            intercept_left = a_rect_left;
        }
        else intercept_left = b_rect_left;


        intercept_width = intercept_right - intercept_left;
        intercept_height = intercept_top - intercept_bottom;
        intercept_area = intercept_width * intercept_height;

        printf("A area de interseção dos dois retangulos é %.2f\n", intercept_area);
    }

    printf("\n"
           "   #################################\n\n");
}

void frequencia_1_ex_4()
{
    float num;
    float max;
    int i;
    int max_pos;

    printf("\n\n"
           "   ########## Exercício 4 ##########\n\n");
    printf("O seguinte algoritmo recebe 5 numeros positivos do utilizador e verifica qual deles e o maior,\n"
           "assim como a sua posição na seguencia de entrada.\n");

    printf("\nIntroduza 5 numeros\n");
    max = 0;
    max_pos = -1;
    for (i = 1; i <= 5; ++i)
    {
        do
        {
            printf(" %d> ", i);
            scanf("%f", &num);

            if (num <= 0)
            {
                printf("ATENÇÃO: O numero tem que ser positivo.\n");
            }
        } while (num <= 0);
        if (num > max)
        {
            max = num;
            max_pos = i;
        }
    }

    printf("\nO maior valor introduzido foi %.2f.\n"
           "A sua posição na sequência de entrada foi %d.\n", max, max_pos);

    printf("\n"
           "   #################################\n\n");
}

void frequencia_1_ex_5()
{
    int min, max;
    int soma;
    int i;

    printf("\n\n"
           "   ########## Exercício 5 ##########\n\n");
    printf("O seguinte algoritmo recebe um limite minimo e um limite maximo do utilizador,\n"
           "sendo esses limites numeros inteiros positivos,\n"
           "e imprime a soma dos numeros pares dentro desse limite\n");
    printf("\n");

    do
    {
        printf("Introduza o limite minimo: ");
        scanf("%d", &min);

        if (min <= 0)
        {
            printf("ATENÇÃO: O numero tem que ser inteiro positivo.\n");
        }
    } while (min <= 0);

    do
    {
        printf("Introduza o limite maximo: ");
        scanf("%d", &max);

        if (max <= 0)
        {
            printf("ATENÇÃO: O numero tem que ser inteiro positivo.\n");
        }
        if (max <= min)
        {
            printf("ATENÇÃO: O numero tem que ser maior que o limite minimo.\n");
        }
    } while (max <= 0 || max <= min);

    // começar a um numero impare
    if (min % 2 == 0)
    {
        i = min + 1;
    }
    else
    {
        i = min;
    }
    while ( i <= max )
    {
        soma = soma + i;
        i = i + 2;
    }

    printf("\nA soma dos numero impares entre %d e %d é %d\n", min, max, soma);

    printf("\n"
           "   #################################\n\n");
}

void frequencia_1_ex_6()
{
    int num, fatorial, i;

    printf("\n\n"
           "   ########## Exercício 6 ##########\n\n");
    printf("O seguinte algoritmo calcula o fatorial de um numero recebido pelo utilizador\n");
    printf("\n");

    do
    {
        printf("Introduza um numero: ");
        scanf("%d", &num);

        if (num <= 0)
        {
            printf("ATENÇÃO: O numero tem que ser inteiro positivo.\n");
        }
    } while (num <= 0);

    fatorial = 1;
    for (i = 1; i <= num; ++i)
    {
        fatorial = fatorial * i;
    }

    printf("\nO fatorial de %d é %d.\n", num, fatorial);

    printf("\n"
           "   #################################\n\n");
}

void frequencia_1_menu()
{
    int opcao;

    do
    {
		console_clear();
        printf("\n   ######### 1ª Frequência #########\n\n"
               "Introduza o numero de um dos exercícios a executar, ou 0 para sair\n"
               "\n"
               "  1 - Distância entre numeros e 100\n"
               "  2 - Verificar igualdade dos dois ultimos digitos de um número\n"
               "  3 - Area da Interseão de dois retêngulos\n"
               "  4 - Maior de 5 numeros e sua posição\n"
               "  5 - Soma dos numeros impares dentro de um limite de numeros\n"
               "  6 - Fatorial de um número\n"
               "  0 - Sair\n"
               "\n"
               "Opcão: ");
        scanf("%d", &opcao);

        printf("\n");
        switch (opcao)
        {
            case 1:
                printf("   #################################\n");
                frequencia_1_ex_1();
                break;
            case 2:
                printf("   #################################\n");
                frequencia_1_ex_2();
                break;
            case 3:
                printf("   #################################\n");
                frequencia_1_ex_3();
                break;
            case 4:
                printf("   #################################\n");
                frequencia_1_ex_4();
                break;
            case 5:
                printf("   #################################\n");
                frequencia_1_ex_5();
                break;
            case 6:
                printf("   #################################\n");
                frequencia_1_ex_6();
                break;
            case 0:
                printf("Obrigado por usar este programa.\n");
                printf("\n   #################################\n\n");
				console_pause();
            break;
            default:
                printf("ATENÇÃO: Parâmetro desconhecido, tente outra vêz...\n");
                printf("\n   #################################\n\n");
				console_pause();
            break;
        };
    } while (opcao != 0);
}

