#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <stdio.h>
#define BUFFER_SIZE 1024

int create_file(const char *filename, char *text_content);
ssize_t read_textfile(const char *filename, size_t letters);
int _putchar(char c);
int append_text_to_file(const char *filename, char *text_content);

int copy_file(const char *file_from, const char *file_to);
void print_error_and_exit(const char *error_message, const char *file_name, int exit_code);

#endif
