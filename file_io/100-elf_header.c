#include "main.h"
#include <elf.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * print_error - Prints an error message and exits
 * @msg: Error message
 * @file: File name (can be NULL)
 */
void print_error(const char *msg, const char *file)
{
	if (file)
		fprintf(stderr, "Error: %s %s\n", msg, file);
	else
		fprintf(stderr, "Error: %s\n", msg);
	exit(98);
}

/**
 * check_elf - Verifies if file is an ELF
 * @ident: ELF identification array
 */
void check_elf(unsigned char *ident)
{
	if (memcmp(ident, ELFMAG, SELFMAG) != 0)
		print_error("Not an ELF file -", NULL);
}

/**
 * swap16 - Swaps byte order for 16-bit integer
 * @v: value
 * Return: swapped value
 */
uint16_t swap16(uint16_t v)
{ return (v >> 8) | (v << 8); }

/**
 * swap32 - Swaps byte order for 32-bit integer
 * @v: value
 * Return: swapped value
 */
uint32_t swap32(uint32_t v)
{ return (v >> 24) | ((v >> 8) & 0x0000FF00UL)
		 | ((v << 8) & 0x00FF0000UL)
		 | (v << 24);
}

/**
 * swap64 - Swaps byte order for 64-bit integer
 * @v: value
 * Return: swapped value
 */
uint64_t swap64(uint64_t v)
{ return (v >> 56) | ((v >> 40) & 0x000000000000FF00UL)
		 | ((v >> 24) & 0x0000000000FF0000UL)
		 | ((v >>  8) & 0x00000000FF000000UL)
		 | ((v <<  8) & 0x000000FF00000000UL)
		 | ((v << 24) & 0x0000FF0000000000UL)
		 | ((v << 40) & 0x00FF000000000000UL)
		 | (v << 56);
}

/**
 * print_magic - Prints ELF magic numbers
 * @ident: ELF identification array
 */
void print_magic(unsigned char ident[])
{
	int i;
	printf("ELF Header:\n  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%2.2x%s", ident[i], i + 1 < EI_NIDENT ? " " : "\n");
}

/**
 * print_class - Prints ELF class
 * @ident: ELF identification array
 */
void print_class(unsigned char ident[])
{
	const char *c;
	if (ident[EI_CLASS] == ELFCLASS32)
		c = "ELF32";
	else if (ident[EI_CLASS] == ELFCLASS64)
		c = "ELF64";
	else
		c = "<unknown>";
	printf("  %-35s%s\n", "Class:", c);
}

/**
 * print_data - Prints ELF data encoding
 * @ident: ELF identification array
 */
void print_data(unsigned char ident[])
{
	const char *d;
	if (ident[EI_DATA] == ELFDATA2LSB)
		d = "2's complement, little endian";
	else if (ident[EI_DATA] == ELFDATA2MSB)
		d = "2's complement, big endian";
	else
		d = "<unknown>";
	printf("  %-35s%s\n", "Data:", d);
}

/**
 * print_version - Prints ELF version
 * @ident: ELF identification array
 */
void print_version(unsigned char ident[])
{
	printf("  %-35s%u%s\n", "Version:", ident[EI_VERSION],
	   ident[EI_VERSION] == EV_CURRENT ? " (current)" : "");

}

/**
 * print_osabi - Prints ELF OS/ABI
 * @ident: ELF identification array
 */
void print_osabi(unsigned char ident[])
{
	const char *os;
	switch (ident[EI_OSABI]) {
	case ELFOSABI_SYSV:    os = "UNIX - System V"; break;
	case ELFOSABI_NETBSD:  os = "UNIX - NetBSD";   break;
	case ELFOSABI_LINUX:   os = "UNIX - Linux";    break;
	case ELFOSABI_SOLARIS: os = "UNIX - Solaris";  break;
	default:
		printf("  %-35s<unknown: %x>\n", "OS/ABI:", ident[EI_OSABI]);
		return;
	}
	printf("  %-35s%s\n", "OS/ABI:", os);
}

/**
 * print_abi_version - Prints ELF ABI version
 * @ident: ELF identification array
 */
void print_abi_version(unsigned char ident[])
{
	printf("  %-35s%u\n", "ABI Version:", ident[EI_ABIVERSION]);
}

/**
 * print_type_and_entry - Prints ELF file type and entry point
 * @hdr: Pointer to ELF header (32 or 64)
 * @ident: ELF identification array
 */
void print_type_and_entry(void *hdr, unsigned char ident[])
{
	uint16_t t;
	uint64_t e;
	const char *ts;
	if (ident[EI_CLASS] == ELFCLASS32) {
		Elf32_Ehdr *h = hdr;
		t = h->e_type;
		e = h->e_entry;
		if (ident[EI_DATA] == ELFDATA2MSB) {
			t = swap16(t);
			e = swap32((uint32_t)e);
		}
	} else {
		Elf64_Ehdr *h = hdr;
		t = h->e_type;
		e = h->e_entry;
		if (ident[EI_DATA] == ELFDATA2MSB) {
			t = swap16(t);
			e = swap64(e);
		}
	}
	switch (t) {
	case ET_NONE:  ts = "NONE (None)";              break;
	case ET_REL:   ts = "REL (Relocatable file)";  break;
	case ET_EXEC:  ts = "EXEC (Executable file)";  break;
	case ET_DYN:   ts = "DYN (Shared object file)";break;
	case ET_CORE:  ts = "CORE (Core file)";        break;
	default:       ts = "<unknown>";               break;
	}
	printf("  %-35s%s\n", "Type:", ts);
	printf("  %-35s0x%lx\n", "Entry point address:", e);
}

/**
 * main - Entry point
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char *argv[])
{
	int fd;
	unsigned char ident[EI_NIDENT];
	void *hdr;

	if (argc != 2)
		print_error("Usage: elf_header elf_filename", NULL);

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		print_error("Can't open file", argv[1]);

	if (read(fd, ident, EI_NIDENT) != EI_NIDENT)
		print_error("Can't read ELF identification from", argv[1]);

	check_elf(ident);
	if (lseek(fd, 0, SEEK_SET) < 0)
		print_error("Can't seek in file", argv[1]);

	if (ident[EI_CLASS] == ELFCLASS32) {
		Elf32_Ehdr *eh = malloc(sizeof(Elf32_Ehdr));
		if (!eh) print_error("Memory allocation failed", NULL);
		if (read(fd, eh, sizeof(Elf32_Ehdr)) != sizeof(Elf32_Ehdr))
			print_error("Can't read full ELF header from", argv[1]);
		hdr = eh;
	} else {
		Elf64_Ehdr *eh = malloc(sizeof(Elf64_Ehdr));
		if (!eh) print_error("Memory allocation failed", NULL);
		if (read(fd, eh, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr))
			print_error("Can't read full ELF header from", argv[1]);
		hdr = eh;
	}

	print_magic(ident);
	print_class(ident);
	print_data(ident);
	print_version(ident);
	print_osabi(ident);
	print_abi_version(ident);
	print_type_and_entry(hdr, ident);

	free(hdr);
	close(fd);
	return (0);
}
