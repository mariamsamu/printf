#include "main.h"

/**
 * convert - Converter function, similar to itoa, for converting numbers to strings.
 * @num: Number to convert.
 * @base: Base for conversion (e.g., 10 for decimal, 16 for hexadecimal).
 * @flags: Argument flags (e.g., CONV_LOWER or CONV_UNSIGNED).
 * @params: Parameter struct (not used in this function).
 *
 * Return: Pointer to the converted string.
 */
char *convert(long int num, int base, int flags, params_t *params)
{
	static char *array; /* Character array for digits (either lowercase or uppercase)*/
	static char buffer[50]; /* Buffer to store the resulting string*/
	char sign = 0; /* Sign indicator for negative numbers*/
	char *ptr; /* Pointer to the current position in the buffer*/
	unsigned long n = num; /* Unsigned version of the input number*/
	(void)params; /* Unused parameter, avoids compiler warning*/

	/* If the CONV_UNSIGNED flag is not set and the number is negative, make it positive and set the sign*/
	if (!(flags & CONV_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';

	}
	array = flags & CONV_LOWER ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * print_unsigned - Prints unsigned integer numbers.
 * @ap: Argument pointer.
 * @params: The parameters struct.
 *
 * Return: The number of bytes printed.
 */
int print_unsigned(va_list ap, params_t *params)
{
	unsigned long l;

	/* Determine the appropriate data type based on modifier flags*/
	if (params->l_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);
	params->unsign = 1;
	/* Convert the unsigned number to a string and print it*/
	return (print_number(convert(l, 10, CONV_UNSIGNED, params), params));
}

/**
 * print_address - Prints an address.
 * @ap: Argument pointer.
 * @params: The parameters struct.
 *
 * Return: The number of bytes printed.
 */
int print_address(va_list ap, params_t *params)
{
	unsigned long int n = va_arg(ap, unsigned long int);
	char *str;

	/* If the address is NULL, print "(nil)" and return*/
	if (!n)
		return (_puts("(nil)"));

	/* Convert the address to a hexadecimal string and add the "0x" prefix*/
	str = convert(n, 16, CONV_UNSIGNED | CONV_LOWER, params);
	*--str = 'x';
	*--str = '0';
	/* Print the address string*/
	return (print_number(str, params));
}

