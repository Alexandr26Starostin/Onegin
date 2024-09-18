#include <stdio.h>
#include <assert.h>

#include "onegin_list_of_const.h"

#define SECTION_SPLITTER "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"

void print_onegin (struct onegin_data inf_about_text, FILE* clean_file)
{
    assert (inf_about_text.array_of_ptr);
    assert (clean_file);

    for (int number_of_line = 0; number_of_line < inf_about_text.count_line; number_of_line++)
    {
        fprintf (clean_file, "%s\n", inf_about_text.array_of_ptr[number_of_line]);
    }

    fprintf (clean_file, SECTION_SPLITTER);
}
