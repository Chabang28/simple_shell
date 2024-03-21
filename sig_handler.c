#include "bnc_shell.h"
#include <unistd.h>

void sigint_handler(int signal_number) {
    (void)signal_number; // Unused parameter
    if (isatty(STDIN_FILENO)) {
        // Check if the standard input is a terminal
        write(STDOUT_FILENO, "\n($) ", 5); // Print a newline and prompt
    }
}

