#ifndef ELF_HEADER_H
#define ELF_HEADER_H

#include <sys/types.h>
#include <stdint.h>  /* Para tipos de ancho fijo */

#define EI_NIDENT 16
#define ELF_MAGIC "\177ELF"
#define ELF_MAGIC_SIZE 4

/* Constantes para clases ELF */
#define ELFCLASSNONE 0
#define ELFCLASS32   1
#define ELFCLASS64   2

/* Constantes para endianness */
#define ELFDATANONE  0
#define ELFDATA2LSB  1
#define ELFDATA2MSB  2

/**
 * struct elf64_hdr - ELF 64-bit header structure
 * @e_ident: Magic number and other info
 * @e_type: Object file type
 * @e_machine: Architecture
 * @e_version: Object file version
 * @e_entry: Entry point virtual address
 * @e_phoff: Program header table file offset
 * @e_shoff: Section header table file offset
 * @e_flags: Processor-specific flags
 * @e_ehsize: ELF header size in bytes
 * @e_phentsize: Program header table entry size
 * @e_phnum: Program header table entry count
 * @e_shentsize: Section header table entry size
 * @e_shnum: Section header table entry count
 * @e_shstrndx: Section header string table index
 */
struct elf64_hdr
{
    uint8_t e_ident[EI_NIDENT];
    uint16_t e_type;
    uint16_t e_machine;
    uint32_t e_version;
    uint64_t e_entry;
    uint64_t e_phoff;
    uint64_t e_shoff;
    uint32_t e_flags;
    uint16_t e_ehsize;
    uint16_t e_phentsize;
    uint16_t e_phnum;
    uint16_t e_shentsize;
    uint16_t e_shnum;
    uint16_t e_shstrndx;
};

/* Function prototypes */

/**
 * print_error - Prints an error message and exits
 * @message: The error message to print
 */
void print_error(const char *message);

/**
 * print_magic - Prints the ELF magic numbers
 * @e_ident: Pointer to the ELF identification bytes
 */
void print_magic(const uint8_t *e_ident);

/**
 * get_class - Gets the ELF class description
 * @class: The ELF class byte
 * Return: String describing the class
 */
const char *get_class(uint8_t class);

/**
 * get_data - Gets the ELF data encoding description
 * @data: The ELF data byte
 * Return: String describing the data encoding
 */
const char *get_data(uint8_t data);

/**
 * get_osabi - Gets the OS/ABI description
 * @osabi: The ELF OS/ABI byte
 * Return: String describing the OS/ABI
 */
const char *get_osabi(uint8_t osabi);

/**
 * get_type - Gets the ELF type description
 * @type: The ELF type value
 * Return: String describing the type
 */
const char *get_type(uint16_t type);

/**
 * print_elf_info - Prints all ELF header information
 * @header: Pointer to the ELF header structure
 */
void print_elf_info(struct elf64_hdr *header);

/**
 * verify_elf - Verifies if the file is a valid ELF
 * @fd: File descriptor
 * @header: Pointer to store the ELF header
 */
void verify_elf(int fd, struct elf64_hdr *header);

#endif /* ELF_HEADER_H */
