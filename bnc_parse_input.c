#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * bnc_parse_input - A function that transform user input into
 * an array of command arguments.
 * @input_string: The input string provided by the user
 *
 * Return: Array of strings containing command arguments, or NULL on failure
 */
char **bnc_parse_input(char *input_string) {
    size_t parsed_count = 0;
    size_t parsed_bufsize = 64;
    char **parsed_args = NULL;
    char *current_token;

    parsed_args = (char **)malloc(sizeof(char *) * parsed_bufsize);
    if (parsed_args == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    current_token = strtok(input_string, " \t\n");
    while (current_token != NULL) {
        if (parsed_count >= parsed_bufsize) {
            parsed_bufsize += 64;
            parsed_args = realloc(parsed_args, sizeof(char *) * parsed_bufsize);
            if (parsed_args == NULL) {
                perror("realloc");
                exit(EXIT_FAILURE);
            }
        }
        parsed_args[parsed_count] = strdup(current_token);
        if (parsed_args[parsed_count] == NULL) {
            perror("strdup");
            exit(EXIT_FAILURE);
        }
        parsed_count++;
        current_token = strtok(NULL, " \t\n");
    }
    // Terminate the array with a NULL pointer
    parsed_args = realloc(parsed_args, sizeof(char *) * (parsed_count + 1));
    if (parsed_args == NULL) {
        perror("realloc");
        exit(EXIT_FAILURE);
    }
    parsed_args[parsed_count] = NULL;

    return parsed_args;
}

