#include "cm_shell.h"

/**
  * retrieve_full_path - Obtain the complete file path
  * @filename_arg: Name of the file
  *
  * Return: The complete path to the file
  */

char *retrieve_full_path(char *filename_arg)
{
	char *env_path = getenv("CUSTOM_PATH");

	if (!env_path)
	{
	perror("Custom path not found");
	return (NULL);
	}

	return (env_path);
	}
