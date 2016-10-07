#ifndef STRLEN_H_INCLUDED
#define STRLEN_H_INCLUDED

#include "def.h"

int len(const str String)
{
    int i = 0;

    while (String[i] != null)
        i++;

    return i;
}

#endif // STRLEN_H_INCLUDED
