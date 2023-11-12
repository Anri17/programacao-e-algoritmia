#ifndef __F_U_INPUT_H
#define __F_U_INPUT_H

// string input
void input_get_string(const char* prompt, char* buff, unsigned int size);

// char inpiut
void input_get_char_constraint(const char* prompt, const char* warning, const char* constraint, char* buff);

// int input
void input_get_int(const char* prompt, int*buff);
void input_get_int_min(const char* prompt, const char* warning, int*buff, int min);
void input_get_int_max(const char* prompt, const char* warning, int*buff, int max);
void input_get_int_range(const char* prompt, const char* warning, int* buff, int min, int max);

// float input
void input_get_float(const char* prompt, float* buff);
void input_get_float_min(const char* prompt, const char* warning, float* buff, float min);
void input_get_float_max(const char* prompt, const char* warning, float* buff, float max);
void input_get_float_range(const char* prompt, const char* warning, float* buff, float min, float max);

#endif // __F_U_INPUT_H