#include "holberton.h"

int binary(va_list ap)
{
	int i = 0;
	unsigned int n = va_arg(ap, unsigned int);
	char arr[100] = {'\0'};

	if (n == 0)
		print_c('0');
	while (n > 0)
	{
		arr[i] = (n % 2) + '0';
		n /= 2;
		i++;
	}

	return (1);
}
