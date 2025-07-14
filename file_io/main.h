#ifndef	MAIN_H_
#define MAIN_H_
#include <unistd.h>
int _putchar(char c);
ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
void check_args(int argc);
int open_from_file(const char *filename);
int open_to_file(const char *filename, int fd_from);
void copy_file_content(int fd_from, int fd_to, const char *file_from_name, const char *file_to_name);
void close_file_descriptor(int fd, int exit_code);


#endif /* MAIN_H_ */
