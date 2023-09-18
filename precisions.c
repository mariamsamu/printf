#include "main.h"

/**
 * get_precision - Extracts the precision value from the format string.
 * @p: The format string pointer.
 * @params: The parameters struct where precision is stored.
 * @ap: The argument pointer.
 *
 * Return: A new pointer within the format string.
 */
char *get_precision(char *p, params_t *params, va_list ap)
{
	int d = 0; /* Initialize the precision value to 0*/

	if (*p != '.') /* Check if the current character is not a period (dot)*/
		return (p); /* If not, return the original pointer (no precision specified)*/
	p++; /* Move the pointer past the period*/
	if (*p == '*') /* Check if the next character is an asterisk (*) */
	{
		d = va_arg(ap, int); /* Retrieve precision from the argument list*/
		p++; /* Move the pointer past the asterisk*/
	}
	else
	{
		/* If the next character is not an asterisk, parse a numeric precision value*/
		while (_isdigit(*p)) /* While the character is a digit*/
			d = d * 10 + (*p++ - '0'); /* Convert and accumulate digits to form the precision value*/
	}
	params->precision = d; /* Store the parsed precision value in the parameters struct*/
	return (p);
}

