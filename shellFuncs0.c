#include "shell.h"

/**
 * str_n_comp - compare two strings.
 * @str1: first string.
 * @str2: second string.
 * @n: number of checks.
 *
 * Return: 1 if the same -1 if not.
*/
int str_n_comp(char *str1, char *str2, int n)
{
	int i;

	if (n)
	{
		for (i = 0; i < n; i++)
		{
			if (str1[i] != str2[i])
				return (-1);
		}
	}

	return (0);
}

/**
 * str_concat - add string together.
 * @str1: string 1.
 * @str2: string 2.
 *
 * Return: concated string.
*/
char *str_concat(char *str1, char *str2)
{
	int i, j, len;
	char *concated;

	if (str1 && str2)
	{
		len = str_len(str1);
		len += str_len(str2);
		len++;

		concated = malloc(sizeof(char) * (len + 1));
		if (!concated)
			return (NULL);

		for (i = 0; str1[i]; i++)
		{
			concated[i] = str1[i];
		}
		concated[i] = '/';
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

/**
 * str_len - count string length
 * @str: target string.
 * Return: string length.
*/
int str_len(char *str)
{
	int i = 0;

	if (str)
	{
		while (str[i])
			i++;

		return (i);
	}
	return (0);
}

/**
 * str_cpy - duplicates a string.
 * @str: string to be duplicated.
 * Return: pointer to the duplicated string.
*/
char *str_cpy(char *str)
{
	int i, len;
	char *copy = NULL;

	if (str)
	{
		len = str_len(str);
		copy = malloc(sizeof(char) * len + 1);
		if (!copy)
			return (NULL);

		for (i = 0; i < len; i++)
		{
			copy[i] = str[i];
		}
		copy[len] = '\0';
		return (copy);
	}
	return (NULL);
}
