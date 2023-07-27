#include "shell.h"

/**
 * Terminate - terminate the program
 * @sh: big var.
*/
void Terminate(hsh_t *sh)
{
	int e;

	if (sh->exit_stat)
	{
		e = sh->exit_stat;
		free(sh);
		exit(e);
	}
	if (FROM_SCREEN)
	{
		free(sh);
		exit(0);
	}
	else
	{
		if (sh->cmd_state)
		{
			free(sh);
			exit(127);
		}
	}
	free(sh);
	exit(0);
}
/**
 * main - execution point of hsh shell
 *
 * @ac: arg count.
 * @av: arg volume.
 * @envp: environment.
 *
 * Return: 0 on success.
*/
int main(int ac, char *av[], char *envp[])
{
	hsh_t *sh;
	btns_t btn[] = {{"exit", exit_f}, {"env", env_f}, {NULL, NULL}};

	sh = malloc(sizeof(hsh_t));
	if (!sh)
		return (0);

	initialize(sh, envp, av[ac - 1]);
	checkInteractive(sh);

	if (runTimeLoop(sh, btn) == _EXIT)
		freeMem(sh);

	checkId(sh);

	Terminate(sh);
	return (0);
}
