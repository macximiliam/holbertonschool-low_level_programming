/* File: print_magic_utils.c */
#include "main.h"
#include <stdio.h>
#include <elf.h>

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

/* File: print_encoding_utils.c */
#include "main.h"
#include <stdio.h>
#include <elf.h>

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

/* File: print_osabi_utils.c */
#include "main.h"
#include <stdio.h>
#include <elf.h>

/**
 * print_osabi - Prints ELF OS/ABI
 * @ident: ELF identification array
 */
void print_osabi(unsigned char ident[])
{
	const char *os;

	switch (ident[EI_OSABI])
	{
	case ELFOSABI_SYSV:
		os = "UNIX - System V";
		break;
	case ELFOSABI_NETBSD:
		os = "UNIX - NetBSD";
		break;
	case ELFOSABI_LINUX:
		os = "UNIX - Linux";
		break;
	case ELFOSABI_SOLARIS:
		os = "UNIX - Solaris";
		break;
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
