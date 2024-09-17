#ifndef ONEGIN_LIST_OF_CONST_H
#define ONEGIN_LIST_OF_CONST_H

enum errors {ERROR_NOT   = 0,
             ERROR_ONE   = 1,
             ERROR_TWO   = 2,
             ERROR_THREE = 3,
             ERROR_FOUR  = 4,
             ERROR_FIVE  = 5,
             ERROR_SIX   = 6,
             ERROR_SEVEN = 7};

struct onegin_data {char*  ptr_onegin_text;
                    size_t text_len;
                    size_t count_line;
                    char** array_of_ptr;
                   };

#endif
