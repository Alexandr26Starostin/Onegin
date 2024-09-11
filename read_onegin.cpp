#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int read_onegin (char** ptr_onegin_text, size_t* text_len, size_t* count_line)
{
    assert (ptr_onegin_text);
    assert (text_len);

    FILE* onegin_file = NULL;
    onegin_file = fopen ("onegin2_text.txt", "r");    //командная строка
    if (onegin_file == 0)
    {
        return 1;
    }

    size_t index_text      = 0;
    char   symbol          = 0;

    fseek (onegin_file, 0, SEEK_END);
    size_t count_memory = ftell (onegin_file);
    fseek (onegin_file, 0, SEEK_SET);

    *ptr_onegin_text = (char*) calloc (count_memory + 1, sizeof (char));
    if (*ptr_onegin_text == NULL)
    {
        fclose (onegin_file);
        return 2;
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

    return 0;
}
