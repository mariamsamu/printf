#include "main.h"

/**
 * _isdigit - Checks if a character is a digit.
 * @c: The character to check.
 *
 * Return: 1 if the character is a digit, 0 otherwise.
 */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9'); /*Returns 1 if 'c' is a digit, 0 otherwise*/
}

/**
 * _strlen - Returns the length of a string.
 * @s: The string whose length to check.
 *
 * Return: Integer length of the string.
 */
int _strlen(char *s)
{
	int i = 0;

	while (*s++)
		i++; /*Iterate through the string to count its characters*/
	return (i); /*Return the length of the string*/
}

/**
 * print_number - Prints a number with formatting options.
 * @str: The base number as a string.
 * @params: The parameter struct containing formatting options.
 *
 * Return: The number of characters printed.
 */
int print_number(char *str, params_t *params)
{
	unsigned int i = _strlen(str); /*Calculate the length of the string*/
	int neg = (!params->unsign && *str == '-'); /*Check if it's a negative number*/

	if (!params->precision && *str == '0' && !str[1])
		str = ""; /*Handle the case of zero with precision as zero*/
	if (neg)
	{
		str++; /*Move past the negative sign*/
		i--;
	}
	if (params->precision != UINT_MAX)
		while (i++ < params->precision)
			*--str = '0'; /*Add leading zeros as per precision*/
	if (neg)
		*--str = '-'; /*Add back the negative sign if it was negative*/

	if (!params->minus_flag)
		return (print_number_right_shift(str, params)); /*Right-align the number*/
	else
		return (print_number_left_shift(str, params)); /*Left-align the number*/
}

/**
 * print_number_right_shift - Prints a number with right alignment and options.
 * @str: The base number as a string.
 * @params: The parameter struct containing formatting options.
 *
 * Return: The number of characters printed.
 */
int print_number_right_shift(char *str, params_t *params)
{
	unsigned int n = 0, neg, neg2, i = _strlen(str);
	char pad_char = ' ';

	if (params->zero_flag && !params->minus_flag)
		pad_char = '0'; /*Use '0' padding if zero_flag is set and not minus_flag*/
	neg = neg2 = (!params->unsign && *str == '-'); /*Check for negative number*/
	if (neg && i < params->width && pad_char == '0' && !params->minus_flag)
		str++; /*Handle special case of negative number with zero padding*/
	else
		neg = 0; /*Reset neg if not a negative number*/
	if ((params->plus_flag && !neg2) ||
		(!params->plus_flag && params->space_flag && !neg2))
		i++; /*Increment character count for '+' or ' '*/
	if (neg && pad_char == '0')
		n += _putchar('-'); /*Print negative sign if needed with zero padding*/
	if (params->plus_flag && !neg2 && pad_char == '0' && !params->unsign)
		n += _putchar('+'); /*Print '+' with zero padding for positive numbers*/
	else if (!params->plus_flag && params->space_flag && !neg2 &&
		!params->unsign && params->zero_flag)
		n += _putchar(' '); /*Print ' ' with zero padding if '+' is not present*/
	while (i++ < params->width)
		n += _putchar(pad_char); /*Add padding characters as needed*/
	if (neg && pad_char == ' ')
		n += _putchar('-'); /*Print negative sign if needed with space padding*/
	if (params->plus_flag && !neg2 && pad_char == ' ' && !params->unsign)
		n += _putchar('+'); /*Print '+' with space padding for positive numbers*/
	else if (!params->plus_flag && params->space_flag && !neg2 &&
		!params->unsign && !params->zero_flag)
		n += _putchar(' '); /*Print ' ' with space padding if '+' is not present*/
	n += _puts(str); /*Print the number itself*/
	return (n); /*Return the number of characters printed*/
}

/**
 * print_number_left_shift - Prints a number with left alignment and options.
 * @str: The base number as a string.
 * @params: The parameter struct containing formatting options.
 *
 * Return: The number of characters printed.
 */
int print_number_left_shift(char *str, params_t *params)
{
	unsigned int n = 0, neg, neg2, i = _strlen(str);
	char pad_char = ' ';

	if (params->zero_flag && !params->minus_flag)
		pad_char = '0'; /*Use '0' padding if zero_flag is set and not minus_flag*/
	neg = neg2 = (!params->unsign && *str == '-');
	if (neg && i < params->width && pad_char == '0' && !params->minus_flag)
		str++; /*Handle special case of negative number with zero padding*/
	else
		neg = 0; /*Reset neg if not a negative number*/

	if (params->plus_flag && !neg2 && !params->unsign)
		n += _putchar('+'), i++; /*Print '+' and increment character count for positive numbers*/
	else if (params->space_flag && !neg2 && !params->unsign)
		n += _putchar(' '), i++; /*Print ' ' and increment character count for positive numbers*/
	n += _puts(str); /*Print the number itself*/
	while (i++ < params->width)
		n += _putchar(pad_char); /*Add padding characters as needed for left alignment*/
	return (n); /*Return the number of characters printed*/
}

