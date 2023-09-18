#include "main.h"

/**
 * precision_setter - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int precision_setter(const char *format, int *i, va_list list)
{
	int curr_i = *i + 1;
	int no_of_precision = -1;

	if (format[curr_i] != '.')
		return (no_of_precision);

	no_of_precision = 0;

	for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			no_of_precision *= 10;
			no_of_precision += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			no_of_precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;

	return (no_of_precision);
}
