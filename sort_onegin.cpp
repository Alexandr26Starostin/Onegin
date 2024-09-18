#include <stdio.h>
#include <assert.h>

#include "onegin_list_of_const.h"
#include "conventor_of_symbol.h"

int static compare (char* first_line, char* second_line);

void sort_onegin (struct onegin_data inf_about_text)          
{
    assert (inf_about_text.array_of_ptr);

    for (int numbers_to_sort = inf_about_text.count_line; numbers_to_sort > 0; numbers_to_sort--)
    {
        for (int index_of_pair = 0; index_of_pair < numbers_to_sort - 1; index_of_pair++)
        {
            if (compare (inf_about_text.array_of_ptr[index_of_pair], inf_about_text.array_of_ptr[index_of_pair+1]) > 0)     //1 > 2 
            {   
                char* temporary                              = inf_about_text.array_of_ptr[index_of_pair];
                inf_about_text.array_of_ptr[index_of_pair]   = inf_about_text.array_of_ptr[index_of_pair+1];
                inf_about_text.array_of_ptr[index_of_pair+1] = temporary;
            }
        }
    }
}

int static compare (char* first_line, char* second_line)
{
    assert (first_line);
    assert (second_line);

    size_t index_symbol = 0;
    int difference = 0; 

    while ((difference = conventor_of_symbol(first_line[index_symbol]) - conventor_of_symbol(second_line[index_symbol])) == 0 
            && first_line[index_symbol] != '\0')
    {
        index_symbol++;
    }

    return difference;
}

// TODO download cloc - count lines of code
