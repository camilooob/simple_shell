#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

char *show_input(void);

void prompt(void);
char *_strcat(char *src);
int _strlen(char *str);

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
<<<<<<< HEAD
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
=======

/**
 * _strlen - Len string.
 * @str: My string.
 * Return: Length.
 */
int _strlen(char *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++)
      ;

    return (i);
}

/**
 * str_concat - concatane strings.
 * @s1: string.
 * @s2: second string.
 * Return: strings.
 */
char *str_concat(char *s1, char *s2)
{
    char *a;
    int lens1, lens2, j, i, e;

    if (s1 == NULL)
        s1 = "";

    if (s2 == NULL)
        s2 = "";

    lens1 = _strlen(s1);

    lens2 = _strlen(s2);

    a = malloc(((lens1) + (lens2) + 1) * sizeof(char));

    if (a == NULL)
        return (NULL);

    for (j = 0; j < lens1; j++)
    {
        a[j] = s1[j];
    }

    for (i = lens1, e = 0; e <= lens2; i++, e++)
    {
        a[i] = s2[e];
    }
    return (a);
}
>>>>>>> b3a90266297dd14bc21e9f6c565bb71af3a84645

/**
 * execute_proc - similar to puts in C
 * @str: a pointer the integer we want to set to 402
 *
 * Return: int
 */
void execute_proc(char *cmd)
{ 
  char *s = str_concat("/bin/", cmd);
  char *argv[] = {s, ".", NULL};
  char *env[] = {s,NULL};

  execve(s, argv, env);
 
  
  if (execve(argv[0], argv, NULL) == -1)
    {
      perror("Error");
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

	int i = 0, j = 1;

	split = strtok(parameter, " \t\r\n\a");

	while (split != NULL)/* This is to save the text in getline to a buffer  */
	{
	  /*PENDIENTE: eliminar espacio en blanco y hacer que guarde la vaina separado*/
	      buf[i] = split;
	      i++;
	  
	  split = strtok(NULL, " ");
	}

	

	/*while(buf[j] != NULL) This will run through the array of words in buf and print them 
	{
	  place(*(buf + j));
	  charput('\n');
	  j++;
	}*/
	
	execute_proc(*(buf));
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
    while(1)
    {
	place("$ ");
	getline(&text, &bufsize, stdin);

	return (text);
    }
    }

<<<<<<< HEAD
void handler_function()
{


}
=======

>>>>>>> f90917512bfbb2b2b7fd555643c8ff4acc470786
/**
 * main func with infinite loop
 *
 **/
void main(int ac, char **av)
{
  pid_t my_pid;
  pid_t pid;
  
  pid = fork();
  if(pid == -1)
    {
      perror("Error:");
    }
  else if(pid == 0)
    {
      while(1)
	{
	  prompt();
	  signal(SIGINT, handler_function);
	}   
    }
}
