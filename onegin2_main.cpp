#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "onegin_list_of_const.h"
#include "read_onegin.h"
#include "create_array_of_ptr.h"
#include "print_onegin.h"
#include "onegin_list_func_sort.h"
#include "onegin_qsort.h"

//const char* find_file (int argc, const char** argv);

int main (int argc, const char* argv[])
{
    /*if (find_file (argc, argv))
    {
        printf ("Program not find file with text. Format: -f<name file>\n");
        printf ("Program falled in error: 4.\n");
        return ERROR_FOUR;
    }*/

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

/*const char* find_file (int argc, const char** argv)
{
    assert (argv);

    for (int number_of_word = 1; number_of_word < argc; number_of_word++)
    {
        if (argv[number_of_word][0] = '-' && argv[number_of_word][1] = 'f'):
        {
            return (argv[number_of_word] + 3);
        }
    }

    return = 0;
}*/
