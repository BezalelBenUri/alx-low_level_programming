#include <stdio.h>

/**
* main - Print the alphabet in lowercase letters, except for e and q
*
* Return: Always 0 (Success)
*/
int main(void)
{
		char alphabet;

		for (alphabet = 'a'; alphabet <= 'z'; alphabet++)
		{
		if (alphabet != 'e' && alphabet != 'q')
		putchar(alphabet);
		}
		putchar('\n');

	return (0);
}
