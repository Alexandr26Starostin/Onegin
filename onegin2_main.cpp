#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "onegin_list_of_const.h"
#include "find_text.h"
#include "read_onegin.h"
#include "create_array_of_ptr.h"
#include "print_onegin.h"
#include "onegin_list_func_sort.h"
#include "onegin_qsort.h"

//const char* find_file (int argc, const char** argv);

int main (int argc, const char* argv[])
{
    const char* name_file = find_text (argc, argv);
    if (name_file == NULL)
    {
        printf ("Program not find file with text. Format: -F<name file>\n");
        printf ("Program falled in error: 4.\n");
        return ERROR_FOUR;
    }

    struct onegin_data inf_about_text {.ptr_onegin_text = NULL,
                                       .text_len        = 0,
                                       .count_line      = 0,
                                       .array_of_ptr    = NULL,
                                      };

    enum errors error_from_read = read_onegin (&inf_about_text.ptr_onegin_text, 
                                               &inf_about_text.text_len, 
                                               &inf_about_text.count_line, name_file);

    switch (error_from_read)
    {
        case ERROR_NOT:
            break;
        
        case ERROR_ONE:
            printf ("Program falled in error: 1.\n");
            return ERROR_ONE;
            break;

        case ERROR_TWO:
            printf ("Program falled in error: 2.\n");
            return ERROR_TWO;
            break;
        
        default:
            printf ("Not find type of error.\n");
            printf ("program falled in error: 5.\n");
            return ERROR_FIVE;
            break;
    }

    inf_about_text.array_of_ptr = (char**) calloc (inf_about_text.count_line, sizeof (char*)); 
    if (inf_about_text.array_of_ptr == NULL)
    {
        printf ("Not RAM memory for accomplishment calloc: array_of_ptr.\n");
        printf ("Program falled in error: 3.\n");
        return ERROR_THREE;
    }

    create_array_of_ptr (inf_about_text);
    print_onegin (inf_about_text);

    onegin_qsort (inf_about_text.array_of_ptr, inf_about_text.count_line, sizeof (char**), compare_str);
    print_onegin (inf_about_text);

    onegin_qsort (inf_about_text.array_of_ptr, inf_about_text.count_line, sizeof (char**), compare_str_for_rhyme);
    print_onegin (inf_about_text);

    free (inf_about_text.ptr_onegin_text);
    free (inf_about_text.array_of_ptr);
    
    printf ("Program finish.\n");
    return ERROR_NOT; 
}
