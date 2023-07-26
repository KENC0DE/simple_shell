#include "shell.h"

/**
 * adjust_numOfArgs - allocate the right ammount of pointer for the arguments.
 *
 * @sh: hsh struct variable.
 *
 * Return: 1 on success. -1 on failur.
*/
int adjust_numOfArgs(hsh_t *sh)
{
	int i;
	int num_of_pointers = 0;

	for (i = 0; sh->line[i] != '\n'; i++)
	{
		if (sh->line[i] != ' ' &&
		(sh->line[i + 1] == ' ' || sh->line[i + 1] == '\n'))
			num_of_pointers++;
	}

	sh->cmd = malloc(sizeof(char *) * (num_of_pointers + 1));
	if (!sh->cmd)
		return (0);

	for (i = 0; i < num_of_pointers + 1; i++)
		sh->cmd[i] = NULL;

	return (num_of_pointers);
}
