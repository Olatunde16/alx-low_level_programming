#include  <stdlib.h>
#include "main.h"

/**
 * read_textfile - reads a text file and prints it to POSIX stdout
 * @filename: pointer to the name of the file
 * @letters: The number o letters the function should read
 * and print
 *
 * Return: if file cannot be opened or read or is NULL or if it fails - 0
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t O, R, W;
	char *guard;

	if (filename ==  NULL)
		return (0);

	guard = malloc(sizeof(char) * letters);
	if (guard == NULL)
		return (0);

	O = open(filename, O_RDONLY);
	R = read(O, guard, letters);
	W = write(STDOUT_FILENO, guard, R);

	if (O == -1 || R == -1 || W == -1 || W != R)
	{
		free(guard);
		return (0);
	}

	free(guard);
	close(O);

	return (W);
}
