#include <stdio.h>

#include "conventor_of_symbol.h"

/*Приводит символы к одному стандарту.*/

char conventor_of_symbol (char symbol) 
{
    if (symbol >= 'a' && symbol <= 'z')     //Английские маленькие - не меняет.
    {
        return symbol;
    }

    if (symbol >= 'A' && symbol <= 'Z')     //Английские большие - меняе на маленькие.
    {
        return symbol - 'A' + 'a';
    }
    
    return ' ';       //Специальные символы - заменяет на пробелы.
}
