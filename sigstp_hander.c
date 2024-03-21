#include <signal.h>
#include "bnc_shell.h"
#include <unistd.h>

/**
 * sigstp_handler - Handle the SIGTSTP signal (Ctrl+Z)
 * @signal_number: A signal number (unused but documented).
 *
 * Return: Nothing (on success).
 */
void sigstp_handler(int signal_number)
{
    (void)signal_number;

    // Check if standard input is a terminal
    if (isatty(STDIN_FILENO))
    {
        // Write prompt to stdout
        write(STDOUT_FILENO, "\n($) ", 5);
    }
}

