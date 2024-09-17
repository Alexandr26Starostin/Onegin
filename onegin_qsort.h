#ifndef ONEGIN_QSORT_H
#define ONEGIN_QSORT_H

void onegin_qsort (const void* array, const size_t len_array, const size_t len_type, int (*compare_element) (void* first_element, void* second_element));

#endif
