#include "shell.h"

/**
 * getCommand - read from the stdin.
 * @sh: uni variable.
 * Return: -1 on error.
*/
ssize_t getCommand(hsh_t *sh)
{
	ssize_t eof;

	while (TRUE)
	{
		eof = getline(&sh->line, &sh->bytes, stdin);
		if (eof == -1 || sh->line[eof - 1] == '\n')
			break;
	}
	return (eof);
}
/**
 * processInput - processes input from stdin
 * @sh: shell vars.
 * @btn: the button.
 * Return: -1 on failure.
*/
ssize_t processInput(hsh_t *sh, btns_t *btn)
{
	int ptrs, info;

	sh->line = NULL, sh->bytes = 0;
	freeMem(sh);

	sh->eof = getCommand(sh);
	if (sh->eof != -1)
	{
		ptrs = adjust_numOfArgs(sh);
		if (!ptrs)
			return (SKIP);

		if (sh->line[0] != '\n')
		{
			tokenize(sh, ptrs);
			info = findcmd(sh->cmd[0], sh, btn);
			return (errorhandle(sh, info));
		}
		else
		{
			if (sh->line)
				freeMem(sh);

			return (SKIP);
		}
	}
	return (_EXIT);
}
