#ifndef STRLEN_H_INCLUDED
#define STRLEN_H_INCLUDED

#ifndef str
#define str char*
#endif // str

#ifndef chr
#define chr char
#endif // chr

#ifndef null
#define null '\0'
#endif // null

int len(const str String)
{
    int i = 0;

    while (String[i] != null)
        i++;

    return i;
}

#endif // STRLEN_H_INCLUDED
