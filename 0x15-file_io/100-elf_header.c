#include "main.h"

/**
 * print_elf_header - prints the information contained in the ELF header
 * @header: pointer to the ELF header structure
 **/
void print_elf_header(Elf64_Ehdr *header)
{
	int i;

	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x ", header->e_ident[i]);
	printf("\n");
	
	printf("  Class:                             %s\n",
			header->e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64" :
			header->e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" :
			"Invalid class");
	
	printf("  Data:                              %s\n",
			header->e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" :
			header->e_ident[EI_DATA] == ELFDATA2MSB ? "2's complement, big endian" :
			"Invalid data encoding");
	
	printf("  Version:                           %d%s\n",
			header->e_ident[EI_VERSION],
			header->e_ident[EI_VERSION] == EV_CURRENT ? " (current)" : "");
	printf("  OS/ABI:                            ");
	switch (header->e_ident[EI_OSABI])
	{
		case ELFOSABI_SYSV:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX\n");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD\n");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - Linux\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris\n");
			break;
		case ELFOSABI_IRIX:
			printf("UNIX - IRIX\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("UNIX - FreeBSD\n");
			break;
		case ELFOSABI_TRU64:
			printf("UNIX - TRU64\n");
			break;
		case ELFOSABI_ARM:
			printf("ARM\n");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone App\n");
			break;
		default:
			printf("<unknown: %x>\n", header->e_ident[EI_OSABI]);
	}

	printf("  ABI Version:                       %d\n",
			header->e_ident[EI_ABIVERSION]);

	printf("  Type:                              ");
	switch (header->e_type)
	{
		case ET_NONE:
			printf("NONE (Unknown type)\n");
			break;
		case ET_REL:
			printf("REL (Relocatable file)\n");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)\n");
			break;
		case ET_CORE:
			printf("CORE (Core file)\n");
			break;
		default:
			printf("<unknown: %x>\n", header->e_type);
	}

	printf("  Entry point address:               %lx\n",
			(unsigned long)header->e_entry);
}

/**
 * print_error - prints an error message to stderr and exits with status 98
 * @msg: the error message to print
 **/
void print_error(char *msg)
{
	fprintf(stderr, "%s\n", msg);
	exit(98);
}

/**

main - entry point for the program

@argc: the number of command line arguments

@argv: an array of pointers to the command line arguments

Return: 0 on success, 98 on error
**/
int main(int argc, char **argv)
{
	int fd;
	Elf64_Ehdr header;

	if (argc != 2)
		print_error("Usage: elf_header elf_filename");

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		print_error("Error: cannot open ELF file");
	
	if (read(fd, &header, sizeof(header)) != sizeof(header))
		print_error("Error: cannot read ELF header");

	if (header.e_ident[EI_MAG0] != ELFMAG0 ||
			header.e_ident[EI_MAG1] != ELFMAG1 ||
			header.e_ident[EI_MAG2] != ELFMAG2 ||
			header.e_ident[EI_MAG3] != ELFMAG3)
		print_error("Error: not an ELF file");

	print_elf_header(&header);

	if (close(fd) == -1)
		print_error("Error: cannot close ELF file");

	return (0);
}
