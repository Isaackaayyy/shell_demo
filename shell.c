#include "main.h"

/**
 * main - A simple UNIX command interpreter
 * @arc: argument counter
 * @arv: argument vector
 * Return: 0 on success, 1 on error
 */
int main(int arc, char **arv)
{
	int c = 0, status = 1;
	char *line;
	int get_line, n;
	char *delim = " \n";
	char *tok;

	while (status)
	{
		if (isatty(0) == 1)
			printf("Shell $ ");

		get_line = getline(&line, &n, stdin);
		if (get_line == -1)
		{
			perror("getline error");
			exit(EXIT_FAILURE);
		}
		
		line_dup = strdup(line);

		tok = strtok(line_dup, delim);

		while (tok)
		{
			c++;
			tok = strtok(NULL, delim);
		}

		arv = malloc(sizeof(char *) * (c + 1));

		
