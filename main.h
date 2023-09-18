#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>


#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/*FLAGS -notifications*/
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/*SIZES -setter*/
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - Struct op
 *
 * @fmt: Specify the format.
 * @fn: The associated function .
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: Specify the format.
 * @fm_t: The associated function .
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int pull_print(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);


/* Funtions to print chars and strings */
int char_print(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int str_print(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int percent_print(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Functions to print numbers */
int int_print(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int bin_print(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int write_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int write_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int write_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int write_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int write_hexa(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);

/* Function to print non printable characters */
int print_nprintable(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Funcion to print memory address */
int print_add(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Funciotns to handle other specifiers */
int flags_handler(const char *format, int *i);
int width_handler(const char *format, int *i, va_list list);
int precision_setter(const char *format, int *i, va_list list);
int size_cast(const char *format, int *i);

/*Function to print string in reverse*/
int print_rev(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/*Function to print a string in rot 13*/
int print_rotstr(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* width handler */
int print_str(char c, char buffer[],
	int flags, int width, int precision, int size);
int print_number(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int print_num(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int print_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);

int print_unsgnd(int is_negative, int ind,
char buffer[],
	int flags, int width, int precision, int size);


int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_number_size(long int num, int size);
long int convert_unsgnd_size(unsigned long int num, int size);

#endif /* MAIN_H */
