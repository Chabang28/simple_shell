#include "mc_shell.h"

/**
  * main - Custom Shell
  * @argc: Number of arguments
  * @argv: Array of argument values
  *
  * Return: 0 on success
  */

int main(int argc, char **argv)
{
	(void)argc, (void)argv;
	char *input_buffer = NULL, *token;
	size_t buffer_size = 0;
	ssize_t read_size;
	pid_t child_process_id;
	int index, process_status;
	char **arguments_array;

	while (1)
	{
	write(STDOUT_FILENO, "MyCustomShell$ ", 15);

	read_size = getline(&input_buffer, &buffer_size, stdin);

	if (read_size ==  -1)
	{
	perror("Exiting custom shell");
	exit(1);
	}

	token = strtok(input_buffer, " \n");

	arguments_array = malloc(sizeof(char*) * 1024);
	index = 0;

	while (token)
	{
	arguments_array[index] = token;
	token = strtok(NULL, " \n");
	index++;
	}

	arguments_array[index] = NULL;

	child_process_id = fork();

	if (child_process_id == -1)
	{
	perror("Failed to create process.");
	exit (41);
	}

	if (child_process_id == 0)
	{
	if (execve(exec_path, arguments_array, NULL) == -1)
	{
	perror("Failed to execute process");
	exit(97);
                        }
	}
	else
	{
	wait(&process_status);
	}
	}
	free(input_buffer);
	
	return 0;

	}

