#include "main.h"

/**
 * main - Entry point
 * @argc: Number of command line arguments
 * @argv: Array of command line arguments
 * Return: 0 on success, 97-100 on failure
 */
int main(int argc, char *argv[])
{
	int result;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", argv[0]);
		exit(97);
	}

	result = copy_file(argv[1], argv[2]);

	return (result);
}

/**
 * copy_file - Copies contents of one file to another
 * @file_from: Source file name
 * @file_to: Destination file name
 * Return: 0 on success, 97-100 on failure
 */
int copy_file(const char *file_from, const char *file_to)
{
	int file_from_file, file_to_file;
	ssize_t bytes_read, bytes_written;
	char buffer[BUFFER_SIZE];

	file_from_file = open(file_from, O_RDONLY);
	if (file_from_file == -1)
	{
		print_error_and_exit("Error: Can't read from file", file_from, 98);
	}

	file_to_file = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR |
			S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	if (file_to_file == -1)
	{
		print_error_and_exit("Error: Can't write to file", file_to, 99);
	}

	while ((bytes_read = read(file_from_file, buffer, BUFFER_SIZE)) > 0)
	{
		bytes_written = write(file_to_file, buffer, bytes_read);
		if (bytes_written != bytes_read)
		{
			print_error_and_exit("Error: Can't write to file", file_to, 99);
		}
	}

	if (bytes_read == -1)
	{
		print_error_and_exit("Error: Can't read from file", file_from, 98);
	}

	if (close(file_from_file) == -1 || close(file_to_file) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close file descriptor\n");
		exit(100);
	}

	return (0);
}

/**
 * print_error_and_exit - Prints error message, file name,exit code
 * @error_message: Error message
 * @file_name: File name
 * @exit_code: Exit code
 */
void print_error_and_exit(const char *error_message,
		const char *file_name, int exit_code)
{
	dprintf(STDERR_FILENO, "%s %s\n", error_message, file_name);
	exit(exit_code);
}
