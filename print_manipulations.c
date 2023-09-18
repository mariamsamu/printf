#include "main.h"

/**
 * print_rot13 - Prints a string in ROT13 encoding.
 * @ap: String to be encoded in ROT13.
 * @params: The parameters struct (not used).
 *
 * Return: The number of bytes printed.
 */
int print_rot13(va_list ap, params_t *params)
{
	int i, index;
	int count = 0;
	char arr[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm"; /*ROT13 character mapping*/
	char *a = va_arg(ap, char *); /*Get the input string*/
	(void)params; /*Suppress unused parameter warning*/

	i = 0;
	index = 0;
	while (a[i])
	{
		if ((a[i] >= 'A' && a[i] <= 'Z')
		    || (a[i] >= 'a' && a[i] <= 'z'))
		{
			index = a[i] - 65; /*Map uppercase and lowercase letters to ROT13 characters - Calculate the index in the mapping array */
			count += _putchar(arr[index]); /*Print the corresponding ROT13 character*/
		}
		else
			count += _putchar(a[i]); /*Non-alphabet characters are printed as is*/
		i++;
	}
	return (count); /*Return the total number of bytes printed*/
}

/**
 * print_from_to - Prints a range of characters from start to stop addresses.
 * @start: Starting address.
 * @stop: Stopping address.
 * @except: Except address (characters at this address are skipped).
 *
 * Return: The number of bytes printed.
 */
int print_from_to(char *start, char *stop, char *except)
{
	int sum = 0;

	while (start <= stop)
	{
		if (start != except)
			sum += _putchar(*start); /*Print the character at the current address*/
		start++;
	}
	return (sum);
}

/**
 * print_rev - Prints a string in reverse.
 * @ap: String to be printed in reverse.
 * @params: The parameters struct (not used).
 *
 * Return: The number of bytes printed.
 */
int print_rev(va_list ap, params_t *params)
{
	int len, sum = 0;
	char *str = va_arg(ap, char *); /*Get the input string*/
	(void)params; /*Suppress unused parameter warning*/

	if (str)
	{
		for (len = 0; *str; str++)
			len++; /*Calculate the length of the string*/
		str--; /*Move the pointer to the last character*/
		for (; len > 0; len--, str--)
			sum += _putchar(*str); /*Print the characters in reverse order*/
	}
	return (sum);
}

