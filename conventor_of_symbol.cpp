#include <stdio.h>
#include <assert.h>

char conventor_of_symbol (char symbol)
{
    if (symbol >= 'a' && symbol <= 'z')
    {
        return symbol;
    }

    if (symbol >= 'A' && symbol <= 'Z')
    {
        return symbol - 'A' + 'a';
    }

    if (symbol >= ' ' && symbol <= '/' || symbol >= ':' && symbol <= '@')
    {
        return ' ';
    }

    return '\0';
}
