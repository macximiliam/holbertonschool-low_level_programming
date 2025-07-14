#include <stdio.h>
#include "main.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024


/**
 * check_args - Checks the number of command-line arguments.
 * @argc: The argument count.
 *
 * Description: If argc is not 3, prints a usage message to stderr
 * and exits with code 97.
 */
void check_args(int argc)
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
}

/**
 * open_from_file - Opens the source file for reading.
 * @filename: The name of the file to open.
 *
 * Return: The file descriptor of the opened file.
 * Description: If the file cannot be opened for reading, prints an error
 * message to stderr and exits with code 98.
 */
int open_from_file(const char *filename)
{
	int fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename);
		exit(98);
	}
	return (fd);
}

/**
 * open_to_file - Opens or creates the destination file for writing.
 * @filename: The name of the file to open/create.
 * @fd_from: The file descriptor of the source file (to close on error).
 *
 * Return: The file descriptor of the opened/created file.
 * Description: If the file cannot be created or written to, prints an error
 * message to stderr and exits with code 99. Closes fd_from
 * if an error occurs here.
 */
int open_to_file(const char *filename, int fd_from)
{
	int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC,
				  S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	if (fd == -1)
	{
		close_file_descriptor(fd_from, 100); /* Try to close fd_from */
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
		exit(99);
	}
	return (fd);
}

/**
 * copy_file_content - Copies data from source to destination file.
 * @fd_from: File descriptor of the source file.
 * @fd_to: File descriptor of the destination file.
 * @file_from_name: Name of the source file (for error messages).
 * @file_to_name: Name of the destination file (for error messages).
 *
 * Description: Reads 1024 bytes at a time from fd_from and writes them
 * to fd_to. Handles read/write errors and exits accordingly.
 */
void copy_file_content(int fd_from, int fd_to,
					   const char *file_from_name, const char *file_to_name)
{
	ssize_t bytes_read, bytes_written;
	char buffer[BUFFER_SIZE];

	while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written == -1 || bytes_written != bytes_read)
		{
			close_file_descriptor(fd_from, 100);
			close_file_descriptor(fd_to, 100);
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to_name);
			exit(99);
		}
	}

	if (bytes_read == -1)
	{
		close_file_descriptor(fd_from, 100);
		close_file_descriptor(fd_to, 100);
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n",
				file_from_name);
		exit(98);
	}
}

/**
 * close_file_descriptor - Closes a file descriptor.
 * @fd: The file descriptor to close.
 * @exit_code: The exit code to use if closing fails.
 *
 * Description: If closing the file descriptor fails, prints an error
 * message to stderr and exits with the given exit_code.
 */
void close_file_descriptor(int fd, int exit_code)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(exit_code);
	}
}

/**
 * main - Copies the content of a file to another file.
 * @argc: Number of arguments passed to the program.
 * @argv: Array of strings with the arguments.
 *
 * Return: 0 on success.
 * 97 if the number of arguments is incorrect.
 * 98 if file_from does not exist or cannot be read.
 * 99 if file_to cannot be created or written to.
 * 100 if a file descriptor cannot be closed.
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to;

	check_args(argc);

	fd_from = open_from_file(argv[1]);
	fd_to = open_to_file(argv[2], fd_from);

	copy_file_content(fd_from, fd_to, argv[1], argv[2]);

	close_file_descriptor(fd_from, 100);
	close_file_descriptor(fd_to, 100);

	return (0);
}
