
#include "shell.h"
#include <stdlib.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

char *strtok(char *str, const char *delim);
void uzee_print(const char *information);

/**
 * This function forks a new process and uses execvp to execute
 * the specified command in the child process. It also tokenizes
 * the command string to prepare the arguments for execvp.
 */
void process_command(const char *command) {
    /* Fork a new process */
    pid_t child_pid = fork();
    
    if (child_pid == -1) {
        /* Forking failed */
        uzee_print("Error forking process.\n");
        exit(EXIT_FAILURE);
    } else if (child_pid == 0) {
        /* Child process */
        /* Parse the command and its arguments */
        char *args[131];
        int arg_count = 0;
        char *token = strtok((char*)command, ",");
        
        while (token != NULL) {
            args[arg_count++] = token;
            token = strtok(NULL, ",");
        }
        args[arg_count] = NULL; /* NULL-terminate args */

        /* Execute the command in the child process */
        execvp(args[0], args);

        /* If execvp fails, print an error message and exit */
        uzee_print("Error processing command.\n");
        exit(EXIT_FAILURE);
    } else {
        /* Parent process */
        /* Wait for the child process to finish */
        wait(NULL);
    }
}