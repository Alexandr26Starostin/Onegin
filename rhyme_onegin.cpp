#include <stdio.h>
#include <assert.h>

#include "conventor_of_symbol.h"

int static compare_for_rhyme (char* first_line, char* second_line);
size_t static len_line (char* line_ptr);

void rhyme_onegin (char** array_of_ptr, size_t count_line)
{
    assert (array_of_ptr);

    for (int g = count_line; g > 0; g--)
    {
        for (int i = 0; i < g - 1; i++)
        {
            if (compare_for_rhyme (array_of_ptr[i], array_of_ptr[i + 1]) > 0)
            {
                char* temporary     = array_of_ptr[i];
                array_of_ptr[i]     = array_of_ptr[i + 1];
                array_of_ptr[i + 1] = temporary;
            }
        }
    }
}

int static compare_for_rhyme (char* first_line, char* second_line)
{
    assert (first_line);
    assert (second_line);

    size_t first_len  = len_line (first_line);
    size_t second_len = len_line (second_line);

    size_t index_first  = 2;
    size_t index_second = 2;
    
    int difference = 0;

    while (index_first <= first_len && index_second <= second_len && 
           (difference = conventor_of_symbol (first_line[first_len - index_first]) - conventor_of_symbol (second_line[second_len - index_second])) == 0)
    {
        index_first++;
        index_second++;
    }

    return difference;
}

size_t static len_line (char* line_ptr)
{
    assert (line_ptr);
    int i = 0;

    while (line_ptr[i] != '\0')
    {
        i++;
    }

    return i++;
}
