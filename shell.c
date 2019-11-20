#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <dirent.h>
char *show_input(void);
void prompt(void);
char *_strcat(char *src);
int _strlen(char *str);
void place(char *str);

/**
 *
 *
 **/
int _strcmpdir(char *s1, char *s2)
{
	for (; (*s2 != '\0' && *s1 != '\0') && *s1 == *s2; s1++)
	{
		s2++;
	}

	return (*s1 - *s2);
}

/**
 *
 *
 **/
int findfile(char *command)
{
    DIR *folder;
    struct dirent *entry;
    int files = 0;
    char *cmd, comp;



    folder = opendir("/bin/");
    if(folder == NULL)
    {
        perror("Unable to read directory");
        return(1);
    }

    while( (entry=readdir(folder)) )
	    {
		    cmd = entry->d_name;

		    comp = _strcmpdir(cmd, command);
		    place("four");
		    if(comp == 0)
			    return(4);
	    }


     folder = opendir("/usr/local/sbin/");
     while( (entry=readdir(folder)) )
	    {
		    cmd = entry->d_name;
		    comp = _strcmpdir(cmd, command);
		    place("five");
		    if(comp == 0)
			    return(5);
	    }

    /*folder = opendir("/usr/local/bin");
    while( (entry=readdir(folder)) )
	    {
		    cmd = entry->d_name;
		    comp = _strcmpdir(cmd, command);

		    if(comp == 0)
			    return(6);
			    }*/

    folder = opendir("/usr/sbin");
    while( (entry=readdir(folder)) )
	    {
		    cmd = entry->d_name;
		    comp = _strcmpdir(cmd, command);
		    place("seven");
		    if(comp == 0)
			    return(7);
	    }

    folder = opendir("/usr/bin/");
    while( (entry=readdir(folder)) )
	    {
		    cmd = entry->d_name;
		    comp = _strcmpdir(cmd, command);
		    place("eight");
		    if(comp == 0)
			    return(8);
	    }

    folder = opendir("/sbin/");
    while( (entry=readdir(folder)) )
	    {
		    cmd = entry->d_name;
		    comp = _strcmpdir(cmd, command);
		    place("nine");
		    if(comp == 0)
			    return(9);
	    }

    /*folder = opendir("/usr/games");
    while( (entry=readdir(folder)) )
	    {
		    cmd = entry->d_name;
		    comp = _strcmpdir(cmd, command);

		    if(comp == 0)
			    return(10);
			    }

    folder = opendir("/usr/local/games");
    while( (entry=readdir(folder)) )
	    {
		    cmd = entry->d_name;
		    comp = _strcmpdir(cmd, command);

		    if(comp == 0)
			    return(11);
			    }

    folder = opendir("/snap/bin");
    while( (entry=readdir(folder)) )
	    {
		    cmd = entry->d_name;
		    comp = _strcmpdir(cmd, command);

		    if(comp == 0)
			    return(12);
			    }*/

    closedir(folder);

    return(0);
}

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
/**
 * _strcmp - a function that compares two strings.
 * @cmd: first string
 * Return: value of comparison
 */

int _strcmp(char *cmd)
{
	int i = 0;
	char *s1 = "/bin/";

		for ( ; (*s1 && (*s1 == *cmd)) ; s1++, cmd++, i++)
		{
			if (i == 4)
				break;
		}
	return (*(char *)s1 - *(char *)cmd);
}

/**
 *
 *
 *
 **/
char *driver(char **cmd)
{
	char *s;

	switch(findfile(*cmd))
		{
		case 4:
			s = str_concat("/bin/", *cmd);
			break;
		case 5:
			s = str_concat("/usr/local/sbin/", *cmd);
			break;
		case 7:
			s = str_concat("/usr/sbin", *cmd);
			break;
		case 8:
			s = str_concat("/usr/bin/", *cmd);
			break;
		case 9:
			s = str_concat("/sbin/", *cmd);
			break;
		default:
			perror("Error");
		}


	return(s);

}


/**
 * execute_proc - similar to puts in C
 * @cmd: a pointer the integer we want to set to 402
 *
 * Return: int
 */
void execute_proc(char **cmd)
{
	int compara = _strcmp(*cmd);
	char *parametro = *(cmd + 1);
	char *s;
	int n;

	if (compara != '0')
		{
			s = driver(cmd);
			char *argv[] = {s, parametro, ".", NULL};

				if (execve(argv[0], argv, NULL) == -1)
				{
					perror("Error:");
				}
		}
		else
			{

				char *argv[] = {*cmd, parametro, ".", NULL};

				if (execve(argv[0], argv, NULL) == -1)
					{
						perror("Error:");
					}
			}
}

/**
 * identify_string - identyfy keyboard input.
 * @parameter: call prompt from another function (prompt)
 * Return: str
 **/
char **identify_string(char *parameter)
{
	char **buf = malloc(1024 * sizeof(char *));
	char *split;
	int i = 0;

	split = strtok(parameter, " \t\r\n\a");
	while (split != NULL)

		{
			buf[i] = split;
			i++;

			split = strtok(NULL, " ");
		}
	execute_proc(buf);
	return (buf);
}

/**
 * prompt - call prompt from another function (prompt)
 *
 **/
void prompt(void)
{
		for (;;)
		{
			char *s;
			pid_t child_pid;
			int status, lenbuf;
			char *text = NULL;

			size_t bufsize = 0;

			place("$ ");

			lenbuf = getline(&text, &bufsize, stdin);
			child_pid = fork();

			if (lenbuf == -1)
				exit(98);

			if (child_pid == -1)
				{
					perror("Error:");
				}

			if (child_pid == 0)
				{
					/*s = str_concat("/bin/", text);*/


					char *argv[] = {s, ".", NULL};

					identify_string(text);

					if (execve(argv[0], argv, NULL) == -1)
						{
							perror("Error:");
						}
				}
			else
				{
					wait(&status);
				}
		}
}
/**
* INThandler - avoid close the shell
* @sig: keep going shell
**/
void  INThandler(int sig)
{
	(void) sig;
	write(1, "\n$ ", 3);
	return;
}
/**
 * main - func with infinite loop
 * @ac: No use
 * @av: No use
 * Return: loop.
 **/
int main(int ac, char **av, char *env[])
{
	(void)ac;
	(void)*av;
	signal(SIGINT, INThandler);
        prompt();
	return (0);
}
