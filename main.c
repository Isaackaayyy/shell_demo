#include "main.h"

/**
 * main - building a simple shell
 * @arc: arc
 * @argv: argv
 * Return: 0 on success
 */

int main(int ac, char **argv)
{
	char *call_on = "simshell:~# ";
	char *lineptr = NULL, *c_lineptr = NULL, *tok;
	size_t n = 0;
	ssize_t read_chars;
	const char *delim = " ";
	int tok_count = 0, i = 0;

	void(ac);

	/* Infinite loop for shell */
	while (1)
	{
		printf("%s", call_on);
		read_chars = getline(&lineptr, &n, stdin);

		/* check if getline function reaches EOF or user uses CTRL + D or fails */
		if (read_chars == -1)
		{
			printf("exit...\n\n\nexit.\n");
			return (-1);
		}

		/* allocate space for the copied pointer */
		c_lineptr = malloc(sizeof(char) * read_chars);
		if (c_lineptr == NULL)
			return (-1);

		/* copy string to c_linptr */
		strcpy(c_lineptr, lineptr);

		/* break the string into different string */
		tok = strtok(lineptr, delim);

		/* find out how many tokens are present */
		while (lineptr != NULL)
		{
			tok_count++;
			tok = strtok(NULL, delim);
		}
		tok_count++;
	

		/* allocate space for array of strings from strtok */
		argv = malloc(sizeof(char *) * tok_count);

		/* break the copy string */
		tok = strtok(c_lineptr, delim);
		while (tok != NULL)
		{
			argv[i] = malloc(sizeof(char) * strlen(tok));
			strcpy(argv[i], tok);
			tok = strtok(NULL, delim);
			i++;
		}
		argv[i] = NULL;

		printf("%s\n", lineptr);

		/* allocated memory freed up here */
		free(lineptr);
	}
	return (0);
}
