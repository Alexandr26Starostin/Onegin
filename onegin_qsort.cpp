#include <stdio.h>
#include <assert.h>

void static change_element (char* first_ptr, char* second_ptr, const size_t len_type);

void onegin_qsort (const void* array, const size_t len_array, const size_t len_type, int (*compare_element) (void* first_element, void* second_element))
{
	assert (array);
	assert (compare_element);

	for (int numbers_to_sort = len_array; numbers_to_sort > 0; numbers_to_sort--)
    {
        for (int index_of_pair = 0; index_of_pair < numbers_to_sort - 1; index_of_pair++)
        {
			char* first_ptr  = (char*) array + index_of_pair       * len_type;
			char* second_ptr = (char*) array + (index_of_pair + 1) * len_type;

			if ((*compare_element) (first_ptr, second_ptr) > 0)
			{
				change_element (first_ptr, second_ptr, len_type);
			}
		}
	}
}

void static change_element (char* first_ptr, char* second_ptr, const size_t len_type)
{
	assert (first_ptr);
	assert (second_ptr);

	for (int index_of_byte = 0; index_of_byte < len_type; index_of_byte++)
	{
		char temporary            = first_ptr[index_of_byte];
		first_ptr[index_of_byte]  = second_ptr[index_of_byte];
		second_ptr[index_of_byte] = temporary;
	}

}
