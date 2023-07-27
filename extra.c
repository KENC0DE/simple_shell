#include "shell.h"

/**
 * put_err_exit - printf error for exit.
 * @sh: big var.
 * Return: shit.
*/
int put_err_exit(hsh_t *sh)
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
	r_len = write(STDERR_FILENO, EXIT_ERR2, str_len(EXIT_ERR2));
	if (r_len == -1)
	{
		return (-1);
	}
	write(STDERR_FILENO, sh->cmd[1], str_len(sh->cmd[1]));
	write(STDERR_FILENO, "\n", 1);

	free(nc);
	free(sh->er_name);
	return (r_len);
}
