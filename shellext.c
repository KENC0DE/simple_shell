#include "shell.h"

/**
 * exit_f - execute exit.
 * @sh: big var.
 * Return: int.
*/
int exit_f(hsh_t *sh)
{
	sh->exit_stat = 0;
	return (_EXIT);
}

/**
 * env_f - execute printenve.
 * @sh: big var.
 * Return: int
*/
int env_f(hsh_t *sh)
{
	int i;

	for (i = 0; sh->environment[i]; i++)
	{
		_put(sh->environment[i]);
		_put("\n");
	}

	return (SKIP);
}
