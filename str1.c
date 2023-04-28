#include "main.h"

/**
 * _strcpy - Copy a string including the null byte
 * @dest: destination string
 * @src: source string
 * Return: character value
 */

char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';

	return (dest);
}

/**
 * _strdup - function that returns a pointer to a newly allocated space
 * in memory, which contains a copy of the string given as a parameter.
 * @str: string
 * Return: char
 */

char *_strdup(char *str)
{
	char *a;
	int i, j;

	if (str == NULL)
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
		;

	a = malloc((i * sizeof(char)) + 1);

	if (a == NULL)
		return (NULL);

	for (j = 0; str[j] != '\0'; j++)
		a[j] = str[j];

	a[j] = '\0';

	return (a);
}

/**
 * _puts - prints a string
 * @str: the string
 */

void _puts(char *str)
{
	int c = 0;

	if (!str)
		return;
	while (str[c] != '\0')
	{
		_putchar(str[c]);
		c++;
	}
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1 or -1 on error.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
