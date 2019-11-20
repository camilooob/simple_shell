#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int _strcmpdir(char *s1, char *s2);

int _strcmpdir(char *s1, char *s2)
{
	int i = 0;

	for (; (*s2 != '\0' && *s1 != '\0') && *s1 == *s2; s1++)
		{
			if (i == 3)
				break;
			i++;
			s2++;
		}

	return (*s1 - *s2);
}



int main(int ac, char **av, char **env)
{
	char *buf = malloc(sizeof(char)*1024);
	char **str = malloc(sizeof(char)*1024);
	extern char **environ;
	char **split = malloc(sizeof(char)*1024);
	int i = 0;

	while(*environ != NULL)
		{
			if(!(_strcmpdir(*environ, "PATH")))
				{
					*str = *environ;
					for (int i = 0;i < 20;i++, split++, str++)
						{
									*split = strtok(*str, ":");
							printf("%s : en POSICION -> %d \n", *split,i);
						}

					return(0);
				}
			environ++;
		}


	return(0);
}
