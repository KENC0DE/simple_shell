#include "shell.h"

/**
 * freeMem - free's dynamically allocated memory.
 * @sh: var pointer
*/
void freeMem(hsh_t *sh)
{
	if (sh)
	{
		if (sh->line)
		{
			free(sh->line);
			sh->line = NULL;
		}
		if (sh->cmd)
		{
			free(sh->cmd);
			sh->cmd = NULL;
		}
		if (sh->path)
		{
			free(sh->path);
			sh->path = NULL;
		}
		if (sh->alc)
		{
			free(sh->shortcmd);
			sh->shortcmd = NULL;
			sh->alc = 0;
		}
	}
}
