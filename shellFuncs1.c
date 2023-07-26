#include "shell.h"

/**
 * _put - prints char.
 * @str: the str.
 *
 * Return: one on success.
*/
int _put(char *str)
{
	int er;

	er = write(1, str, str_len(str));
	if (er == -1)
		return (-1);

	return (er);
}

/**
 * tokenize - tokenize
 * @sh: var
 * @n: int
*/
void tokenize(hsh_t *sh, int n)
{
	int i;

	sh->cmd[0] = strtok(sh->line, sh->delim);
	sh->prg = sh->cmd[0];
	for (i = 1; i < n; i++)
		sh->cmd[i] = strtok(NULL, sh->delim);
}

/**
 * errorhandle - handle error
 * @sh: var
 * @er: ar
 *
 * Return: int
*/
int errorhandle(hsh_t *sh, int er)
{
	if (!sh->cmd[0])
		return (SKIP);

	switch (er)
	{
		case SKIP:
			return (SKIP);
		case NO_CMD:
			put_err(sh);
			sh->cmd_state = 1;
			return (SKIP);
		case _EXIT:
			if (FROM_SCREEN)
				_put("exit\n");
			return (_EXIT);
	}

	return (0);
}
/**
 * str_comp - compare str
 * @str1: fist string.
 * @str2: second string.
 *
 * Return: compered value
*/
int str_comp(char *str1, char *str2)
{
	int i = 0;

	if (str1 && str2)
	{
		while (str1[i] && str2[i])
		{
			if (str1[i] != str2[i])
				return (-1);
			i++;
		}
		return (str1[i] == str2[i] ? 0 : -1);
	}

	return (-1);
}
