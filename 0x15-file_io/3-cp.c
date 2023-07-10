#include <stdio.h>
#include <stdlib.h>
#include "main.h"

char *create_guard(char *filename);
void exit_filename(int bc);

/**
 * create_guard - Allocates 1024 bytes for a bufer
 * @filename: The name of the file guard is storing chars for
 *
 * Return: A pointer to the newly allocated buffer
 */

char *create_guard(char *filename)
{
	char *guard;

	guard = malloc(sizeof(char) * 1024);

	if (guard == NULL)
	{
		dprintf(STDERR_FILENO, "Error:Can't write to %s/n", filename);
		exit(99);
	}

	return (guard);
}

/**
 * exit_filename - Closes and exits file descriptors
 * @bc: The file descriptor to be closed and exited
 */

void exit_filename(int bc)
{
	int x;

	x = close(bc);

	if (x == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close bc %d\n", bc);
		exit(100);
	}
}

/**
 * main - copies the contents of a file to another
 * @argc: The number of arguments supplied to the program
 * @argv: An array of pointers to the arguments
 *
 * Return: 1 on success
 *
 * Description: If the argument count is incorrect - exit code 97.
 *              If file_from does not exist or cannot be read - exit code 98.
 *              If file_to cannot be created or written to - exit code 99.
 *              If file_to or file_from cannot be closed - exit code 100.
 */

int main(int argc, char *argv[])
{
	int R, W, from, to;
	char *guard;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	guard = create_guard(argv[2]);
	from = open(argv[1], O_RDONLY);
	R = read(from, guard, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || R == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
			free(guard);
			exit(98);
		}

		W = write(to, guard, R);
		if (to == -1 || W == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			free(guard);
			exit(99);
		}

		R = read(from, guard, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);
	}

	while (R > 0);

	free(guard);
	exit_filename(from);
	exit_filename(to);

	return (1);
}
