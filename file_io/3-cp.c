#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

/**
 * print_error - Prints error message and code to stdout, then exits.
 * @code: Exit code to print.
 * @msg: Error message.
 * @arg: Related file or descriptor.
 */
void print_error(int code, const char *msg, const char *arg)
{
	printf("%s%s\n", msg, arg);
	printf("%d\n", code);
	exit(code);
}

/**
 * close_file - Closes a file descriptor.
 * @fd: The file descriptor to close.
 */
void close_file(int fd)
{
	if (close(fd) == -1)
	{
		printf("Error: Can't close fd %d\n", fd);
		printf("100\n");
		exit(100);
	}
}

/**
 * copy_file - Copies content from one file to another.
 * @file_from: Source file.
 * @file_to: Destination file.
 */
void copy_file(const char *file_from, const char *file_to)
{
	int fd_from, fd_to, r, w;
	char buffer[BUFFER_SIZE];

	fd_from = open(file_from, O_RDONLY);
	if (fd_from == -1)
		print_error(98, "Error: Can't read from file ", file_from);

	fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		close_file(fd_from);
		print_error(99, "Error: Can't write to ", file_to);
	}

	while ((r = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		w = write(fd_to, buffer, r);
		if (w != r)
		{
			close_file(fd_from);
			close_file(fd_to);
			print_error(99, "Error: Can't write to ", file_to);
		}
	}
	if (r == -1)
	{
		close_file(fd_from);
		close_file(fd_to);
		print_error(98, "Error: Can't read from file ", file_from);
	}

	close_file(fd_from);
	close_file(fd_to);
}

/**
 * main - Entry point for cp program.
 * @ac: Argument count.
 * @av: Argument vector.
 *
 * Return: 0 on success, otherwise exits with proper code.
 */
int main(int ac, char **av)
{
	if (ac != 3)
	{
		printf("Usage: cp file_from file_to\n");
		printf("97\n");
		exit(97);
	}

	copy_file(av[1], av[2]);
	return (0);
}
