#include <stdio.h>
#include <assert.h>

#include "conventor_of_symbol.h"

size_t static len_line (char* line_ptr);

int compare_str (void* first_ptr, void* second_ptr)
{
    assert (first_ptr);
    assert (second_ptr);

	char* first_line  = *((char**) first_ptr);
	char* second_line = *((char**) second_ptr);

    size_t index_symbol = 0;
    int    difference   = 0; 

    while ((difference = conventor_of_symbol(first_line[index_symbol]) - conventor_of_symbol(second_line[index_symbol])) == 0 
            && first_line[index_symbol] != '\0')
    {
        index_symbol++;
    }

    return difference;
}

int compare_str_for_rhyme (void* first_ptr, void* second_ptr)
{
    assert (first_ptr);
    assert (second_ptr);

	char* first_line  = *((char**) first_ptr);
	char* second_line = *((char**) second_ptr);

    size_t first_len  = len_line (first_line);
    size_t second_len = len_line (second_line);

    size_t index_first  = 2;
    size_t index_second = 2; // TODO magic number
    
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
    int index_of_symbol = 0;

    while (line_ptr[index_of_symbol] != '\0')
    {
        index_of_symbol++;
    }

    return index_of_symbol++;
}
