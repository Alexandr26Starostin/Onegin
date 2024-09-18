#ifndef ONEGIN_LIST_OF_CONST_H
#define ONEGIN_LIST_OF_CONST_H

enum errors {ERROR_NOT                  = 0,
             ERROR_WITH_PTR_TEXT_FILE   = 1,
             ERROR_WITH_PTR_TEXT        = 2,
             ERROR_WITH_ARRAY_OF_STRUCT = 3,
             ERROR_NOT_FIND_TEXT        = 4,
             ERROR_STATUS_OF_READ_TEXT  = 5,
             ERROR_NOT_FIND_CLEAN_FILE  = 6,
             ERROR_WITH_PTR_CLEAN_FILE  = 7};

struct line_data {const char* begin_line,
                  const size_t line_len};

struct onegin_data {char*  ptr_onegin_text;
                    size_t text_len;
                    size_t count_line;
                    (struct line_data)** array_of_struct;
                   };

#endif
