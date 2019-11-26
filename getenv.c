#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <dirent.h>


int _strcmpdir(char *s1, char *s2);
void place(char *str);
int charput(char c);

void place(char *str)
{
	while (*str != '\0')
		{
			charput(*str);
			str++;
		}
}


int charput(char c)
{
         return (write(1, &c, 1));
}



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



char *find_command(char *command)
{
	DIR *folder;
	struct dirent *entry;
	int files = 0;
	char *cmd, comp;

	char **str  = malloc(sizeof(char)*1024);
	extern char **environ;
	char **split = malloc(sizeof(char)*1024);
	int i = 0;
	char **ptr = malloc(sizeof(char)*1024);

	while(*environ != NULL)
		{
			if(!(_strcmpdir(*environ, "PATH")))
				{
					*str = *environ;
					for (int i = 0;i < 9;i++, split++, str++, ptr++)
						{
							*split = strtok(*str, ":='PATH'");

							folder = opendir(*split);

							if(folder == NULL)
								{
									perror("Unable to read directory");
								}

							while((entry=readdir(folder)))
								{
									cmd = entry->d_name;
									comp = _strcmpdir(cmd, "adduser");

									if(comp == 0)
										{
/* printf("%s",entry->d_name); */
									return(entry->d_name);
										}
								}
						}


				}
		environ++;
		}

return("1");
}
