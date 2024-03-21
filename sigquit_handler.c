#include <signal.h>
#include "bnc_shell.h"
#include <unistd.h>
#include <stdio.h> // for perror

/**
 * sigquit_handler - A function that handles the SIGQUIT signal (Ctrl+\)
 * @signal_number: The signal number (unused)
 */
void sigquit_handler(int signal_number)
{
    (void)signal_number;

    // Print a message if standard input is a terminal
    if (isatty(STDIN_FILENO))
    {
        const char *message = "SIGQUIT received. Exiting...\n";
        if (write(STDOUT_FILENO, message, strlen(message)) == -1) {
            perror("write");
            exit(EXIT_FAILURE); // Handle write error
        }
    }

    
}

