#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFFER_SIZE 1024

/**
 * print_error - Prints an error message to stderr and exits
 * @code: Exit code
 * @msg: Error message
 * @file: File name or descriptor value to include
 */
void print_error(int code, const char *msg, const char *file)
{
	if (file)
		dprintf(STDERR_FILENO, "%s%s\n", msg, file);
	else
		dprintf(STDERR_FILENO, "%s\n", msg);
	exit(code);
}

/**
 * transfer_data - Reads from fd_from and writes to fd_to in chunks
 * @fd_from: Source file descriptor
 * @fd_to: Destination file descriptor
 * @file_from: Source file name for errors
 * @file_to: Destination file name for errors
 */
void transfer_data(int fd_from, int fd_to,
		   const char *file_from, const char *file_to)
{
	int r_bytes, w_bytes;
	char buffer[BUFFER_SIZE];

	while ((r_bytes = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		w_bytes = write(fd_to, buffer, r_bytes);
		if (w_bytes != r_bytes)
			print_error(99, "Error: Can't write to ", file_to);
	}
	if (r_bytes == -1)
		print_error(98, "Error: Can't read from file ", file_from);
}

/**
 * copy_file - Copies the content of a file to another
 * @file_from: Source file name
 * @file_to: Destination file name
 */
void copy_file(const char *file_from, const char *file_to)
{
	int fd_from, fd_to, first_read, first_write;
	char buffer[BUFFER_SIZE];

	fd_from = open(file_from, O_RDONLY);
	if (fd_from == -1)
		print_error(98, "Error: Can't read from file ", file_from);

	first_read = read(fd_from, buffer, BUFFER_SIZE);
	if (first_read == -1)
	{
		close(fd_from);
		print_error(98, "Error: Can't read from file ", file_from);
	}

	fd_to = open(file_to, O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		close(fd_from);
		print_error(99, "Error: Can't write to ", file_to);
	}

	first_write = write(fd_to, buffer, first_read);
	if (first_write != first_read)
	{
		close(fd_from);
		close(fd_to);
		print_error(99, "Error: Can't write to ", file_to);
	}

	transfer_data(fd_from, fd_to, file_from, file_to);

	if (close(fd_from) == -1)
		print_error(100, "Error: Can't close fd ", file_from);
	if (close(fd_to) == -1)
		print_error(100, "Error: Can't close fd ", file_to);
}

/**
 * main - Entry point
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: 0 on success, exits with code on failure
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
		print_error(97, "Usage: cp file_from file_to", NULL);

	copy_file(argv[1], argv[2]);

	return (0);
}
