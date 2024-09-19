#include <stdio.h>

#include "conventor_of_symbol.h"

const char conventor_of_symbol (const char symbol) 
{
    if (symbol >= 'a' && symbol <= 'z')     //английские маленькие
    {
        return symbol;
    }

    if (symbol >= 'A' && symbol <= 'Z')     //английские большие
    {
        return symbol - 'A' + 'a';
    }

    if (symbol >= ' ' && symbol <= '@' || symbol >= '[' && symbol <= '`' || symbol >= '{' && symbol <= '~')    //специальные символы
    {
        return ' ';
    }

    return '\0';
}
