#include <stdio.h>
#include <assert.h>

void print_onegin (char** array_of_ptr, size_t count_line)
{
    for (int i = 0; i < count_line; i++)
    {
        printf ("%s\n", *(array_of_ptr + i));

    }

    printf ("\n\n\n");
}
