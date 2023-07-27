#include "shell.h"

/**
 * exit_f - execute exit.
 * @sh: big var.
 * Return: int.
*/
int exit_f(hsh_t *sh)
{
	if (sh->cmd[1] == NULL)
	{
		sh->exit_stat = 0;
		return (_EXIT);
	}
	else if (sh->cmd[1])
	{
		sh->exit_stat = atoi(sh->cmd[1]);
		return (_EXIT);
	}
	return (0);
}
	

/**
 * env_f - execute printenve.
 * @sh: big var.
 * Return: int
*/
int env_f(hsh_t *sh)
{
	int i;

	if (sh->cmd[1] == NULL)
	{
		for (i = 0; sh->environment[i]; i++)
		{
			_put(sh->environment[i]);
			_put("\n");
		}
		return (SKIP);
	}
	return (0);
}
