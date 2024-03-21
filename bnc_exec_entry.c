#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * bnc_exec_entry - A function that executes the given command
 * @command_args: Command arguments
 *
 * Return: 0 on success, -1 on failure
 */

int bnc_exec_entry(char **command_args) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == -1) {
        perror("fork");
        return -1; /* Failure */
    } else if (pid == 0) { /* Child process */
        if (execvp(command_args[0], command_args) == -1) {
            perror("execvp");
            exit(EXIT_FAILURE);
        }
    } else { /* Parent process */
        do {
            if (waitpid(pid, &status, WUNTRACED) == -1) {
                perror("waitpid");
                return -1; /* Failure */
            }
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));

        if (WIFEXITED(status)) {
            return WEXITSTATUS(status); /* Return child process exit status */
        } else {
            return -1; /* Failure */
        }
    }
}

