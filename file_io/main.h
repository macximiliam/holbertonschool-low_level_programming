#ifndef	MAIN_H_
#define MAIN_H_
#include <unistd.h>
int _putchar(char c);
ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
int main(int argc, char *argv[]);
void copy_file(const char *file_from, const char *file_to);
void transfer_data(int fd_from, int fd_to, const char *file_from, const char *file_to);
void print_error(int code, const char *msg, const char *file);



#endif /* MAIN_H_ */
