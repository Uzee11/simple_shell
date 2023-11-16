#ifdef SHELL_H
#define SHELL_H

/**
 * Below are all the includes and dependencies for the functions
 * Author: Uzee11
 *@scan: to read
 * shell header file compilation
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


void uzee_print(const char *information);
void show_prompt(void);
void scan_command(char *command, size_t size);
void process_command(const chart *command);
#endif /* SHELL_H */



