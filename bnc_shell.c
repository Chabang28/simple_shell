#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include "bnc_shell.h"

/**
 * main - Entry point of the shell program
 *
 * Return: EXIT_SUCCESS on successful completion
 */
int main(void)
{
    char *user_input;
    char **command_args;
    int shell_status;

    // Register signal handlers
    signal(SIGINT, sigint_handler);
    signal(SIGQUIT, sigquit_handler);
    signal(SIGTSTP, sigstp_handler);

    do {
        // Read user input
        user_input = bnc_read_input();
        if (!user_input || !*user_input) {
            // Check for end of file (EOF) or empty input
            break;
        }

        // Parse user input into command arguments
        command_args = bnc_parse_input(user_input);
        if (!command_args || !*command_args) {
            // Handle parsing error
            free(user_input);
            continue;
        }

        // Execute built-in commands or external commands
        if (strcmp(command_args[0], "exit") == 0) {
            bnc_exit(user_input);
            free(user_input);
            break; // Exit the loop if the command is "exit"
        } else if (strcmp(command_args[0], "env") == 0) {
            bnc_env();
            free(user_input);
            continue;
        } else {
            // Execute the command
            shell_status = bnc_exec_entry(command_args);
            free(user_input);
            if (shell_status != 0) {
                // Handle execution error
                continue;
            }
        }

        // Free memory allocated for command arguments
        tokenized_array(command_args);

    } while (1);

    return EXIT_SUCCESS;
}
}
