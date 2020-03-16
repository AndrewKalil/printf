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
	return (write(1, &c, 1));
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
		for (i = 0; str[i] != '\0'; i++)
		{
			print_c(str[i]);
		}
	}

	else
	{
		str = "(nill)";
	}

		return (i);
}

/**
 * decimal - prints numbers decimal
 * @ap: argument to print
 * Return: number of characters printed in decimal
 */

int decimal(va_list ap)
{
	int n = va_arg(ap, int);
	int num;
	int last = n % 10;
	int dig;
	int exp = 1;
	int i = 1;

	n = n / 10;
	num = n;

	if (last < 0)
	{
		print_c('-');
		num = -num;
		n = -n;
		last = -last;
		i++;
	}
	if (num > 0)
	{
		while (num / 10 != 0)
		{
			exp = exp * 10;
			num = num / 10;
		}
		num = n;
		while (exp > 0)
		{
			dig = num / exp;
			print_c(dig + '0');
			num = num - (dig * exp);
			exp = exp / 10;
			i++;
		}
	}

	print_c(last + '0');

	return (i);
}
