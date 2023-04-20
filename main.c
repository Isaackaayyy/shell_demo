#include "main.h"

/**
 * main - building a simple shell
 * Return: 0 on success
 */

int main(void)
{
	char *call_on = "simshell:~# ";
	char *lineptr = NULL, *c_lineptr = NULL, tok;
	size_t n = 0;
	ssize_t read_chars;
	const char *delim = " \n";
	int tok_count = 0;

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
		/* tok = strtok(linptr, delim); */

		/* find out how many tokens are present */
		while (lineptr != NULL)
		{
			tok = strtok(linptr, delim);
			tok_count++;
		}

		/* allocate space for array of strings from strtok */
		tok_arr = malloc(sizeof(char *) * tok_count);


		printf("%s\n", lineptr);

		/* allocated memory freed up here */
		free(lineptr);
	}
	return (0);
}
