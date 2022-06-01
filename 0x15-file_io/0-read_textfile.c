/*
 * File: 0-read_textfile.c
 * Auth: izi martins
 */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * read_textfile - Reads a text file and prints it to the POSIX standard output
 * .
 *
 * @filename: The pathfile to the file to be read.
 * @letters: size_t, the amount of letters to be read and printed.
 *
 * Return: The actual number of letters it could read and print.
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int file;
	int b_read;
	int b_write;
	char *buffer;

	if (!filename || letters == 0)
		return (0);

	file = open(filename, O_RDONLY);

	if (file < 0)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (!buffer)
	{
		close(file);
		return (0);
	}

	b_read = read(file, buffer, letters);
	close(file);
	if (b_read < 0)
	{
		free(buffer);
		return (0);
	}

	b_write = write(STDOUT_FILENO, buffer, b_read);
	free(buffer);

	if (b_write < 0)
		return (0);

	return (b_write);
}
