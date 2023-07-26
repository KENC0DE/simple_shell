#include "shell.h"

/**
 * shell_do - select fucnction.
 * @sh: big var.
 * @btn: sub big var.
 * Return: int.
*/
int shell_do(hsh_t *sh, btns_t *btn)
{
	int i;
	int info;

	for (i = 0; btn[i].bt; i++)
	{
		if (str_comp(sh->cmd[0], btn[i].bt) == 0)
		{
			info = btn[i].ext(sh);
			return (info);
		}
	}

	return (0);
}

/**
 * put_err - custom perror.
 * @sh: big var.
 * Return: int
*/
int put_err(hsh_t *sh)
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
	r_len = write(STDERR_FILENO, CMD_ERR, str_len(CMD_ERR));
	if (r_len == -1)
	{
		return (-1);
	}

	free(nc);
	free(sh->er_name);
	return (r_len);
}

/**
 * intToCharArray - change integer to var.
 * @number: number to be changed.
 * Return: array.
*/
char *intToCharArray(int number)
{
	int numDigits = countDigits(number);
	char *result = (char *)malloc((numDigits + 1) * sizeof(char));
	int i = 0;
	int start = 0;
	int end = i - 1;

	if (result == NULL)
		return (NULL);
	if (number == 0)
		result[i++] = '0';
	while (number > 0)
	{
		result[i++] = '0' + (number % 10);
		number /= 10;
	}

	while (start < end)
	{
		char temp;

		temp = result[start];
		result[start] = result[end];
		result[end] = temp;
		start++;
		end--;
	}
	result[i] = '\0';
	reverseString(result);
	return (result);
}

/**
 * countDigits - count numbe or digits
 * @number: the number.
 * Return: int.
*/
int countDigits(int number)
{
	int count = 0;

	while (number > 0)
	{
		number /= 10;
		count++;
	}
	return (count);
}

/**
 * reverseString - reverses string.
 * @str: the string.
*/
void reverseString(char *str)
{
	int length = str_len(str);
	int i;
	char temp;

	for (i = 0; i < length / 2; i++)
	{
		temp = str[i];
		str[i] = str[length - 1 - i];
		str[length - 1 - i] = temp;
	}
}
