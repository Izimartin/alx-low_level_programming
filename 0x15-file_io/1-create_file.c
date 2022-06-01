/*
 * File: 1-create_file.c
 * Auth: izi martins
 */


#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * create_file - Creates a file with read and write permissions for user if the
 * file does not exist. Truncates the file if it exists. Fills the file with
 * the contents of text_content.
 *
 * @filename: Name of the file that is to be created if it doesn't exist.
 * @text_content: Content of the text.
 *
 * Return: 1 if success, otherwise -1.
 */

int create_file(const char *filename, char *text_content)
{
	ssize_t file;
	ssize_t b_write;
	size_t length;

	if (!filename)
		return (-1);

	file = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (file == -1)
		return (-1);

	b_write = 0;
	if (text_content)
	{
		for (length = 0; text_content[length]; length++)
			;

		b_write = write(file, text_content, length);
	}
	close(file);
	if (b_write == -1)
		return (-1);

	return (1);
}
