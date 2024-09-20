#include <stdio.h>
#include <assert.h>

#include "../../include/list_of_const_and_struct/onegin_list_of_const.h"
#include "../../include/read_text/create_array_of_struct.h"

/*Создаёт массив структур, содержащих данные о строках в тексте: указатель на начало строки и eё длину.*/

void create_array_of_struct (onegin_data* inf_about_text)
{
    assert (inf_about_text);
    assert ((*inf_about_text).array_of_struct);
    assert ((*inf_about_text).ptr_onegin_text);

    size_t index_array_of_struct = 0;      //Индекс, пробегающий по всем структурам в маасиве структур.

    char* ptr_on_beginning_text = (*inf_about_text).ptr_onegin_text;   //Указатель на начало текста.
    char* ptr_on_last_line      = ptr_on_beginning_text;               //Указатель на начало новой строки в массиве с текстом.

    for (size_t number_of_symbol = 0; number_of_symbol < (*inf_about_text).text_len; number_of_symbol++)     //Пробегает по каждому символу текста
    {
        assert (number_of_symbol <= (*inf_about_text).text_len - 1);

        char* ptr_on_symbol_in_text = ptr_on_beginning_text + number_of_symbol;     //Указатель на рассматриваемый символ в тексте.

        if (*(ptr_on_symbol_in_text) == '\0')          //Рассматриваемый символ = '\0'; значит нашёлся конец строки.
        {
            *((*inf_about_text).array_of_struct + index_array_of_struct) = {ptr_on_last_line, (size_t) (ptr_on_symbol_in_text - ptr_on_last_line + 1)};   //Записывает структуру в массив структур.
                                                                                                                        //+1, тк при разности не учитывается первый символ строки.
                                                                                                                        
            ptr_on_last_line = ptr_on_symbol_in_text + 1;  //Записывает указатель на новую строку.
            index_array_of_struct++;                   //Следующий элемент в массиве структур.
            
        }
    } 
}
