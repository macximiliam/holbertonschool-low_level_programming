#include <fcntl.h>
#include <unistd.h>

/**
 * append_text_to_file - Appends text at the end of an existing file.
 * @filename: Name of the file.
 * @text_content: NULL-terminated string to append to the file.
 *
 * Return: 1 on success, -1 on failure.
 * Do not create the file if it does not exist.
 * If text_content is NULL, do not write anything. Return 1 if file exists.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, wr_status;
	size_t len = 0;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);
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
