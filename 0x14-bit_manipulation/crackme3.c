#include <stdio.h>
#include <string.h>

/**
 * check_password - Check that a given password is correct
 *
 * @pwd: The password to be checked
 *
 * Return: 1 on success, 0 on failure
 */
int pass_checker(char *pwd)
{
	unsigned int xor = 0x046c6f48;
	unsigned char i;
	unsigned char mask = 0xff;
	
	if (strlen(pwd) != 4)
	{
		return 0;
	}
	
	for (i = 0; i < 4; i++)
	{
		if ((unsigned char)(pwd[i]) != ((xor >> (i * 8)) & mask))
		{
			return 0;
		}
	}

	return 1;
}

/**
 * main - Entry point
 *
 * @argc: Arguments count
 * @argv: Arguments array
 *
 * Return: 0 on success, error code otherwise
 */
int main(int argc, char **argv)
{
	int chkr;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s password\n", argv[0]);
		return 1;
	}
	
	chkr = pass_checker(argv[1]);

	if (chkr == 1)
	{
		printf("Congratulations!\n");
	}
	else
	{
		printf("ko\n");
		return 1;
	}

	return 0;
}

