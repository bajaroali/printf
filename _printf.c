#include "main.h"

void write_buffer(char buffer[], int *buff_ind);

/**
 * _printf - custom printf function
 * @format: format string.
 * Return: number of printed chars.
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, no_of_printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				write_buffer(buffer, &buff_ind);
			/* write(1, &format[i], 1);*/
			no_of_printed_chars++;
		}
		else
		{
			write_buffer(buffer, &buff_ind);
			flags = flags_handler(format, &i);
			width = width_handler(format, &i, list);
			precision = precision_setter(format, &i, list);
			size = size_cast(format, &i);
			++i;
			printed = pull_print(format, &i, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			no_of_printed_chars += printed;
		}
	}

	write_buffer(buffer, &buff_ind);

	va_end(list);

	return (no_of_printed_chars);
}

/**
 * write_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void write_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
