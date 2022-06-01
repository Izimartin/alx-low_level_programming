/*
 * File: 2-append_text_to_file.c
 * Auth: izi martins
 */


#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * append_text_to_file - Appends text at the end of a file.
 *
 * @filename: Name of the file that will have text appended to.
 * @text_content: Content of the text.
 *
 * Return: 1 if success, otherwise -1.
 */

int append_text_to_file(const char *filename, char *text_content)
{
	ssize_t file;
	ssize_t b_write;
	size_t length;

	if (!filename)
		return (-1);

	file = open(filename, O_APPEND | O_WRONLY);
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
