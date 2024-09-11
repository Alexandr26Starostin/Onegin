#include <stdio.h>
#include <assert.h>

#include "conventor_of_symbol.h"

int static compare (char* first_line, char* second_line);

void sort_onegin (char** array_of_ptr, size_t count_line)
{
    assert (array_of_ptr);

    for (int g = count_line; g > 0; g--)
    {
        for (int i = 0; i < g - 1; i++)  // TODO rename iterators
        {
            if (compare (*(array_of_ptr + i), *(array_of_ptr + i + 1)) > 0)     //1 > 2 
            {   
                char* temporary   = array_of_ptr[i];
                array_of_ptr[i]   = array_of_ptr[i+1];
                array_of_ptr[i+1] = temporary;
            }
        }
    }
}

int static compare (char* first_line, char* second_line)
{
    assert (first_line);
    assert (second_line);

    size_t i = 0;
    int difference = 0; 

    while ((difference = conventor_of_symbol(first_line[i]) - conventor_of_symbol(second_line[i])) == 0 && first_line[i] != '\0')
    {
        i++;
    }

    return difference;
}
