#include "bnc_shell.h"

/**
 * tokenized_array - A function that releases the memory allocated for an array
 * @str_array: A pointer to the array of strings
 *
 * Return: nothing (on success)
 */
void tokenized_array(char **str_array)
{
    int index;

    // Check if str_array is not NULL
    if (str_array)
    {
        // Loop through the array of strings until NULL is encountered
        for (index = 0; str_array[index]; index++)
        {
            // Free each string in the array
            free(str_array[index]);
        }
        // Free the array itself
        free(str_array);
    }
}

