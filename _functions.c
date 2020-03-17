#include "holberton.h"
#include <unistd.h>

/**
 * print_c - writes the character c
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int print_c(char c)
{
	{

		return (write(1, &c, 1));
	}
}


/**
 * character - prints character c
 * @ap: character to print
 * Return: number of characters printed
 */

int character(va_list ap)
{
	char ch;

	ch = va_arg(ap, int);

	print_c(ch);

	return (1);
}

/**
 * string - prints string s
 * @ap: string to print
 * Return: number of characters printed
 */

int string(va_list ap)
{
	unsigned int i;

	char *str;

	str = va_arg(ap, char *);

	if (str != NULL)
	{
		i = 0;

		while (str[i])
		{
			i += print_c(str[i]);
		}
	}

	else
	{
		str = "(null)";
	}

		return (i);
}

/**
 * decimal_integer - prints numbers decimal
 * @ap: argument to print
 * Return: number of characters printed in decimal
 */

int decimal_integer(va_list ap)
{
	int n = va_arg(ap, int);
	int last = n % 10;
	int exp = 1;
	int i = 1;
	int number, digt;

	n = n / 10;
	number = n;

	if (last < 0)
	{
		print_c('-');
		number = -number;
		n = -n;
		last = -last;
		i++;
	}
	if (number > 0)
	{
		while (number / 10 != 0)
		{
			exp = exp * 10;
			number = number / 10;
		}
		number = n;
		while (exp > 0)
		{
			digt = number / exp;
			print_c(digt + '0');
			number = number - (digt * exp);
			exp = exp / 10;
			i++;
		}
	}

	print_c(last + '0');

	return (i);
}
