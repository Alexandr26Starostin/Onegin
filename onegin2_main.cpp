#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "onegin_list_of_const.h"
#include "read_onegin.h"
#include "create_array_of_ptr.h"
#include "print_onegin.h"
#include "sort_onegin.h"
#include "rhyme_onegin.h"

int main (int argc, char* argv[])
{
    struct onegin_data inf_about_text {.ptr_onegin_text = NULL,
                                       .text_len        = 0,
                                       .count_line      = 0,
                                       .array_of_ptr    = NULL,
                                      };

    enum errors error_from_read = read_onegin (&inf_about_text.ptr_onegin_text, 
                                               &inf_about_text.text_len, 
                                               &inf_about_text.count_line);

    switch (error_from_read)
    {
        case ERROR_NOT:
            break;
        
        case ERROR_ONE:
            printf ("Program falled in error: 1.\n");
            break;

        case ERROR_TWO:
            printf ("Program falled in error: 2.\n");
            break;
        
        default:
            printf ("Not find type of error.\n");
            printf ("program falled.\n");
            break;
    }

    inf_about_text.array_of_ptr = (char**) calloc (inf_about_text.count_line, sizeof (char*)); 
    if (inf_about_text.array_of_ptr == NULL)
    {
        printf ("Not RAM memory for accomplishment calloc: array_of_ptr.\n");
        printf ("Program falled in error: 3.\n");
        return ERROR_THREE;
    }

    create_array_of_ptr (inf_about_text.ptr_onegin_text, inf_about_text.text_len, inf_about_text.array_of_ptr);
    print_onegin (inf_about_text.array_of_ptr, inf_about_text.count_line);

    sort_onegin (inf_about_text.array_of_ptr, inf_about_text.count_line);
    print_onegin (inf_about_text.array_of_ptr, inf_about_text.count_line);

    rhyme_onegin (inf_about_text.array_of_ptr, inf_about_text.count_line);
    print_onegin (inf_about_text.array_of_ptr, inf_about_text.count_line);

    free (inf_about_text.ptr_onegin_text);
    free (inf_about_text.array_of_ptr);
    
    printf ("Program finish.\n");
    return ERROR_NOT; 
}
