#include "main.h"

/**
 * rev_string - Reverses a string.
 *
 * @s: The string to be reversed.
 */
void rev_string(char *s)
{
	int length = 0, c;
	char *begin, *end, temp;
	
	/* Find the length of the string */
	while (s[length] != '\0')
		length++;
	
	/* Set the begin and end pointers to the start
   * and end of the string */
	begin = s;
	end = s;
	for (c = 0; c < length - 1; c++)
		end++;
	
	/* Swap the characters of the string */
	for (c = 0; c < length / 2; c++)
	{
		temp = *end;
		*end = *begin;
		*begin = temp;

		/* Update pointers to point to the next
		 * * * character in the string */
		begin++;
		end--;
  }
}

