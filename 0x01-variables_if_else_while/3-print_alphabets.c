#include <stdio.h>

/* printing the alphabet */
int main(void)
{
	int l;

	for (l = 'a'; l <= 'z'; l++)
		putchar(l);
	for (l = 'A'; l <= 'Z'; l++)
		putchar(l);
		putchar('\n');

	return (0);
}
