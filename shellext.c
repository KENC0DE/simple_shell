#include "shell.h"

/**
 * exit_f - execute exit.
 * @sh: big var.
 * Return: int.
*/
int exit_f(hsh_t *sh)
{
	if (sh->signal)
	{
		sh->exit_stat = sh->signal;
		return (_EXIT);
	}
	if (sh->cmd[1] == NULL)
	{
		sh->exit_stat = 0;
		return (_EXIT);
	}
	else if (sh->cmd[1])
	{
		sh->exit_stat = atoi(sh->cmd[1]);
		if (sh->exit_stat == 0 || sh->exit_stat < 0)
		{
			put_err_exit(sh);
			if (!FROM_SCREEN)
				sh->exit_stat = 2;
			return (SKIP);
		}
		return (_EXIT);
	}
	return (0); /* return for nothing to do */
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

/**
 * setenv_f - set's invironment.
 * @sh: big var.
 * Return: SKIP.
*/
int setenv_f(hsh_t *sh)
{
	if (setenv(sh->cmd[1], sh->cmd[2], 1) != 0)
	{
		if (FROM_SCREEN)
			perror("Error");
	}
	return (SKIP);
}

/**
 * unsetenv_f - unsets variable
 * @sh: big var.
 * Return: SKIP.
*/
int unsetenv_f(hsh_t *sh)
{
	if (unsetenv(sh->cmd[1]) != 0)
	{
		if (FROM_SCREEN)
			perror("Error");
	}
	return (SKIP);
}
