#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "../../include/list_of_const_and_struct/onegin_list_of_const.h"

#include "../../include/find_name_files/find_text.h"
#include "../../include/find_name_files/find_clean_file.h"

#include "../../include/read_text/read_onegin.h"
#include "../../include/read_text/create_array_of_struct.h"

#include "../../include/sort_text/onegin_list_func_sort.h"
#include "../../include/sort_text/onegin_qsort.h"

#include "../../include/print_text/print_onegin.h"
#include "../../include/print_text/print_original_onegin.h"

/*
  error 1: Не верен указатель на файл с текстом.
  error 2: Не создался массив с текстом.
  error 3: Не создался массив структур.
  error 4: Не указано или неверно указано название файла с текстом.
  error 5: Не определён статус при окончании чтения файла с текстом.
  error 6: Не указано или неверно указано название чистого файла.
  error 7: Не верен указатель на чистый файл.
*/

int main (int argc, const char* argv[])
{
    const char* name_file = find_text (argc, argv);              //Ищет имя файла с текстом.
    if (name_file == NULL)                                       //Проверка, что существует файл с текстом.
    {
        printf ("Program not find file with text. Format: -FR<name file>\n");
        printf ("Program falled in error: 4.\n");
        return ERROR_NOT_FIND_TEXT;
    }

    const char* name_clean_file = find_clean_file (argc, argv);   //Ищет имя чистого файла.
    if (name_clean_file == NULL)                                  //Проверка, что существует чистый файл.
    {
        printf ("Program not find clean file. Format: -FW<name file>\n");
        printf ("Program falled in error: 6.\n");
        return ERROR_NOT_FIND_CLEAN_FILE;
    }

    FILE* clean_file = fopen (name_clean_file, "w");     //Создаём указатель на чистый файл.
    if (clean_file == NULL)                                    //Проверка указателя на чистый файл.
    {
        printf ("Pointer clean_file = 0.\n");
        printf ("Program falled in error: 7.\n");
        return ERROR_WITH_PTR_CLEAN_FILE;
    }

    struct onegin_data inf_about_text {.ptr_onegin_text = NULL,       //Структура с данными по тексту: указатель на начало текста, длина текста, количество строк, указатель на массив структур.
                                       .text_len        = 0,
                                       .count_line      = 0,
                                       .array_of_struct = NULL,
                                      };

    enum errors error_from_read = read_onegin (&inf_about_text.ptr_onegin_text,        //записывает текст в память, считает количество символов и строк. 
                                               &inf_about_text.text_len, 
                                               &inf_about_text.count_line, name_file);

    switch ((int) error_from_read)                //Проверка корректности чтения текста из файла.
    {
        case ERROR_NOT:
            break;
        
        case ERROR_WITH_PTR_TEXT_FILE:
            printf ("Program falled in error: 1.\n");

            free (inf_about_text.ptr_onegin_text);
            fclose (clean_file);

            return ERROR_WITH_PTR_TEXT_FILE;
            break;

        case ERROR_WITH_PTR_TEXT:
            printf ("Program falled in error: 2.\n");

            free (inf_about_text.ptr_onegin_text);
            fclose (clean_file);

            return ERROR_WITH_PTR_TEXT;
            break;
        
        default:
            printf ("Not find type of error.\n");
            printf ("program falled in error: 5.\n");

            free (inf_about_text.ptr_onegin_text);
            fclose (clean_file);

            return ERROR_STATUS_OF_READ_TEXT;
            break;
    }

    inf_about_text.array_of_struct = (line_data*) calloc (inf_about_text.count_line, sizeof (line_data));   //Создаём пустой массив структур.
    if (inf_about_text.array_of_struct == NULL)                                                                   //Проверка, что массив структур существует. 
    {
        printf ("Not RAM memory for accomplishment calloc: array_of_struct.\n");
        printf ("Program falled in error: 3.\n");

        free (inf_about_text.ptr_onegin_text);
        fclose (clean_file);

        return ERROR_WITH_ARRAY_OF_STRUCT;
    }

    create_array_of_struct (&inf_about_text);           //Создаёт массив структур.

    qsort (inf_about_text.array_of_struct, inf_about_text.count_line, sizeof (line_data), &compare_str);   //Сортирует строки от A до Z.
    print_onegin (&inf_about_text, clean_file);      //Печатает в чистый файл по массиву структур.

    onegin_qsort (inf_about_text.array_of_struct, inf_about_text.count_line, sizeof (line_data), &compare_str_for_rhyme);   //Сортирует строки по рифме.
    print_onegin (&inf_about_text, clean_file);      //Печатает в чистый файл по массиву структур.

    print_original_onegin (&inf_about_text, clean_file); //Печатает оригинальный текст в чистый файл

    free (inf_about_text.ptr_onegin_text);      //Освобождаем память.
    free (inf_about_text.array_of_struct);

    fclose (clean_file);                       //Закрываем чистый файл.
    
    printf ("Program finish.\n");
    return ERROR_NOT; 
}
