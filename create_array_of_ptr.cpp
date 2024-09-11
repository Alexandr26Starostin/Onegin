#include <stdio.h>
#include <assert.h>

void create_array_of_ptr (char* ptr_onegin_text, size_t text_len, char** array_of_ptr)
{
    assert (array_of_ptr);
    assert (ptr_onegin_text);

    size_t index_array_of_ptr = 1;

    *(array_of_ptr) = ptr_onegin_text; 

    for (int i = 1; i < text_len - 1; i++)
    {
        if (*(ptr_onegin_text + i) == '\0')
        {
            *(array_of_ptr + index_array_of_ptr) = (ptr_onegin_text) + (i + 1);
            index_array_of_ptr++;
        }
    } 
}
