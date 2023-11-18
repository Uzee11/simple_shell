#include "shell.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void scan_command(char *command, size_t size)
{
if (fgets(command, size, stdin) == NULL)
{
if (feof(stdin))
{
uzee_print("\n");
exit(EXIT_SUCCESS);
}
else
{
uzee_print("Error while scanning input.\n");
exit(EXIT_FAILURE);
}
}
command[strcspn(command, "\n")] = '\0'; /* Remove new line */
}
