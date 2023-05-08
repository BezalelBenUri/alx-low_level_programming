#include "main.h"

/**
 * append_text_to_file - appends the specified text content to the end of the
 * specified file
 *
 * @filename: the name of the file to append to
 * @text_content: the text content to append
 *
 * Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, written, length;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);

	if (text_content != NULL)
	{
		for (length = 0; text_content[length] != '\0'; length++)
			;
		written = write(fd, text_content, length);
		if (written != length)
		{
			close(fd);
			return (-1);
		}
	}

	close(fd);
	return (1);
}

