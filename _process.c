#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * execute_command - Execute a shell command.
 * @command: The command to be executed.
 *
 * This function forks a new process and uses execve to execute
 * the specified command in the child process.
 */
void execute_command(const char *command)
{
/* Fork a new process */
pid_t child_pid = fork();
if (child_pid == -1)
{
/* Forking failed */
perror("fork");
exit(EXIT_FAILURE);
}
else if (child_pid == 0)
{
/* Child process */
/* Declare environment variables */
char *envp[] = {NULL};

/* Prepare an array of strings for the command and its arguments */
char *args[] = {"/bin/sh", "-c", NULL, NULL};

/* Copy the command into args[2] */
args[2] = malloc(strlen(command) + 1);
if (args[2] == NULL)
{
perror("malloc");
exit(EXIT_FAILURE);
}
strcpy(args[2], command);

/* Execute the command in the context of a shell */
execve(args[0], args, envp);
/* If execve fails, print an error and exit */
perror("execve");
exit(EXIT_FAILURE);
}
else
{
/* Parent process */
/* Wait for the child process to finish */
wait(NULL);
}
}
