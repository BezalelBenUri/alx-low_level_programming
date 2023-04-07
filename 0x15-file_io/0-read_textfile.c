#include "main.h"

/**
 * read_textfile - Reads a text file and prints it to the POSIX
 * standard output.
 *
 * @filename: Pointer to the name of the file to be read.
 * @letters: Number of letters to be read from the file.
 *
 * Return: The actual number of letters read and printed,
 * or 0 if an error occurs.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int file_n;
	char *buffer;
	ssize_t bytes_read, bytes_written;

	if (filename == NULL)
	{
		return (0);
	}

	file_n = open(filename, O_RDONLY);

	if (file_n == -1)
	{
		return (0);
	}

	buffer = malloc(sizeof(char) * letters);

	if (buffer == NULL)
	{
		close(file_n);
		return (0);
	}
	bytes_read = read(file_n, buffer, letters);

	if (bytes_read == -1)
	{
		close(file_n);
		free(buffer);
		return (0);
	}
	bytes_written = write(STDOUT_FILENO, buffer, bytes_read);

	close(file_n);
	free(buffer);

	if (bytes_written != bytes_read)
		return (0);
	return (bytes_read);
}
