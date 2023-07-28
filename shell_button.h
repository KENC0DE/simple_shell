#ifndef __BUTTONS__
#define __BUTTONS__

#define TRUE 1
#define SKIP -101
#define _EXIT -2
#define NO_CMD 101
#define FROM_SCREEN sh->fd
#define PROMPT "$ "
#define CMD_TRY do { sh->nth_cmd += 1; } while (0)

/* strings */
#define C_ERROR ": command not found\n"
#define XDIR ": No such file or directory\n"
#define CMD_ERR ": not found\n"
#define EXIT_ERR ": numeric argument required"
#define EXIT_ERR2 ": Illegal number: "

#endif
