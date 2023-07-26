#include "shell.h"

/**
 * findcmd - find if short hand command exists.
 * @cmd1: original variable.
 * @sh: sh.
 * @btn: btn.
 * Return: 1 on success and 0 on error.
*/
int findcmd(char *cmd1, hsh_t *sh, btns_t *btn)
{
	char *dr_token;
	int i, info;
	struct stat st;

	info = shell_do(sh, btn);
	if (info)
		return (info);

	if (stat(cmd1, &st) == 0)
		return (1);

	for (i = 0; sh->environment[i]; i++)
	{
		if (str_n_comp(sh->environment[i], "PATH=", 5) == 0)
		{
			sh->path = str_cpy((sh->environment[i] + 5));
			break;
		}
	}
	if (sh->path)
	{
		dr_token = strtok(sh->path, ":");
		while (dr_token)
		{
			sh->shortcmd = str_concat(dr_token, cmd1);
			if (stat(sh->shortcmd, &st) == 0)
			{
				sh->prg = sh->shortcmd;
				sh->alc = 1;
				return (1);
			}
			free(sh->shortcmd);
			dr_token = strtok(NULL, ":");
		}
	}
	return (NO_CMD);
}
