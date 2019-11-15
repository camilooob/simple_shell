<<<<<<< HEAD
/*
 *
 */

#include <sys/wait.h>
#include <sys/types.h>

=======
#include <sys/wait.h>
#include <sys/types.h>
>>>>>>> 5ba74ac819ad5cac235ae649c239222283295b2b
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

<<<<<<< HEAD
=======
char *show_input(void);


>>>>>>> 5ba74ac819ad5cac235ae649c239222283295b2b
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
<<<<<<< HEAD
/**
  * place - similar to puts in C
  * @str: a pointer the integer we want to set to 402
  *
  * Return: int
  */
=======


/**
 * place - similar to puts in C
 * @str: a pointer the integer we want to set to 402
 *
 * Return: int
 */
>>>>>>> 5ba74ac819ad5cac235ae649c239222283295b2b
void place(char *str)
{
	while (*str != '\0')
	{
		charput(*str);
		str++;
	}
<<<<<<< HEAD
	charput('\n');
}
size_t getinput()
{
char *buffer;
    size_t bufsize = 32;
    size_t characters;

    buffer = (char *)malloc(bufsize * sizeof(char));
    if( buffer == NULL)
    {
        perror("Unable to allocate buffer");
        exit(1);
    }

    printf("$>");
    characters = getline(&buffer,&bufsize,stdin);
    printf("%zu characters were read.\n",characters);
    printf("You typed: '%s'\n",buffer);

    return(0);


}


int main(int ac, char **av)
{

place("-----Super Master Shell----\n");
place("      -----by:----\n");
place(" -----Sergio Pietri----\n");
place(" -----Camilo Baquero---\n");
place("    ----- 2019 ----\n");

getinput();


  return (0);
=======
}
/**
 * call prompt from another function (prompt)
 *
 **/
char **identify_string(char *parameter)
{
	char **buf = malloc(1024 * sizeof(char*));
	char *split;
	int i = 0;

	strtok(parameter, " ");

	while (split != NULL)
	{
		buf[i] = split;
		i++;
	}


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


	if(get == "exit")
	{
		place("exit");
	}

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

>>>>>>> 5ba74ac819ad5cac235ae649c239222283295b2b
}
