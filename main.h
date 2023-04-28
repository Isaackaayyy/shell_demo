#ifndef MAIN
#define MAIN

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/wait.h>
#include "data_structure.h"


/* define macros */
#define BUF_FLUSH -1

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}




/* str.c */
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *start_find(const char *hashtack, const char *needle);
char *_strcat(char *dest, char *src);

/* str1.c */
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
void _puts(char *str);
int _putchar(char c);


#endif
