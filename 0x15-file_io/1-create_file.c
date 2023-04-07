#include "main.h"

/**
 * create_file - Creates a file with the given filename and writes the text
 * content to the file.
 * @filename: The name of the file to create
 * @text_content: The NULL terminated string to write to the file
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int file_n, bits_write, i;

	if (filename == NULL)
		return (-1);

	file_n = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (file_n == -1)
		return (-1);

	if (text_content != NULL)
	{
		for (i = 0; text_content[i] != '\0'; i++)
			;

		bits_write = write(file_n, text_content, i);
		if (bits_write == -1)
		{
			close(file_n);
			return (-1);
		}
	}

	close(file_n);
	return (1);
}
