#include <stdio.h>
#include <assert.h>

#include "../../include/sort_text/onegin_qsort.h"

void static change_element (char* first_ptr, char* second_ptr, const size_t len_type);

/*Осуществляет сортировку по критериям.*/

void onegin_qsort (const void* array, const size_t len_array, const size_t len_type, int (*compare_element) (void* first_element, void* second_element))
{
	assert (array);
	assert (compare_element);

	for (size_t numbers_to_sort = len_array; numbers_to_sort > 0; numbers_to_sort--)    //Сортировка пузырьком.
    {
		assert (numbers_to_sort <= len_array);

        for (size_t index_of_pair = 0; index_of_pair < numbers_to_sort - 1; index_of_pair++)
        {
			assert (index_of_pair <= numbers_to_sort - 2);

			char* first_ptr  = (char*) array + index_of_pair       * len_type;     //Указатель на первый сравниваемый элемент.
			char* second_ptr = (char*) array + (index_of_pair + 1) * len_type;     //Указатель на второй сравниваемый элемент.

			if ((*compare_element) (first_ptr, second_ptr) > 0)     //Сравнение по критериям.
			{
				change_element (first_ptr, second_ptr, len_type);   //Меняет элементы местами.
			}
		}
	}
}

/*Меняет элементы местами по байтам.*/

void static change_element (char* first_ptr, char* second_ptr, const size_t len_type)
{
	assert (first_ptr);
	assert (second_ptr);

	for (size_t index_of_byte = 0; index_of_byte < len_type; index_of_byte++)   //Проход по каждому байту числа.
	{
		assert (index_of_byte <= len_type - 1);

		char temporary            = first_ptr[index_of_byte];           //Замена байтов местами.
		first_ptr[index_of_byte]  = second_ptr[index_of_byte];
		second_ptr[index_of_byte] = temporary;
	}

}
