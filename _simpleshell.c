#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100

void show_prompt()
{
write("uzee_print$ ");
uzee_write(prompt);
fflush(stdout);
}
void uzee_write(const char *information) 
{
write(STDOUT_FILENO, information, strlen(information));
}


void execute_command(const char *command)
{
pid_t pid = fork();

if (pid == -1)
{
perror("fork");
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
/* Child process */
execlp(command, command, (char *)NULL);
/* If exec fails */
perror("exec");
exit(EXIT_FAILURE);
} 
else
{
/* Parent process */
wait(NULL);

}

int main()
{
char command[MAX_COMMAND_LENGTH];

while (1)
{
show_prompt();

if (fgets(command, sizeof(command), stdin) == NULL) {
if (feof(stdin))
{
const char newline[] = "\n";
write(STDOUT_FILENO, newline, sizeof(newline) - 1);
exit(EXIT_SUCCESS);
else
{
perror("fgets");
exit(EXIT_FAILURE);
}
}
/* Remove the trailing newline character */
command[strcspn(command, "\n")] = '\0';

if (strlen(command) > 0)
{
execute_command(command);
}
}

return 0;

