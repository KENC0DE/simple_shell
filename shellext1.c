#include "shell.h"

/**
 * cd_f - change directories.
 * @sh: big var.
 * Return: 0.
*/
int cd_f(hsh_t *sh)
{
	char *new_dir = NULL;

	if (sh->cmd[1])
	{
		if (str_comp(sh->cmd[1], "-") == 0)
		{
			if (chdir(sh->cwd) != 0)
				perror("Error");
			else
				setenv("PWD", sh->cwd, 1);
			return (SKIP);
		}
		else if (sh->cmd[1])
		{
			sh->cwd = getenv("PWD");
			new_dir = cwd_adjust(sh->cwd, sh->cmd[1]);
			if (chdir(new_dir) != 0)
				put_err_cd(sh);
			else
				setenv("PWD", new_dir, 1);
			if (new_dir)
				free(new_dir);
			return (SKIP);
		}
	}
	else
	{
		char *home = getenv("HOME");

		chdir(home);
		setenv("PWD", home, 1);
		return (SKIP);
	}
	return (0);
}

/**
 * put_err_cd - custom perror.
 * @sh: big var.
 * Return: int
*/
int put_err_cd(hsh_t *sh)
{
	int r_len;
	char *nc = intToCharArray(sh->nth_cmd);

	sh->er_name = str_concatSH(sh->sh_name, nc);
	r_len = write(STDERR_FILENO, sh->er_name, str_len(sh->er_name));
	if (r_len == -1)
	{
		free(sh->er_name);
		return (-1);
	}
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, sh->cmd[0], str_len(sh->cmd[0]));
	r_len = write(STDERR_FILENO, XDIR, str_len(XDIR));
	if (r_len == -1)
	{
		return (-1);
	}

	free(nc);
	free(sh->er_name);
	return (r_len);
}
