#include "shell.h"

/**
 * runTimeLoop - the shell main loop.
 *
 * @sh: neccessary varibles for the hsh shell.
 * @btn: button.
 *
 * Return: 0 on success -1 on faliure or exit.
*/
int runTimeLoop(hsh_t *sh, btns_t *btn)
{
	ssize_t Er;

	while (TRUE)
	{
		if (FROM_SCREEN)
			_put(PROMPT);

		CMD_TRY;
		Er = processInput(sh, btn);
		if (Er == _EXIT)
			break;

		if (Er == SKIP)
		{
			freeMem(sh);
			continue;
		}
		else
		{
			execute(sh);

			if (sh->id != 0)
			{
				wait(&(sh->waitStat));
				freeMem(sh);
			}
		}


	}
	return (_EXIT);/* later modification */
}

/**
 * execute - executes the command.
 * @sh: og variable.
 *
 * Return: 1 on success.
*/
int execute(hsh_t *sh)
{
	sh->id = fork();
	if (sh->id == -1)
		return (EXIT_FAILURE);

	if (sh->id == 0)
	{
		if (execve(sh->prg, sh->cmd, sh->environment) == -1)
		{
			perror(sh->er_name);
			freeMem(sh);
			sh->ex_child = _EXIT;
			return (_EXIT);
		}
	}

	return (1);
}
