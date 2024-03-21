#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * bnc_read_input - A function that reads input from the user
 *
 * Return: The input string entered by the user
 */
char *bnc_read_input(void) {
    char *user_input = NULL;
    size_t input_size = 0;
    ssize_t read_bytes;

    if (isatty(STDIN_FILENO)) {
        /* Display prompt only in interactive mode */
        printf("MyShell$ ");
        fflush(stdout);  // Flush stdout to ensure prompt is displayed immediately
    }

    read_bytes = getline(&user_input, &input_size, stdin);
    if (read_bytes == -1) {
        /* Error or end of input */
        if (isatty(STDIN_FILENO)) {
            putchar('\n');
            fflush(stdout);  // Flush stdout to ensure newline is displayed
        }
        free(user_input);
        return NULL;
    }

    // Remove trailing newline character
    if (user_input[read_bytes - 1] == '\n') {
        user_input[read_bytes - 1] = '\0';
    }

    return user_input;
}

