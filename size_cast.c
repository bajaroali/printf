#include "main.h"
#include <stdarg.h>

/**
 *  * size_cast - Calculates the size to cast the argument
 *   * @format: Formatted string in which to print the arguments
 *    * @i: List of arguments to be printed.
 *     *
 *      * Return: Precision.
 */
int size_cast(const char *format, int *i)
{
	int curr_i = *i + 1;
	int sizee = 0;

	if (format[curr_i] == 'l')
		sizee = S_LONG;
	else if (format[curr_i] == 'h')
		sizee = S_SHORT;

	if (sizee == 0)
		*i = curr_i - 1;
	else
		*i = curr_i;

	return (sizee);
}
