#include "main.h"

/**
 * _strlen - length of a string
 * @s: first value
 * Return: unsigned int
 */

int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;

	return  (i);
}

/**
* _strcmp - compares two strings
* @s1: first member
* @s2: second member
* Return: integer
*/

int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0' || s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	return (0);
}

/**
 * start_find - check to see if needle begins with hashtack
 * @hashtack: string to be search
 * @needle: the substring being sought for
 * Return: address of next char of haystack or NULL
 */
char *start_find(const char *hashtack, const char *needle)
{
	while (*needle)
		if (*needle++ != *hashtack++)
			return (NULL);
	return ((char *)hashtack);
}

/**
 * *_strcat - Apendind a string to another string
 * @dest: The first string
 * @src: String to be appended to the next string
 * Return: char
 */

char *_strcat(char *dest, char *src)
{
	int i, j;

	for (i = 0; dest[i] != '\0'; i++)
		;
	for (j = 0; src[j] != '\0'; j++)
	{
		dest[i] = src[j];
		i++;
	}
	dest[i] = '\0';

	return (dest);
}
