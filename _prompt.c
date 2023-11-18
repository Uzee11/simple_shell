#include "shell.h"

/* Declarations for functions used in main */
void uzee_print(const char *information);

void show_prompt(void) 
{
uzee_print("uzee_shell$ ");
}

int main(void)
{
show_prompt();
return 0;
}
