#include "u_input.h"

#include <stdio.h>


// string input
void input_get_string(const char* prompt, char* buff, unsigned int size)
{
    char *c = buff;
    printf(prompt);
    fflush(stdin);
    fgets(buff, size, stdin);
    while (*c++)
        if (*c == '\n')
            *c = '\0';
}

void input_get_char_constraint(const char* prompt, const char* warning, const char* constraint, char* buff)
{
    for (;;) {
        printf(prompt);
        fflush(stdin);
        *buff = fgetc(stdin);
        for (const char *c = constraint; *c; ++c)
        {
            if (*buff == *c) return;
        }
        printf(warning);
    }
}


// int input
void input_get_int(const char* prompt, int* buff)
{
    printf(prompt);
    fflush(stdin);
    scanf("%d", buff);
}
void input_get_int_min(const char* prompt, const char* warning, int* buff, int min)
{
    do {
        printf(prompt);
        fflush(stdin);
        scanf("%d", buff);
        if (!((*buff) >= min)) printf(warning);
    } while (!((*buff) >= min));
}
void input_get_int_max(const char* prompt, const char* warning, int* buff, int max)
{
    do {
        printf(prompt);
        fflush(stdin);
        scanf("%d", buff);
        if (!((*buff) <= max)) printf(warning);
    } while (!((*buff) <= max));
}
void input_get_int_range(const char* prompt, const char* warning, int* buff, int min, int max)
{
    do {
        printf(prompt);
        fflush(stdin);
        scanf("%d", buff);
        if (!((*buff) >= min && (*buff) <= max)) printf(warning);
    } while (!((*buff) >= min && (*buff) <= max));
}


// float input
void input_get_float(const char* prompt, float* buff)
{
    printf(prompt);
    fflush(stdin);
    scanf("%f", buff);
}
void input_get_float_min(const char* prompt, const char* warning, float* buff, const float min)
{
    do {
        printf(prompt);
        fflush(stdin);
        scanf("%f", buff);
        if (!((*buff) >= min)) printf(warning);
    } while (!((*buff) >= min));
}
void input_get_float_max(const char* prompt, const char* warning, float* buff, const float max)
{
    do {
        printf(prompt);
        fflush(stdin);
        scanf("%f", buff);
        if (!((*buff) <= max)) printf(warning);
    } while (!((*buff) <= max));
}
void input_get_float_range(const char* prompt, const char* warning, float* buff, const float min, const float max)
{
    do {
        printf(prompt);
        fflush(stdin);
        scanf("%f", buff);
        if (!((*buff) >= min && (*buff) <= max)) printf(warning);
    } while (!((*buff) >= min && (*buff) <= max));
}
