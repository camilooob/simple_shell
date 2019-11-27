#include "holberton.h"
/**
 * find_command - finds command to execute in path routes.
 *
 * @command: first position of getline input.
 *
 * Return - string of folder for command to be executed.
 **/
char *find_command(char *command)
{
	DIR *folder;
	struct dirent *entry;
	char *cmd, comp;

	char **str  = malloc(sizeof(char) * 1024);
	extern char **environ;
	char **split = malloc(sizeof(char) * 1024);
	int i;

	while (*environ != NULL)
	{
		if (!(_strcmpdir(*environ, "PATH")))
		{
			*str = *environ;
			for (i = 0; i < 9; i++, split++, str++)
			{
				*split = strtok(*str, ":='PATH'");

				folder = opendir(*split);

				if (folder == NULL)
				{
					perror("Unable to read directory");
				}

				while ((entry = readdir(folder)))
				{
					cmd = entry->d_name;
					comp = _strcmpdir(cmd, command);

					if (comp == 0)
					{
						return (*split);
					}

					if (cmd == NULL)
					{
						perror("Error");
					}
				}
			}
		}
		environ++;
	}
	return ("Error: Not Found");
}
/**
 * lookforslash - identifies if first char is a slash.
 * @cmd: first string
 * Return: 1 if yes 0 if no.
 */
int lookforslash(char *cmd)
{
	int cont = 0;

	while (cmd[cont])
	{
		if (cmd[0] == '/')
		{
			printf("%c\n", cmd[0]);
			return (1);
		}

		cont++;
	}
	return (0);
}

/**
 * compare - identifies if first char is a slash.
 * @s1: first string
 * @s2: exit string
 * Return: 1 if yes 0 if no.
 */
int compareExit(char *s1, char *s2)
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

/**
 * compareEnv - identifies if first char is a slash.
 * @s1: first string
 * @s2: exit string
 * Return: 1 if yes 0 if no.
 */
int compareEnv(char *s1, char *s2)
{
	int i = 0;

	for (; (*s2 != '\0' && *s1 != '\0') && *s1 == *s2; s1++)
	{
		if (i == 2)
			break;
		i++;
		s2++;
	}

	return (*s1 - *s2);
}

/**
 * execute_proc - similar to puts in C
 * @cmd: a pointer the integer we want to set to 402
 *
 * Return: int
 */
void execute_proc(char **cmd)
{

	char *parametro = (*(cmd + 1));
	char *s, *slash = "/";
	char *o;

	char *vartoprint = *cmd;
	char *argv[4];

	if ((access(cmd[0], F_OK) == 0))
	{
		argv[0] = cmd[0];
		argv[1] = parametro;
		argv[2] = ".";
		argv[3] = NULL;

		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("Error");
		}
	}
	else
	{
		o = find_command(vartoprint);

		slash = str_concat(o, slash);

		s = str_concat(slash, *cmd);

		argv[0] = s;
		argv[1] = parametro;
		argv[2] = ".";
		argv[3] = NULL;

		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("Error");
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
	char *delim = " \t\n";


	split = strtok(parameter, delim);

	while (split != NULL)
	{
		buf[i] = split;
		i++;
		split = strtok(NULL, delim);
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
		char *s = "";
		pid_t child_pid;
		int status, lenbuf;
		char *text = NULL;
		size_t bufsize = 0;
		extern char **environ;

		place("$ ");

		lenbuf = getline(&text, &bufsize, stdin);


		if (lenbuf == -1)
		{
			free(s);
			free(text);
			free(environ);
			free(*environ);
			exit(98);
		}

		if (compareExit(text, "exit") == 0)
			exit(0);

		if (compareEnv(text, "env") == 0)
		{
			while (*environ != NULL)
			{
				if (!(_strcmpdir(*environ, "USER")) ||
						!(_strcmpdir(*environ, "LANGUAGE")) ||
						!(_strcmpdir(*environ, "SESSION")) ||
						!(_strcmpdir(*environ, "COMPIZ_CONFIG_PROFILE")) ||
						!(_strcmpdir(*environ, "SHLV")) ||
						!(_strcmpdir(*environ, "HOME")) ||
						!(_strcmpdir(*environ, "C_IS")) ||
						!(_strcmpdir(*environ, "DESKTOP_SESSION")) ||
						!(_strcmpdir(*environ, "LOGNAME")) ||
						!(_strcmpdir(*environ, "TERM")) ||
						!(_strcmpdir(*environ, "PATH")))
				{
					place(*environ);
					place("\n");
				}
				environ++;
			}
		}
		child_pid = fork();
		if (child_pid < 0)
		{
			perror("Error");
		}

		if (child_pid == 0)
		{
			identify_string(text);
		}
		else
		{
			wait(&status);
		}
	}
}

/**
 * controlC - avoid close the shell
 * @sig: keep going shell
 **/
void  controlC(int sig)
{
	(void) sig;
	write(1, "\n$ ", 3);
}

