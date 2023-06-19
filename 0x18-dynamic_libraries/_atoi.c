#include "main.h"

int _atoi(char *s)
{
	int val = 0;
	int neg = 1;
	while (*s == ' ' || *s == '\t')
	{
		s++;
	}
	if (*s == '-')
	{
		neg = -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		val = val * 10 + (*s - '0');
		s++;
	}
	return (val * neg);
}
