/*
 *
 */

#include <sys/wait.h>
#include <sys/types.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

/**
 * charput - writes the character like putchar
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int charput(char c)
{
	return (write(1, &c, 1));
}
/**
  * place - similar to puts in C
  * @str: a pointer the integer we want to set to 402
  *
  * Return: int
  */
void place(char *str)
{
	while (*str != '\0')
	{
		charput(*str);
		str++;
	}
	charput('\n');
}


int main(int ac, char **av)
{

place("-----Super Master Shell----\n");
place("-----by:----\n");
place("-----Sergio Pietri----\n");
place("-----Camilo Baquero----\n");
place("----- 2019 ----\n");
  return (0);
}
