#include "main.h"

void _execmd(char **tok_arr)
{
	char *cmd;

	if (tok_arr)
	{
		/* getting the first index as the command */
		cmd = tok_arr[0];

		if (_execmd(cmd, tok_arr, NULL) == -1)
			perror("Error");
	}
}
