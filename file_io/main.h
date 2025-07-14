#ifndef MAIN_H_
#define MAIN_H_

#include <unistd.h>
#include <elf.h>

/* Funciones generales de I/O */
int _putchar(char c);
ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
int main(int argc, char *argv[]);
void copy_file(const char *file_from, const char *file_to);
void transfer_data(int fd_from, int fd_to,
		   const char *file_from, const char *file_to);
void print_error(const char *msg, const char *file);

/* Funciones ELF */
void print_magic(unsigned char ident[]);
void print_class(unsigned char ident[]);
void print_data(unsigned char ident[]);
void print_version(unsigned char ident[]);
void print_osabi(unsigned char ident[]);
void print_abi_version(unsigned char ident[]);


/* Funciones de swap (endianness) */
uint16_t swap16(uint16_t v);
uint32_t swap32(uint32_t v);
uint64_t swap64(uint64_t v);

#endif /* MAIN_H_ */
