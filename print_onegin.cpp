#include <stdio.h>
#include <assert.h>

#include "onegin_list_of_const.h"

void print_onegin (struct onegin_data inf_about_text)
{
    assert (inf_about_text.array_of_ptr);

    for (int number_of_line = 0; number_of_line < inf_about_text.count_line; number_of_line++)
    {
        printf ("%s\n", inf_about_text.array_of_ptr[number_of_line]);

    }

    printf ("\n\n\n");
}
