#include <stdio.h>
#include <assert.h>

#include "../../include/list_of_const_and_struct/onegin_list_of_const.h"
#include "../../include/print_text/print_original_onegin.h"

#define SEPARATOR_TEXT "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"

void print_original_onegin (onegin_data* inf_about_text, FILE* clean_file)
{
	assert (inf_about_text);
	assert (clean_file);
	assert ((*inf_about_text).ptr_onegin_text);

	const size_t text_len = (*inf_about_text).text_len;

	for (size_t index_of_symbol = 0; index_of_symbol < text_len; index_of_symbol++)
	{
		assert (index_of_symbol <= text_len - 1);

		const char symbol = *((*inf_about_text).ptr_onegin_text + index_of_symbol);

		if (symbol == '\0')
		{
			fprintf (clean_file, "\n");
		}
		else
		{
			fprintf (clean_file, "%c", symbol);
		}
	}

}
