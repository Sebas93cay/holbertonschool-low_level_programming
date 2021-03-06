# include "holberton.h"

#if 0
/**
 * exit99 - function to execute error 99
 * @file: - file to print in error message
 * Return: nothing
 */
void exit99(char *file)
{
	dprintf(2, "Error: Can't write to %s\n", file);
	exit(99);
}


/**
 * exit100 - function to execute in error 100
 * @fd: file descriptor to pirnt in error message
 * Return: nothing
 */
void exit100(int fd)
{
	dprintf(2, "Error: Can't close fd %d\n", fd);
	exit(100);
}
#endif

/**
 * main - copies the content of a file to another file.
 * @argc: argument counts
 * @argv: argument vector
 * Return: always zero
 */
int main(int argc, char **argv)
{
	int file1, file2;
	char buff[1024];
	int bytes = 1024;

	if (argc != 3)
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n"), exit(97);

	file1 = open(argv[1], O_RDONLY);
	if (file1 == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	file2 = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC,
		     S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	if (file2 == -1)
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]), exit(99);

	while ((bytes = read(file1, buff, 1024)) > 0)
	{
		if (write(file2, buff, bytes) != bytes)
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]), exit(99);
	}
	if (bytes == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	if (close(file1) == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file1), exit(100);
	if (close(file2) == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file2), exit(100);

	return (0);
}
