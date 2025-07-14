#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

/**
 * create_file - Creates a file with specified content and permissions.
 * @filename: Name of the file to create.
 * @text_content: NULL-terminated string to write into the file.
 *
 * Return: 1 on success, -1 on failure.
 * If text_content is NULL, creates an empty file.
 * If the file exists, truncate it. Do not change its permissions.
 * The created file must have permissions rw------- (0600).
 */
int create_file(const char *filename, char *text_content)
{
	int fd, wr_status;
	size_t len = 0;

	if (filename == NULL)
		return (-1);


	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);

	if (text_content != NULL)
	{
		while (text_content[len] != '\0')
			len++;
		wr_status = write(fd, text_content, len);
		if (wr_status == -1 || (size_t)wr_status != len)
		{
			close(fd);
			return (-1);
		}
	}

	close(fd);
	return (1);
}
