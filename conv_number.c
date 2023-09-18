#include "main.h"

/**
 * print_octal - Prints unsigned octal numbers.
 * @ap: The argument pointer.
 * @params: The parameters struct.
 *
 * Return: The number of bytes printed.
 */
int print_octal(va_list ap, params_t *params)
{
	unsigned long l; /*Variable to hold the unsigned long integer*/
	char *str; /*Pointer to store the converted octal number as a string*/
	int c = 0; /*Counter for the number of bytes printed*/

	/*Determine the type of argument and extract it accordingly*/
	if (params->l_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);

	/*Convert the unsigned integer 'l' to an octal string representation*/
	str = convert(l, 8, CONV_UNSIGNED, params);

	/*Add '0' prefix if the '#' flag is set and the value is not zero*/
	if (params->hashtag_flag && l)
		*--str = '0';

	params->unsign = 1; /*Indicate that an unsigned value is being printed*/
	return (c += print_number(str, params)); /*Print the octal number and update the byte count*/
}

/**
 * print_binary - Prints unsigned binary numbers.
 * @ap: The argument pointer.
 * @params: The parameters struct.
 *
 * Return: The number of bytes printed.
 */
int print_binary(va_list ap, params_t *params)
{
	unsigned int n = va_arg(ap, unsigned int); /*Extract the unsigned integer argument*/
	char *str = convert(n, 2, CONV_UNSIGNED, params); /*Convert 'n' to binary string*/
	int c = 0; /* Counter for the number of bytes printed*/

	/*Add '0' prefix if the '#' flag is set and 'n' is not zero*/
	if (params->hashtag_flag && n)
		*--str = '0';

	params->unsign = 1; /*Indicate that an unsigned value is being printed*/
	return (c += print_number(str, params)); /*Print the binary number and update the byte count*/
}

/**
 * print_hex - Prints unsigned hexadecimal numbers in lowercase.
 * @ap: The argument pointer.
 * @params: The parameters struct.
 *
 * Return: The number of bytes printed.
 */
int print_hex(va_list ap, params_t *params)
{
	unsigned long l; /*Variable to hold the unsigned long integer*/
	int c = 0; /*Counter for the number of bytes printed*/
	char *str;

	/*Determine the type of argument and extract it accordingly*/
	if (params->l_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);

	/*Convert the unsigned integer 'l' to a lowercase hexadecimal string*/
	str = convert(l, 16, CONV_UNSIGNED | CONV_LOWER, params);

	/*Add '0x' prefix if the '#' flag is set and 'l' is not zero*/
	if (params->hashtag_flag && l)
	{
		*--str = 'x';
		*--str = '0';
	}

	params->unsign = 1; /*Indicate that an unsigned value is being printed*/
	return (c += print_number(str, params)); /*Print the hexadecimal number and update the byte count*/
}
/**
 * print_HEX - Prints unsigned hexadecimal numbers in uppercase.
 * @ap: The argument pointer.
 * @params: The parameters struct.
 *
 * Return: The number of bytes printed.
 */
int print_HEX(va_list ap, params_t *params)
{
	unsigned long l; /*Variable to hold the unsigned long integer*/
	int c = 0; /*Counter for the number of bytes printed*/
	char *str;

	/*Determine the type of argument and extract it accordingly*/
	if (params->l_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);

	/*Convert the unsigned integer 'l' to an uppercase hexadecimal string*/
	str = convert(l, 16, CONV_UNSIGNED, params);

	/*Add '0X' prefix if the '#' flag is set and 'l' is not zero*/
	if (params->hashtag_flag && l)
	{
		*--str = 'X';
		*--str = '0';
	}

	params->unsign = 1; /*Indicate that an unsigned value is being printed*/
	return (c += print_number(str, params)); /*Print the hexadecimal number and update the byte count*/
}

