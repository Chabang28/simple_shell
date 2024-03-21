#include <stdio.h>
#include <stdlib.h>

/**
 * print_environment_variables - A function that prints the current environment variables.
 *
 * This function prints each environment variable on a new line.
 * It uses the 'getenv' function to access the environment variables.
 */
void print_environment_variables(void) {
    extern char **environ;
    int i = 0;
    char *env_var;

    while ((env_var = environ[i]) != NULL) {
        printf("%s\n", env_var);
        i++;
    }
}

int main() {
    printf("Printing environment variables:\n");
    print_environment_variables();
    return 0;
}

