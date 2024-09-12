#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "onegin_list_of_const.h"
#include "read_onegin.h"
#include "create_array_of_ptr.h"
#include "print_onegin.h"
#include "sort_onegin.h"
#include "rhyme_onegin.h"

int main ()
{
    char*  ptr_onegin_text = NULL; 
    size_t text_len        = 0;
    size_t count_line      = 0;

    enum errors error_from_read = read_onegin (&ptr_onegin_text, &text_len, &count_line);

    switch (error_from_read)
    {
        case ERROR_NOT:
            break;
        
        case ERROR_ONE:
            printf ("Program falled\n");
            break;

        case ERROR_TWO:
            printf ("Program falled\n");
            break;
        
        default:
            printf ("Not find type of error\n");
            printf ("program falled\n");
            break;
    }

    char** array_of_ptr = (char**) calloc (count_line, sizeof (char*)); 
    if (array_of_ptr == 0)
    {
        printf ("Not RAM memory for accomplishment calloc: array_of_ptr\n");
        return ERROR_THREE;
    }

    create_array_of_ptr (ptr_onegin_text, text_len, array_of_ptr);
    print_onegin (array_of_ptr, count_line);

    sort_onegin (array_of_ptr, count_line);
    print_onegin (array_of_ptr, count_line);

    rhyme_onegin (array_of_ptr, count_line);
    print_onegin (array_of_ptr, count_line);

    free (ptr_onegin_text);
    free (array_of_ptr);
    
    printf ("Program finish\n");
    return ERROR_NOT; 
}

//rifma
//print sorted
