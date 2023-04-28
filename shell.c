#include "main.h"

/**
 * main - A simple UNIX command interpreter
 * @arc: argument counter
 * @arv: argument vector
 * Return: 0 on success, 1 on error
 */
int shell(int arc, char **arv)
{
	info_s infor[] = { INFO_INIT };
	int fp = 2;

	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (fp)
		: "r" (fp));

	if (arc == 2)
	{
		fp = open(arv[1], O_RDONLY);
		if (fp == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_puts(arv[0]);
				_puts(": 0: Can't open ");
				_puts(arv[1]);
				_putchar('\n');
				_putchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		infor->readfd = fp;
	}
	populate_env_list(infor);
	_read_history(infor);
	hsh(infor, arv);
	return (EXIT_SUCCESS);
}
