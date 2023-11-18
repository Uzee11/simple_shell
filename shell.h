#ifndef SHELL_H
#define SHELL_H

/**
 * @file: shell.h
 * Declarations for functions used in the shell.
 *
 * Below are all the includes and dependencies for the functions.
 * Author: Uzee11
 * @scan to read command
 * shell header file compilation
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
/**
 * @param information - The description in parameter
 * which is information to be printed.
 */

/* The prototype helpers */
void uzee_print(const char *information);
void show_prompt(void);
void scan_command(char *command, size_t size);
void process_command(const char *command);

#endif /* SHELL_H */
