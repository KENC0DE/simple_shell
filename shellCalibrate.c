#include "shell.h"

/**
 * initialize - initializes variables.
 * @sh: big var
 * @envp: bing envron
 * @p_name: name
*/
void initialize(hsh_t *sh, char **envp, char *p_name)
{
	sh->id = 0;
	sh->delim = " \n\t\r\v\f";
	sh->cmd = NULL;
	sh->shortcmd = NULL;
	sh->line = NULL;
	sh->environment = envp;
	sh->path = NULL;
	sh->sh_name = p_name;
	sh->alc = 0;
	sh->er_name = NULL;
	sh->prg = NULL;
	sh->ex_child = 1;
	sh->nth_cmd = 0;
	sh->cmd_state = 0;
	sh->exit_stat = 0;
}

/**
 * checkInteractive - check if it is interactive.
 * @sh: big var.
*/
void checkInteractive(hsh_t *sh)
{
	if (isatty(STDIN_FILENO))
		FROM_SCREEN = 1;
	else
		FROM_SCREEN = 0;
}

/**
 * checkId - check child id.
 * @sh: big var.
*/
void checkId(hsh_t *sh)
{
	if (sh->id == 0)
	{
		if (sh->ex_child != _EXIT)
			freeMem(sh);
	}
}

/**
 * str_concatSH - add string together.
 * @str1: string 1.
 * @str2: string 2.
 *
 * Return: concated string.
*/
char *str_concatSH(char *str1, char *str2)
{
	int i, j, len;
	char *concated;

	if (str1 && str2)
	{
		len = str_len(str1);
		len += str_len(str2);
		len += 2;

		concated = malloc(sizeof(char) * (len + 1));
		if (!concated)
			return (NULL);

		for (i = 0; str1[i]; i++)
		{
			concated[i] = str1[i];
		}
		concated[i] = ':';
		i++;
		concated[i] = ' ';
		i++;
		for (j = 0; str2[j]; i++, j++)
		{
			concated[i] = str2[j];
		}
		concated[len] = '\0';

		return (concated);
	}
	return (NULL);
}
