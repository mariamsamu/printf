#include "main.h"

/**
 * _printf - Custom print function that handles various data types and formatting.
 * @format: The format string specifying how to print the data.
 *
 * Return: The number of bytes printed.
 */
int _printf(const char *format, ...)
{
	int sum = 0; /*Initialize a variable to keep track of the total bytes printed*/
	va_list ap; /*Declare a variable of type va_list to manage variable arguments*/
	char *p, *start; /*Pointers for navigating the format string and tracking substrings*/
	params_t params = PARAMS_INIT; /*Initialize a structure to store formatting parameters*/

	va_start(ap, format); /*Initialize variable argument processing using the format string*/

	/*Check for format string validity and edge cases */
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);

	for (p = (char *)format; *p; p++) /*Loop through each character in the format string*/
	{
		init_params(&params, ap); /*Initialize formatting parameters for each iteration*/

		if (*p != '%') /*If the character is not a '%', print it directly*/
		{
			sum += _putchar(*p);
			continue;
		}

		start = p; /*Store the starting position of the format specifier*/
		p++;

		while (get_flag(p, &params)) /*Continue while the character at 'p' is a flag character */
		{
			p++; /*Move to the next character */
		}

		p = get_width(p, &params, ap); /*Get the specified field width, if any*/
		p = get_precision(p, &params, ap); /*Get the specified precision, if any*/

		if (get_modifier(p, &params)) /*Check for length modifiers*/
			p++;

		if (!get_specifier(p)) /*Check for the conversion specifier*/
		{
			/*Print the substring between '%' and the specifier character*/
			sum += print_from_to(start, p,
				params.l_modifier || params.h_modifier ? p - 1 : 0);
		}
		else
		{
			/*Call a function to handle the specific conversion specifier*/
			sum += get_print_func(p, ap, &params);
		}
	}

	_putchar(BUFF_FLUSH); /*Flush the buffer to ensure all data is printed*/
	va_end(ap); /*End processing of variable arguments*/
	return (sum); /*Return the total number of bytes printed*/
}
