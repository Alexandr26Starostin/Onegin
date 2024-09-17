#include <stdio.h>
#include <assert.h>
#include <stdlib.h>


#include "onegin_list_of_const.h"

size_t static len_file (FILE* onegin_file);

enum errors read_onegin (char** ptr_onegin_text, size_t* text_len, size_t* count_line, const char* name_file)
{
    assert (ptr_onegin_text);
    assert (text_len);
    assert (count_line);
    assert (name_file);

    FILE* onegin_file = fopen (name_file, "r"); 
    if (onegin_file == NULL)
    {
        printf ("Not RAM memory for accomplishment fopen: onegin_file\n");
        return ERROR_ONE;
    }

    size_t index_text   = 0;
    char   symbol       = 0;
    size_t count_memory = len_file (onegin_file);

    *ptr_onegin_text = (char*) calloc (count_memory + 1, sizeof (char));
    if (*ptr_onegin_text == NULL)
    {
        fclose (onegin_file);

        printf ("Not RAM memory for accomplishment calloc: ptr_onegin_text\n");
        return ERROR_TWO;
    }

    while ((symbol = fgetc (onegin_file)) != EOF)
    {
        *(*ptr_onegin_text + index_text) = symbol;

        if (symbol == '\n')
        {
            (*count_line)++;

            *(*ptr_onegin_text + index_text) = '\0';
        }

        index_text++;
    } 

    *(*ptr_onegin_text + index_text) = '\0';
    index_text++;

    *text_len = index_text;
    (*count_line)++;

    fclose (onegin_file);

    return ERROR_NOT;
}

size_t static len_file (FILE* onegin_file)
{
    fseek (onegin_file, 0, SEEK_END);
    size_t count_memory = ftell (onegin_file);
    fseek (onegin_file, 0, SEEK_SET);

    return count_memory;
}
