#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#define BUFF_SIZE 1024
#define BUFF_FLUSH -1
#define NULL_STR "(null)"
#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define CONV_LOWER 1
#define CONV_UNSIGNED 2

/**
 * struct parameters - Structure to store formatting parameters for printf-like functions.
 *
 * @unsign: Flag to indicate if the value is unsigned.
 *
 * @plus_flag: Set if the '+' flag is specified.
 * @space_flag: Set if the ' ' (space) flag is specified.
 * @hashtag_flag: Set if the '#' flag is specified.
 * @zero_flag: Set if the '0' flag is specified.
 * @minus_flag: Set if the '-' flag is specified.
 *
 * @width: Field width specified.
 * @precision: Field precision specified.
 *
 * @h_modifier: Set if the 'h' modifier is specified.
 * @l_modifier: Set if the 'l' modifier is specified.
 *
 */
typedef struct parameters
{
    unsigned int unsign : 1; /* Flag to indicate if the value is unsigned*/
    unsigned int plus_flag : 1; /* Set if the '+' flag is specified*/
    unsigned int space_flag : 1; /* Set if the ' ' (space) flag is specified*/
    unsigned int hashtag_flag : 1; /* Set if the '#' flag is specified*/
    unsigned int zero_flag : 1; /* Set if the '0' flag is specified*/
    unsigned int minus_flag : 1; /* Set if the '-' flag is specified*/
    unsigned int width; /* Field width specified*/
    unsigned int precision; /* Field precision specified.*/
    unsigned int h_modifier : 1; /* Set if the 'h' modifier is specified*/
    unsigned int l_modifier : 1; /* Set if the 'l' modifier is specified*/
} params_t;

/**
 * struct specifier - Struct to define format specifiers and associated functions.
 *
 * @specifier: Format token.
 * @f: Function associated with the format specifier.
 */
typedef struct specifier
{
    char *specifier;
    int (*f)(va_list, params_t *);
} specifier_t;

/*These are specific to the _put.c file*/
int _puts(char *str);
int _putchar(int c);

/*These are specific to the print_functions.c file*/
int print_char(va_list ap, params_t *params);
int print_int(va_list ap, params_t *params);
int print_string(va_list ap, params_t *params);
int print_percent(va_list ap, params_t *params);
int print_S(va_list ap, params_t *params);

/*These are specific to the number.c file*/
char *convert(long int num, int base, int flags, params_t *params);
int print_unsigned(va_list ap, params_t *params);
int print_address(va_list ap, params_t *params);

/*These are specific to the specifier.c file*/
int (*get_specifier(char *s))(va_list ap, params_t *params);
int get_print_func(char *s, va_list ap, params_t *params);
int get_flag(char *s, params_t *params);
int get_modifier(char *s, params_t *params);
char *get_width(char *s, params_t *params, va_list ap);

/*These are specific to the con-num.c file*/
int print_hex(va_list ap, params_t *params);
int print_HEX(va_list ap, params_t *params);
int print_binary(va_list ap, params_t *params);
int print_octal(va_list ap, params_t *params);

/*These are specific to the simpile-print.c file*/
int print_from_to(char *start, char *stop, char *except);
int print_rev(va_list ap, params_t *params);
int print_rot13(va_list ap, params_t *params);

/*These are specific to the print_number.c file*/
int _isdigit(int c);
int _strlen(char *s);
int print_number(char *str, params_t *params);
int print_number_right_shift(char *str, params_t *params);
int print_number_left_shift(char *str, params_t *params);

/* These are specific to the pramas.c file*/
void init_params(params_t *params, va_list ap);

/*These are specific to the precision.c file*/
char *get_precision(char *p, params_t *params, va_list ap);

/* These are specific to the _printf.c */
int _printf(const char *format, ...);

/*in here that end*/

#endif

