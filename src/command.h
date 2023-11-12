#ifndef __F_COMMAND_H
#define __F_COMMAND_H

typedef struct
{
    unsigned int count;
    char** parameters;
} command_t;

// parses a string into a command separated by spaces
command_t *command_create(char* str);

// destroys a command pointer
void      command_destroy(command_t **command);

#endif /* __F_COMMAND_H */
