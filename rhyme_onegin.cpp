#include <stdio.h>
#include <assert.h>

#include "onegin_list_of_const.h"
#include "conventor_of_symbol.h"

int static compare_for_rhyme (char* first_line, char* second_line);
size_t static len_line (char* line_ptr);

void rhyme_onegin (struct onegin_data inf_about_text)
{
    assert (inf_about_text.array_of_ptr);

    for (int numbers_to_sort = inf_about_text.count_line; numbers_to_sort > 0; numbers_to_sort--)
    {
        for (int index_of_pair = 0; index_of_pair < numbers_to_sort - 1; index_of_pair++)
        {
            if (compare_for_rhyme (inf_about_text.array_of_ptr[index_of_pair], inf_about_text.array_of_ptr[index_of_pair + 1]) > 0)
            {
                char* temporary                                = inf_about_text.array_of_ptr[index_of_pair];
                inf_about_text.array_of_ptr[index_of_pair]     = inf_about_text.array_of_ptr[index_of_pair + 1];
                inf_about_text.array_of_ptr[index_of_pair + 1] = temporary;
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
    int index_of_symbol = 0;

    while (line_ptr[index_of_symbol] != '\0')
    {
        index_of_symbol++;
    }

    return index_of_symbol++;
}
