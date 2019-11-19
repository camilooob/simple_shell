#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

char *show_input(void);


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
}
/**
 * call prompt from another function (prompt)
 *
 **/
char **identify_string(char *parameter)
{
	char **buf = malloc(1024 * sizeof(char*));
	char *split;
	int i = 1;

	split = strtok(parameter, "");

	while (split != NULL)
	{
	  /*PENDIENTE: eliminar espacio en blanco y hacer que guarde la vaina separado*/
	  if (*split)
	    {
	      buf[i] = split;
	      i++;
	    }
	  
	  
	  split = strtok(NULL, " ");
	}

	
	place(*(buf + 1));
	
	
	
	return (buf);
}
/**
 * call prompt from another function (prompt)
 *
 **/
void prompt(void)
{
	char *text;
	char **pars;

	text = show_input();
	pars = identify_string(text);



	
}

/**
 * display prompt with getline
 *
 **/
char *show_input(void)
{
	char *text = NULL, *get;
	ssize_t bufsize = 0;

	place("$ ");
	getline(&text, &bufsize, stdin);


	return (text);
}

/**
 * main func with infinite loop
 *
 **/
void main(int ac, char **av)
{

	while(1)
	{
		prompt();
	}

}
