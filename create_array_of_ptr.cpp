#include <stdio.h>
#include <assert.h>

#include "onegin_list_of_const.h"

void create_array_of_ptr (struct onegin_data inf_about_text)
{
    assert (inf_about_text.array_of_ptr);
    assert (inf_about_text.ptr_onegin_text);

    size_t index_array_of_ptr = 1;

    *(inf_about_text.array_of_ptr) = inf_about_text.ptr_onegin_text; 

    for (int inumber_of_symbol = 1; inumber_of_symbol < inf_about_text.text_len - 1; inumber_of_symbol++)
    {
        if (*(inf_about_text.ptr_onegin_text + inumber_of_symbol) == '\0')
        {
            *(inf_about_text.array_of_ptr + index_array_of_ptr) = (inf_about_text.ptr_onegin_text) + (inumber_of_symbol + 1);
            index_array_of_ptr++;
        }
    } 
}
