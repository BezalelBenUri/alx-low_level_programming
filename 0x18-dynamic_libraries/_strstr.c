#include "main.h"

char *_strstr(char *haystack, char *needle)
{
	while (*haystack != '\0')
	{
		char *h = haystack;
		char *n = needle;

		while (*n == *haystack && *n != '\0' && *haystack != '\0')
		{
			n++;
			haystack++;
		}
		if (*n == '\0')
			return (h);
		haystack = h + 1;
	}
	return (NULL);
}
