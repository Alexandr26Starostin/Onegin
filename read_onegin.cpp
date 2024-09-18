#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "onegin_list_of_const.h"
#include "read_onegin.h"

const size_t static len_file (const FILE* onegin_file);

/*Записывает текст из файла в память и собирает информацию о тексте: указатель на начало текста, длина текста и количество строк.*/

enum errors read_onegin (const char** ptr_onegin_text, const size_t* text_len, const size_t* count_line, const char* name_file)
{
    assert (ptr_onegin_text);
    assert (text_len);
    assert (count_line);
    assert (name_file);

    const FILE* onegin_file = fopen (name_file, "r");   //Создаёт указатель на файл с текстом.
    if (onegin_file == NULL)                            //Проверка указателя на файл с текстом.
    {
        printf ("Not RAM memory for accomplishment fopen: onegin_file\n");
        return ERROR_WITH_PTR_TEXT_FILE;
    }

    size_t index_text   = 0;
    char   symbol       = '\0';
    const size_t count_memory = len_file (onegin_file);

    *ptr_onegin_text = (char*) calloc (count_memory + 1, sizeof (char));    //Создаёт указатель на массив с текстом.  +1 нужен для дополнительного '\0'  в конце текста, если текстовый файл не заканчивается '\n'.
    if (*ptr_onegin_text == NULL)                                           //Проверка указателя на массив с текстом.
    {
        fclose (onegin_file);

        printf ("Not RAM memory for accomplishment calloc: ptr_onegin_text\n");
        return ERROR_WITH_PTR_TEXT;
    }

    while ((symbol = fgetc (onegin_file)) != EOF)       //Читает текст.
    { 
        if (symbol != '\r')                             //Сводит формат \r\n к \n. Если был формат \n, то он не меняется.
        {
            *(*ptr_onegin_text + index_text) = symbol;      //Записывает текст.

            if (symbol == '\n')                             //Заменяет '\n' на '\0' и считает количество строк.
            {
                (*count_line)++;

                *(*ptr_onegin_text + index_text) = '\0';
            }

            index_text++;
        }
    } 

    *(*ptr_onegin_text + index_text) = '\0';           //Запись '\0' в конце файла.
    index_text++;

    *text_len = index_text;                           //Длина текста.
    (*count_line)++;

    fclose (onegin_file);                             //Закрытие файла с текстом.

    return ERROR_NOT;
}

/*Считает размер файла.*/

const size_t static len_file (const FILE* onegin_file)      
{ 
    assert (onegin_file);

    fseek (onegin_file, 0, SEEK_END);
    const size_t count_memory = ftell (onegin_file);
    fseek (onegin_file, 0, SEEK_SET);

    return count_memory;
}
