#include <stdio.h>
#include <assert.h>

#include "find_clean_file.h"

/*Функция получает параметры командной строки argc и argv, 
  ищет флаг -FW, определяющий имя чистого файла для записи сортируемого текста,
  и возвращает указатель на строку с названием чистого файла.*/

const char* find_clean_file (int argc, const char** argv)
{
    assert (argv);
    assert (*argv);

    for (int number_of_word = 1; number_of_word < argc; number_of_word++)
    {
        const char  start_flag         = argv[number_of_word][0];    //Первый символ слова. '-' значит начало флага.
        const char  type_flag          = argv[number_of_word][1];    //Второй символ слова. 'F' значит поиск файла.
        const char  operation_flag     = argv[number_of_word][2];    //Третий символ слова. 'W' значит запись слов в файл.
        const char* beginnig_name_file = argv[number_of_word] + 3;   //Указатель на четвёртый символ слова и, следовательно, на имя файла 

        if (start_flag == '-' && type_flag == 'F' && operation_flag == 'W')
        {
            return (beginnig_name_file);
        }
    }

    return NULL;
}
