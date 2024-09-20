#include <stdio.h>
#include <assert.h>

#include "../../include/list_of_const_and_struct/onegin_list_of_const.h"
#include "../../include/sort_text/conventor_of_symbol.h"
#include "../../include/sort_text/onegin_list_func_sort.h"

/*Сортирует строки от A до Z.*/

int compare_str (const void* first_ptr, const void* second_ptr)
{
    assert (first_ptr);
    assert (second_ptr);

    struct line_data first_struct  = *((line_data*) first_ptr);   //Структура с первой строкой.
    struct line_data second_struct = *((line_data*) second_ptr);  //Структура со второй строкой.

	char* first_line  = first_struct.begin_line;         //Указатель на первую строку.
	char* second_line = second_struct.begin_line;        //Указатель на вторую строку.

    size_t index_symbol = 0;  //Индекс для пробега с начала строк по каждому их символу.
    int    difference   = 0;  //Разность кодов символов.

    while ((difference = conventor_of_symbol(first_line[index_symbol]) - conventor_of_symbol(second_line[index_symbol])) == 0   //Прерывается, когда символы не равны или оба равны '\0'.
            && first_line[index_symbol] != '\0')
    {
        index_symbol++;
    }

    return difference;
}

/*Сортирует строки по рифме, те по концу от A до Z.*/

int compare_str_for_rhyme (void* first_ptr, void* second_ptr)
{
    assert (first_ptr);
    assert (second_ptr);

    struct line_data first_struct  = *((line_data*) first_ptr);    //Структура с первой строкой.
    struct line_data second_struct = *((line_data*) second_ptr);   //Структура с второй строкой.

	char* first_line  = first_struct.begin_line;           //Указатель на первую строку.
	char* second_line = second_struct.begin_line;          //Указатель на вторую строку.

    size_t first_len  = first_struct.len_line;             //Длина первой строки.
    size_t second_len = second_struct.len_line;            //Длина второй строки.

    size_t index_first  = 2; //Индекс для прохода по символам с конца строки. Он = 2, тк последний символ строки '\0' задаётся адресом len_line - 1. Тк в наших строках не '\n', то первый "рабочий" символ будет предпоследний и будет задаваться адресом len_line - 2. 
    size_t index_second = 2;
    
    int difference = 0;

    while (index_first <= first_len && index_second <= second_len && 
           (difference = conventor_of_symbol (first_line[first_len - index_first]) - conventor_of_symbol (second_line[second_len - index_second])) == 0)   //Прервётся, если какой-либо индекс дойдёт до начала строки или есди разность символов не равна 0.
    {
        index_first++;   //Каждый индекс смещается влево к началу строки на одну позицию.
        index_second++;
    }

    return difference;
}
