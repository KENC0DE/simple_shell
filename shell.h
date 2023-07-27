#ifndef __SHELL__
#define __SHELL__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <dirent.h>
#include <fcntl.h>
#include <errno.h>

#include "shell_button.h"

/**
 * struct hsh_t - Represents the shell data
 * @sh_name: Name of the shell
 * @id: Child pid
 * @cmd: String of commands
 * @prg: Program location
 * @shortcmd: Shortened command
 * @delim: Tokenize using delim
 * @line: Accepted input
 * @waitStat: Status of wait
 * @fd: File descriptor
 * @ex_child: Child process info
 * @bytes: Bytes read
 * @eof: End of file
 * @path: Path to a program
 * @environment: Current environment
 * @alc: Free specify
 * @exit_stat: Exit status
 * @er_name: Name used for error
 * @nth_cmd: Command number
 * @cmd_state: state.
 * @signal: sig
 */
typedef struct hsh_t
{
	char *sh_name;            /* Name of the shell */
	pid_t id;                 /* Child pid */
	char **cmd;               /* String of commands */
	char *prg;                /* Program location */
	char *shortcmd;           /* Shortened command */
	char *delim;              /* Tokenize using delim */
	char *line;               /* Accepted input */
	int waitStat;             /* Status of wait */
	int fd;                   /* File descriptor */
	int ex_child;             /* Child process info */
	size_t bytes;             /* Bytes read */
	ssize_t eof;              /* End of file */
	char *path;               /* Path to a program */
	char **environment;       /* Current environment */
	int alc;                  /* Free specify */
	int exit_stat;            /* Exit status */
	char *er_name;            /* Name used for error */
	unsigned int nth_cmd;     /* Command number */
	int cmd_state;		/* Command state */
	int signal;		/* signal for exit */
} hsh_t;

/**
 * struct button - Represents a shell button
 * @bt: Button name
 * @ext: Button location
 */
typedef struct button
{
	char *bt;                 /* Button name */
	int (*ext)(hsh_t *);      /* Button location */
} btns_t;


/* helper functions */
int str_n_comp(char *str1, char *str2, int n);
int str_len(char *str);
char *str_concat(char *str1, char *str2);
char *str_cpy(char *str);
int _put(char *str);
int str_comp(char *str1, char *str2);
void reverseString(char *str);

/* Addons */
int shell_do(hsh_t *sh, btns_t *btn);
int exit_f(hsh_t *sh);
int env_f(hsh_t *sh);
int put_err(hsh_t *sh);
char *intToCharArray(int number);
int countDigits(int number);
char *toChar(int num);

/* shell functions */
void checkInteractive(hsh_t *sh);
void initialize(hsh_t *sh, char **envp, char *p_name);
void checkId(hsh_t *sh);
int runTimeLoop(hsh_t *sh, btns_t *btn);
ssize_t processInput(hsh_t *sh, btns_t *btn);
int adjust_numOfArgs(hsh_t *sh);
int findcmd(char *cmd1, hsh_t *sh, btns_t *btn);
int execute(hsh_t *sh);
void freeMem(hsh_t *sh);
void tokenize(hsh_t *sh, int n);
int errorhandle(hsh_t *sh, int er);
char *str_concatSH(char *str1, char *str2);

#endif
