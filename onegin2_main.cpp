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

    if (read_onegin (&ptr_onegin_text, &text_len, &count_line))
    {
        return 1;                    //switch
    }

    char** array_of_ptr = (char**) calloc (count_line, sizeof (char*)); 
    if (array_of_ptr == 0)
    {
        return 4;
    }

    create_array_of_ptr (ptr_onegin_text, text_len, array_of_ptr);
    print_onegin (array_of_ptr, count_line);

    sort_onegin (array_of_ptr, count_line);
    print_onegin (array_of_ptr, count_line);

    rhyme_onegin (array_of_ptr, count_line);
    print_onegin (array_of_ptr, count_line);

    free (ptr_onegin_text);
    free (array_of_ptr);
    
    return 0; 
}

//rifma
//print sorted
