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

/**
 * cwd_adjust - addjust the directory.
 * @current_dir: current directory.
 * @new_dir: new directory.
 * Return: address.
*/
char *cwd_adjust(char *current_dir, char *new_dir)
{
	size_t current_len = str_len(current_dir);
	size_t new_len = str_len(new_dir);
	char *result_path = NULL;

	if (new_dir[0] == '/')
		return (str_cpy(new_dir));

	result_path = (char *)malloc(current_len + new_len + 2);
	if (result_path != NULL)
	{
		_strcpy(result_path, current_dir);

		if (current_len > 0 && result_path[current_len - 1] != '/')
			_strcat(result_path, "/");

		_strcat(result_path, new_dir);
	}
	return (result_path);
}

/**
 * _strcat - strcat.
 * @destination: dir.
 * @source: go to dir.
 * Return: address.
*/
char *_strcat(char *destination, char *source)
{
	char *result = destination;

	while (*destination != '\0')
		destination++;

	while (*source != '\0')
	{
		*destination = *source;
		destination++;
		source++;
	}

	*destination = '\0';

	return (result);
}

/**
 * _strcpy - strcpy.
 * @destination: dir.
 * @source: got to
 * Return: address.
*/
char *_strcpy(char *destination, const char *source)
{
	char *result = destination;

	while (*source != '\0')
	{
		*destination = *source;
		destination++;
		source++;
	}

	*destination = '\0';

	return (result);
}
