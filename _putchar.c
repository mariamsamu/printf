#include "main.h"

/**
 * _putchar - Writes the character 'c' to stdout.
 * @c: The character to print.
 *
 * Return: On success, it returns 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(int c)
{
	static int i; /*Static variable to keep track of the current buffer position*/
	static char buf[BUFF_SIZE]; /*Static buffer to store characters*/

	if (c == BUFF_FLUSH || i >= BUFF_SIZE)
	{
		write(1, buf, i); /*Write the buffer contents to stdout*/
		i = 0; /*Reset the buffer position*/
	}
	if (c != BUFF_FLUSH) /*If 'c' is not a buffer flush indicator, store it in the buffer*/
		buf[i++] = c;
	return (1); /*Return 1 to indicate successful printing of one character*/
}

/**
 * _puts - Prints a string followed by a newline.
 * @str: The string to print.
 *
 * Return: The number of characters printed (excluding the null terminator).
 */
int _puts(char *str)
{
	char *a = str; /*Store the starting address of the string*/

	while (*str)
		_putchar(*str++); /*Print each character of the string using _putchar*/

	return (str - a); /*Calculate and return the number of characters printed*/
}

