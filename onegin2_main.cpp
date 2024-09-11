#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "onegin_list_of_const.h"
#include "read_onegin.h"
#include "create_array_of_ptr.h"
#include "print_onegin.h"
#include "sort_onegin.h"

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
        free (ptr_onegin_text);
        return 4;
    }

    create_array_of_ptr (ptr_onegin_text, text_len, array_of_ptr);

    print_onegin (array_of_ptr, count_line);

    sort_onegin (array_of_ptr, count_line);

    print_onegin (array_of_ptr, count_line);

    free (ptr_onegin_text);
    free (array_of_ptr);
    
    return 0; 
}

//rifma
//print sorted

/*size_t len_line (char* line_ptr)
{
    assert (line_ptr);
    int i = 0;

    while (line_ptr[i] != '\0')
    {
        i++
    }

    return i++;
}

void rhyme_onegin (char** array_of_ptr, size_t count_line)
{
    assert (array_of_ptr);

    for (int g = count_line; g > 0; g--)
    {
        for (int i = 0; i < g - 1; i++)
        {
            if (compare_for_rhyme (array_of_ptr[i], array_of_ptr[i + 1]))
            {
            }
        }
    }
}

int compare_for_rhyme (char* first_line, char* second_line)
{
    assert (first_line);
    assert (second_line);

    size_t first_len  = len_line (array_of_ptr[i]);
    size_t second_len = len_line (array_of_ptr[i + 1]);

    size_t index_first  = 1;
    size_t index_second = 1;

    while (index_first <= first_len && index_second <= )
}
*/
