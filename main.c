#include "main.h"

/**
 * main - building a simple shell
 * @arc: arc
 * @argv: argv
 * Return: 0 on success
 */

int main()
{
	char *call_on = "simshell:~# ";
	char *lineptr = NULL, *c_lineptr = NULL, *tok;
	char **tok_arr;
	size_t a = 0;
	ssize_t read_chars;
	const char *delim = " ";
	int tok_count = 0, i = 0;

	/* Infinite loop for shell */
	while (1)
	{
		printf("%s", call_on);
		read_chars = getline(&lineptr, &a, stdin);

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
		while (tok != NULL)
		{
			tok_count++;
			tok = strtok(NULL, delim);
		}
		tok_count++;
	

		/* allocate space for array of strings from strtok */
		tok_arr = malloc(sizeof(char *) * tok_count);

		/* break the copy string */
		tok = strtok(c_lineptr, delim);
		while (tok != NULL)
		{
			tok_arr[i] = malloc(sizeof(char) * strlen(tok));
			strcpy(tok_arr[i], tok);
			tok = strtok(NULL, delim);
			i++;
		}
		tok_arr[i] = NULL;

		printf("%s\n", lineptr);

		_execmd(tok_arr);

		/* allocated memory freed up here */
		free(c_lineptr);
		free(lineptr);
	}
	return (0);
}
