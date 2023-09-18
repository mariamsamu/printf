#include "main.h"

/**
 * get_specifier - Finds the format function associated with a format specifier.
 * @s: The format string.
 *
 * Return: A function pointer to the appropriate print function.
 */
int (*get_specifier(char *s))(va_list ap, params_t *params)
{
	/*Define an array of specifier_t structs, each containing a specifier and its associated print function*/
	specifier_t specifiers[] = {
		{"c", print_char},
		{"d", print_int},
		{"i", print_int},
		{"s", print_string},
		{"%", print_percent},
		{"b", print_binary},
		{"o", print_octal},
		{"u", print_unsigned},
		{"x", print_hex},
		{"X", print_HEX},
		{"p", print_address},
		{"S", print_S},
		{"r", print_rev},
		{"R", print_rot13},
		{NULL, NULL}
	/*End of the specifier list*/

	/*Iterate through the specifiers array to find a match with the format specifier character in the input string*/
	};
	int i = 0;

	while (specifiers[i].specifier)
	{
		if (*s == specifiers[i].specifier[0])
		{
			return (specifiers[i].f); /*Return the associated print function if a match is found*/
		}
		i++;
	}
	return (NULL); /*Return NULL if no matching specifier is found*/
}

/**
 * get_print_func - Retrieves the appropriate printing function for a format specifier.
 * @s: The format string.
 * @ap: The argument pointer.
 * @params: The parameters struct containing formatting information.
 *
 * Returns: The number of bytes printed by the selected printing function.
 */
int get_print_func(char *s, va_list ap, params_t *params)
{
	/*Pointer to the printing function for the format specifier 's'*/
	int (*f)(va_list, params_t *) = get_specifier(s);

	/*If a valid printing function is found for the format specifier, call it with arguments and return the result*/

	if (f)
		return (f(ap, params));
	return (0); /*If no valid printing function is found (unsupported format specifier), return 0*/
}

/**
 * get_flag - Checks and sets formatting flags based on the format string.
 * @s: The format string.
 * @params: The parameters struct to store formatting flags.
 *
 * Returns: 1 if a valid flag character is found, 0 otherwise.
 */
int get_flag(char *s, params_t *params)
{
	int i = 0;

	/*Check the first character of the format string 's' for specific formatting flags*/

	switch (*s)
	{
		case '+':
			i = params->plus_flag = 1;
			break;
		case ' ':
			i = params->space_flag = 1;
			break;
		case '#':
			i = params->hashtag_flag = 1;
			break;
		case '-':
			i = params->minus_flag = 1;
			break;
		case '0':
			i = params->zero_flag = 1;
			break;
	}
	return (i); /*Return 1 if a valid flag character is found; otherwise, return 0*/
}

/**
 * get_modifier - Checks and sets format specifiers (modifiers) based on the format string.
 * @s: The format string.
 * @params: The parameters struct to store format specifiers.
 *
 * Returns: 1 if a valid format specifier character is found, 0 otherwise.
 */
int get_modifier(char *s, params_t *params)
{
	int i = 0;

	/*Check the first character of the format string 's' for specific format specifiers*/

	switch (*s)
	{
	case 'h':
		i = params->h_modifier = 1;
		break;
	case 'l':
		i = params->l_modifier = 1;
		break;
	}
	return (i); /*Return 1 if a valid format specifier character is found; otherwise, return 0*/
}

/**
 * get_width - Extracts the width value from the format string.
 * @s: The format string.
 * @params: The parameters struct used for storing formatting options.
 * @ap: The argument pointer for variable arguments.
 *
 * Returns: A new pointer within the format string after processing the width value.
 */
char *get_width(char *s, params_t *params, va_list ap)
{
	int d = 0; /*Initialize the width to 0*/

	/*Check if the width is specified as an asterisk '*' in the format string*/

	if (*s == '*')
	{
		/*If an asterisk is found, retrieve the width value from the variable arguments using va_arg*/
		d = va_arg(ap, int);
		s++; /*Move the format string pointer past the asterisk*/
	}
	else
	{
		while (_isdigit(*s))
			d = d * 10 + (*s++ - '0');
	}
	params->width = d;
	return (s); /*Return a new pointer within the format string after processing the width value*/
}

