#ifndef _VARIADIC_FUNCTION_H_
#define _VARIADIC_FUNCTION_H_


int sum_them_all(const unsigned int n, ...);
void print_numbers(const char *separator, const unsigned int n, ...);
void print_strings(const char *separator, const unsigned int n, ...);
void print_all(const char * const format, ...);

#endif /*_VARIADIC_FUNCTION_H_ */
