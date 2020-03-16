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
