#include "shell.h"
#include <string.h>
#include <unistd.h>
/**
 * uzee_print - Print information to standard output.
 *
 * This function writes the given information to the standard output.
 *
 * @param information The string to be printed.
 */
void uzee_print(const char *information)
{
write(STDOUT_FILENO, information, strlen(information));
}
