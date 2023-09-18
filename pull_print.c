#include "main.h"
/**
 *  * pull_print - Prints an argument based on its type
 *   * @fmt: Formatted string in which to print the arguments.
 *    * @list: List of arguments to be printed.
 *     * @ind: ind.
 *      * @buffer: Buffer array to handle print.
 *       * @flags: Calculates active flags
 *        * @width: get width.
 *         * @precision: Precision specification
 *          * @size: Size specifier
 *           * Return: 1 or 2;
 */
int pull_print(const char *fmt, int *ind, va_list list, char buffer[],
		int flags, int width, int precision, int size)
{
	int i, unknow_len = 0, no_of_printed_chars = -1;
	fmt_t fmt_types[] = {
		{'c', char_print}, {'s', str_print}, {'%', percent_print},
		{'i', int_print}, {'d', int_print}, {'b', bin_print},
		{'u', write_unsigned}, {'o', write_octal}, {'x', write_hexadecimal},
		{'X', write_hexa_upper}, {'p', print_add}, {'S', print_nprintable},
		{'r', print_rev}, {'R', print_rotstr}, {'\0', NULL}
	};
	for (i = 0; fmt_types[i].fmt != '\0'; i++)
		if (fmt[*ind] == fmt_types[i].fmt)
			return (fmt_types[i].fn(list, buffer, flags, width, precision, size));

	if (fmt_types[i].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknow_len += write(1, &fmt[*ind], 1);
		return (unknow_len);
	}
	return (no_of_printed_chars);
}
