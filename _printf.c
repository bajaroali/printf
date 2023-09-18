#include "main.h"

void write_buffer(char buffer[], int *buff_ind);

/**
 * _printf - custom printf function
 * @format: format string.
 * Return: number of printed chars.
 */
int _printf(const char *format, ...)
{
<<<<<<< HEAD
	int char_print = 0;
	va_list args_list;

	if (format == NULL)
	{
		return (-1);
	}
	va_start(args_list, format);
	while (*format) /*interate through the characters in the format string*/
	{
		if (*format != '%') /* if character % sign*/
		{
			write(1, format, 1); /* write the character  to the std output */
			char_print++;
		}
		else /* if the character in format string is % sign */
		{
			format++; /*skip that % and check next charecter */
			if (*format == '\0')
				break;
			if (*format == '%') /*Handle the % */
			{
				write(1, format, 1);
				char_print++;
			}
			else if (*format == 'c')
			{
				char c = va_arg(args_list, int);/*handle %c */

				write(1, &c, 1);
				char_print++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(args_list, char*);
				int len = 0; /* initialize the length of the string*/
				/*calculate length of the string*/
				while (str[len] != '\0')
				{
					len++;
				}
				/*write the str characters to the std output*/
				write(1, str, len);
				char_print += len;
			}
		}
		format++;
	}
	va_end(args_list);
	return (char_print);
=======
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
>>>>>>> 203cca8be5d26dad3c8a9310b0601fa10679fc90
}

/**
 * write_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void write_buffer(char buffer[], int *buff_ind)
{
<<<<<<< HEAD
_printf("Bajaro\n");
_printf("%c\n", 'V');
_printf("%s\n", "String");
_printf("%%\n");
return 0;
}
*/
int main(void)

{
	int len;
	int len2;
	unsigned int ui;
	void *addr;

	len = _printf("Let's try to printf a simple sentence.\n");
	len2 = printf("Let's try to printf a simple sentence.\n");
	ui = (unsigned int)INT_MAX + 1024;
	addr = (void *)0x7ffe637541f0;
	_printf("Length:[%d, %i]\n", len, len);
	printf("Length:[%d, %i]\n", len2, len2);
	_printf("Negative:[%d]\n", -762534);
	printf("Negative:[%d]\n", -762534);
	_printf("Unsigned:[%u]\n", ui);
	printf("Unsigned:[%u]\n", ui);
	_printf("Unsigned octal:[%o]\n", ui);
	printf("Unsigned octal:[%o]\n", ui);
	_printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	_printf("Character:[%c]\n", 'H');
	printf("Character:[%c]\n", 'H');
	_printf("String:[%s]\n", "I am a string !");
	printf("String:[%s]\n", "I am a string !");
	_printf("Address:[%p]\n", addr);
	printf("Address:[%p]\n", addr);
	len = _printf("Percent:[%%]\n");
	len2 = printf("Percent:[%%]\n");
	_printf("Len:[%d]\n", len);
	printf("Len:[%d]\n", len2);
	/*_printf("Unknown:[%r]\n");*/
	/* printf("Unknown:[%r]\n");*/
	return (0);
=======
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
>>>>>>> 203cca8be5d26dad3c8a9310b0601fa10679fc90
}
