#ifndef __BUTTONS__
#define __BUTTONS__

#define TRUE 1
#define SKIP -101
#define _EXIT -2
#define NO_CMD 101
#define FROM_SCREEN sh->fd
#define PROMPT "$ "

/* strings */
#define C_ERROR ": command not found\n"
#define CMD_TRY do { sh->nth_cmd += 1; } while (0)
#define CMD_ERR ": not found\n"
#define EXIT_ERR ": numeric argument required"
#define EXIT_ERR2 ": Illegal number: "

#endif
