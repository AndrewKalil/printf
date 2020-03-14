#include "holberton.h"

/**
 * character - prints character c
 * @ap: character to print
 * Return: number of characters printed
 */

int character(va_list ap)
{
	char ch;

	ch = va_arg(ap, int);

	_putchar(ch);

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
			_putchar(str[i]);
		}
	}

	else
	{
		str = "(nill)";
	}

		return (i);
}
