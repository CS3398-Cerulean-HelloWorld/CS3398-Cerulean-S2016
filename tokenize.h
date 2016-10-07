///Code written by Zachary Westerman, 2016

#ifndef TOKENIZE_H_INCLUDED
#define TOKENIZE_H_INCLUDED

#include "def.h"
#include "strappend.h"
#include "strlen.h"

//function that appends a string to the end of a string
//array, and increases the size appropriately.
//meant to be used exclusively from within tokenize()
void tok_arr_append(str*& strArray, int& arrSize, str newStr)
{
    if (newStr)
    {
        str* oldArray = strArray;

        strArray = new str[arrSize + 1];

        for (int i=0; i<arrSize; i++)
            strArray[i] = oldArray[i];

        strArray[arrSize] = newStr;

        arrSize++;

        if (oldArray)
            delete[] oldArray;
    }
}


//function to separate a string into tokens, given any number of delimiters and 2 quotation symbols.
//tokens are returned as a string array, through parameter
void tokenize(const str String, const str delim, const str enquote, str*& outStrArray, int& outSize, bool removeQuotes)
{
    //get rid of any garbage data
    if (outStrArray)
    {
        for (int i=0; i<outSize; i++)
            delete[] outStrArray[i];

        delete[] outStrArray;
    }

    //prep for string parsing
    outStrArray = NULL;
    outSize = 0;


    if (String)
    {
        int length = len(String);

        str thisToken = NULL;

        bool inQuotes = false;

        bool isOpenQuote = false;
        bool isCloseQuote = false;
        bool isDelim = false;

        //for every character in the string
        for (int i=0; i<length; i++)
        {
            isOpenQuote = false;
            isCloseQuote = false;
            isDelim = false;

            //if there are quotes, determine whether we're within them
            if (enquote)
            {
                if (inQuotes)
                {
                    if (String[i] == enquote[1])
                    {
                        isCloseQuote = true;
                    }
                }
                else
                {
                    if (String[i] == enquote[0])
                    {
                        isOpenQuote = true;
                    }
                }
            }

            //if current character is an open quote, we are within quotes
            if (isOpenQuote)
                inQuotes = true;


            //if the current character is one of the delimiters
            int j = 0;
            if (delim && !inQuotes)
            {
                while (!isDelim && (delim[j] != null))
                {
                    if (String[i] == delim[j])
                    {
                        isDelim = true;
                    }

                    j++;
                }
            }



            if (inQuotes)
            {
                if (isOpenQuote && thisToken)
                {
                    tok_arr_append(outStrArray, outSize, thisToken);

                    thisToken = NULL;
                }

                if (!removeQuotes || (!isOpenQuote && !isCloseQuote))
                {
                    append(thisToken, String[i]);
                }

                if (isCloseQuote && thisToken)
                {
                    tok_arr_append(outStrArray, outSize, thisToken);

                    thisToken = NULL;
                }
            }
            else if (isDelim)
            {
                if (thisToken)
                {
                    tok_arr_append(outStrArray, outSize, thisToken);

                    thisToken = NULL;
                }
            }
            else
            {
                append(thisToken, String[i]);
            }



            if (isCloseQuote)
                inQuotes = false;

        }

        //once we finish parsing the string, if we have a completed
        //token, add it to the output.
        if (thisToken)
        {
            tok_arr_append(outStrArray, outSize, thisToken);

            thisToken = NULL;
        }
    }
}

//same as tokenize, but allows a single char delimiter
void tokenize(const str String, const chr delim, const str enquote, str*& outStrArray, int& outSize, bool removeQuotes)
{
    str delimiter = NULL;
    append(delimiter, delim);

    tokenize(String, delimiter, enquote, outStrArray, outSize, removeQuotes);
}

void delTok(str*& strTok, int& Lines)
{
    if (strTok)
    {
        for (int i=0; i<Lines; i++)
            delete[] strTok[i];

        delete[] strTok;

        strTok = NULL;
    }
}


#endif // TOKENIZE_H_INCLUDED
