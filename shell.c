#include "shell.h"
#include <stddef.h>

/* Declarations for functions used in main */
void show_prompt(void);
void scan_command(char *command, size_t size);
void execute_command(const char *command);

/**
 * main - The main function for the shell.
 *        This function continuously prompts the user, reads a command,
 *        and processes it until the user exits.
 *
 * Return: Always 0 on successful completion.
 */
int main(void)
{
char command[131]; /* Buffer to store the user's command */

while (1)
{
show_prompt(); /* Display the shell prompt */
scan_command(command, sizeof(command)); /* Read user input */
execute_command(command); /* Execute the user's command */
}

return (0); /* Successful completion */
}







