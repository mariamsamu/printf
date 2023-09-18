#include "main.h"

/**
 * print_char - Prints a character.
 * @ap: Argument pointer.
 * @params: The parameters struct.
 *
 * Return: The number of characters printed (1).
 */
int print_char(va_list ap, params_t *params)
{
	char pad_char = ' '; /*Default padding character is a space*/
	unsigned int pad = 1, sum = 0, ch = va_arg(ap, int); /*Initialize variables*/

	if (params->minus_flag)
		sum += _putchar(ch); /*If minus flag is set, print the character first*/
	while (pad++ < params->width)
		sum += _putchar(pad_char); /*Print padding characters based on width*/
	if (!params->minus_flag)
		sum += _putchar(ch); /*If minus flag is not set, print the character last*/
	return (sum);
}

/**
 * print_int - Prints an integer.
 * @ap: Argument pointer.
 * @params: The parameters struct.
 *
 * Return: The number of characters printed.
 */
int print_int(va_list ap, params_t *params)
{
	long l;

	if (params->l_modifier) /*Determine the appropriate data type based on modifier flags*/
		l = va_arg(ap, long);
	else if (params->h_modifier)
		l = (short int)va_arg(ap, int);
	else
		l = (int)va_arg(ap, int); /*Convert the integer to a string and call the print_number function to print it*/
	return (print_number(convert(l, 10, 0, params), params));
}

/**
 * print_string - Prints a string.
 * @ap: Argument pointer.
 * @params: The parameters struct.
 *
 * Return: The number of characters printed.
 */
int print_string(va_list ap, params_t *params)
{
	char *str = va_arg(ap, char *), pad_char = ' ';
	unsigned int pad = 0, sum = 0, i = 0, j;
	/*Suppress unused parameter warning for 'params'*/

	(void)params;
	switch ((int)(!str)) /*Handle the case where the string pointer is NULL*/
		case 1:
			str = NULL_STR; /*Set str to the predefined NULL_STR*/

	j = pad = _strlen(str);  /*Initialize 'j' and 'pad' with the length of the string*/
	if (params->precision < pad) /*Adjust 'j' and 'pad' based on precision*/
		j = pad = params->precision;

	if (params->minus_flag) /*If the minus flag is set (left-justify)*/
	{
		if (params->precision != UINT_MAX) /*If precision is specified*/
			for (i = 0; i < pad; i++) /*Print characters from the string up to 'pad'*/
				sum += _putchar(*str++);
		else /*If no precision is specified, print the whole string*/
			sum += _puts(str);
	}
	while (j++ < params->width) /*Print padding characters based on width*/
		sum += _putchar(pad_char);
	if (!params->minus_flag) /*If the minus flag is not set (right-justify)*/
	{
		if (params->precision != UINT_MAX) /*If precision is specified*/
			for (i = 0; i < pad; i++) /*Print characters from the string up to 'pad'*/
				sum += _putchar(*str++);
		else /*If no precision is specified, print the whole string*/
			sum += _puts(str);
	}
	return (sum);
}

/**
 * print_percent - Prints the '%' character.
 * @ap: Argument pointer (not used).
 * @params: The parameters struct (not used).
 *
 * Return: The number of characters printed (always 1).
 */
int print_percent(va_list ap, params_t *params)
{
	(void)ap; /*Suppress unused parameter warnings for 'ap' and 'params'*/
	(void)params;
	return (_putchar('%'));
}

/**
 * print_S - Custom format specifier for printing strings.
 * @ap: Argument pointer.
 * @params: The parameters struct.
 *
 * Return: The number of characters printed.
 */
int print_S(va_list ap, params_t *params)
{
	char *str = va_arg(ap, char *); /*Handle the case where the string pointer is NULL*/
	char *hex;
	int sum = 0;

	if ((int)(!str))
		return (_puts(NULL_STR)); /*Print the predefined NULL_STR*/
	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127) /*Check if character is non-printable or extended ASCII*/
		{
			sum += _putchar('\\');
			sum += _putchar('x');
			hex = convert(*str, 16, 0, params);
			if (!hex[1]) /*If the hexadecimal representation has only one digit*/
				sum += _putchar('0'); /*Print a leading '0'*/
			sum += _puts(hex); /*Print the hexadecimal representation*/
		}
		else
		{
			sum += _putchar(*str); /*Print the printable character as is*/
		}
	}
	return (sum);
}

