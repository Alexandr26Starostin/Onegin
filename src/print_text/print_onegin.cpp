#include <stdio.h>
#include <assert.h>

#include "../../include/list_of_const_and_struct/onegin_list_of_const.h"
#include "../../include/print_text/print_onegin.h"

#define SEPARATOR_TEXT "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"

//Печатает по строчкам обработанный текст в чистый файл.

void print_onegin (onegin_data* inf_about_text, FILE* clean_file)
{
    assert (inf_about_text);
    assert ((*inf_about_text).array_of_struct);
    assert (clean_file);

    const size_t count_line = (*inf_about_text).count_line;    //Количество строк в тексте.

    for (size_t number_of_line = 0; number_of_line < count_line; number_of_line++)  //Пробегается по номеру каждой строки.
    {
        assert (number_of_line < count_line);

        fprintf (clean_file, "%s\n", ((*inf_about_text).array_of_struct[number_of_line]).begin_line);   //печатает строку в файл. 
                        //Переход в структуру о тексте -> указатель на массив структур -> структура о строке по номеру строки -> указатель на начало строки.
    }

    fprintf (clean_file, SEPARATOR_TEXT);   //Разделяет разные обработки текста в чистом файле.
}
