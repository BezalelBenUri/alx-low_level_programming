#include "main.h"

/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename: Name of the file to append.
 * @text_content: NULL terminated string to write to the file.
 * Return: 1 on success, -1 on failure.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int file_n;
	size_t text_len;
	ssize_t bytes_written;

	if (filename == NULL)
	{
		return (-1);
	}

	file_n = open(filename, O_WRONLY | O_APPEND | O_CREAT, 0600);

	if (file_n == -1)
	{
		return (-1);
	}

	if (text_content == NULL)
	{
		close(file_n);
		return (1);
	}

	text_len = strlen(text_content);
	bytes_written = write(file_n, text_content, text_len);

	close(file_n);

	if (bytes_written == -1 || (size_t)bytes_written != text_len)
	{
		return (-1);
	}

	return (1);
}
