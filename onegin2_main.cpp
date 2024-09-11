#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int  read_onegin (char** ptr_onegin_text, size_t* text_len, size_t* count_line);
void create_array_of_ptr (char* ptr_onegin_text, size_t text_len, char** array_of_ptr);

void print_onegin (char** array_of_ptr, size_t count_line);

void sort_onegin (char** array_of_ptr, size_t count_line);
int compare (char* first_line, char* second_line);

int main ()
{
    char*  ptr_onegin_text = NULL; 
    size_t text_len        = 0;
    size_t count_line      = 0;

    if (read_onegin (&ptr_onegin_text, &text_len, &count_line))
    {
        return 1;
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

int read_onegin (char** ptr_onegin_text, size_t* text_len, size_t* count_line)
{
    assert (ptr_onegin_text);
    assert (text_len);

    FILE* onegin_file;
    onegin_file = fopen ("onegin2_text.txt", "r");
    if (onegin_file == 0)
    {
        fclose (onegin_file);
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

void print_onegin (char** array_of_ptr, size_t count_line)
{
    for (int i = 0; i < count_line; i++)
    {
        printf ("%s\n", *(array_of_ptr + i));

    }

    printf ("\n\n\n");
}


//rifma
//print sorted



void sort_onegin (char** array_of_ptr, size_t count_line)
{
    assert (array_of_ptr);

    for (int g = count_line; g > 0; g--)
    {
        for (int i = 0; i < g - 1; i++)
        {
            if (compare (*(array_of_ptr + i), *(array_of_ptr + i + 1)) > 0)     //1 > 2 
            {   
                char* temporary   = array_of_ptr[i];
                array_of_ptr[i]   = array_of_ptr[i+1];
                array_of_ptr[i+1] = temporary;
            }
        }
    }
}




int compare (char* first_line, char* second_line)
{
    assert (first_line);
    assert (second_line);

    int i = 0;

    while (conventor_of_symbol(first_line[i]) - conventor_of_symbol(second_line[i]) == 0 && first_line[i] != '\0')
    {
        i++;
    }

    return first_line[i] - second_line[i];
}

char conventor_of_symbol (char symbol)
{
    if (symbol >= 'a' && symbol <= 'z')
    {
        return symbol;
    }

    if (symbol >= 'A' && symbol <= 'Z')
    {
        return symbol - 'A' + 'a';
    }

    if (symbol >= ' ' && symbol <= '/' || symbol >= ':' && symbol <= '@')
    {
        return ' ';
    }
}

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