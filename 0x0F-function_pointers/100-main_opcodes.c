#include <stdio.h>
#include <stdlib.h>

/**
 * main - print opcodes
 * @argc: argument count
 * @argv: argument vector
 * Return: Nothing
 */
int main(int argc, char **argv)
{
	int nbytes, i;
	int (*pfun)(int, char **) = NULL;
	unsigned char *pchar = NULL;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}

	nbytes = atoi(argv[1]);
	if (nbytes < 0)
	{
		printf("Error\n");
		exit(2);
	}

	pchar = (unsigned char *) main;

	for (i = 0; i < nbytes; i++)
	{
		printf("%x", *(pchar + i));
		if (i == nbytes - 1)
			printf("\n");
		else
			printf(" ");
	}
	return (0);
}
