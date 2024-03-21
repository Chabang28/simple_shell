#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * bnc_exit - A function that gracefully exits the shell program
 * @user_command: The user input to be processed
 *
 * Return: Nothing
 */
void bnc_exit(char *user_command) {
    if (strcmp(user_command, "exit") == 0) {
        printf("Exiting the bnc_shell program\n");
        exit(EXIT_SUCCESS);
    }
}

