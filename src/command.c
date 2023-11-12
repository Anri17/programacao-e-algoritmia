#include "command.h"

#include <stdlib.h>
#include <string.h>

command_t* command_create(char* str)
{
    int       i;
    command_t *output = (command_t *)malloc(sizeof(command_t));

    /* Get count of parameters */

    for (i = output->count = 0; str[i]; ++i)
    {
        if (str[i] == ' ' || str[i] == '\n')
            output->count++;
    }
    // if the string does not end in a new line
    // then the last parameter does not get counted in the loop
    // and it must be done after the loop
    if (str[i-1] != '\n') output->count++;

    // TODO: Copy the input string because it might exist in
    // the stack and not in the heap
    output->parameters = malloc(sizeof(char *) * output->count);

    i = 0;
    char* parameter_pointer = str;
    while (*str)
    {
        if (*str == ' ' || *str == '\n')
        {
            *str = '\0';
            size_t parameter_size = strlen(parameter_pointer) + 1;
            output->parameters[i] = malloc(sizeof(char) * parameter_size);
            strcpy(output->parameters[i], parameter_pointer);
            parameter_pointer = str + 1;
            ++i;
        }

        str++;
    }

    return output;
}

void command_destroy(command_t **command)
{
    int i;
    for (i = 0; i < (*command)->count; ++i)
    {
        free((*command)->parameters[i]);
        (*command)->parameters[i] = NULL;
    }
    free ((*command)->parameters);
    (*command)->parameters = NULL;
    free(*command);
    *command = NULL;
}
