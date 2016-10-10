#include "text.h"
#include<fstream>
#include <iostream>
#include<stdlib.h>
#include "tokenize.h"

using namespace std;

void text::inputText(const char* fileName)
{
    ifstream fin;
    fin.open(fileName);

    fin.seekg(0,ios::end);
    streamsize size = fin.tellg();
    fin.seekg(0,ios::beg);

    char* contents = new char[size];
    fin.read(contents, size);


    clear();

    //separate data into pages
    char** tempData = NULL;
    tokenize(contents, '\n', "\"\"", tempData, storyPages, false, false);

    storyData = new char**[storyPages];
    storyPageSize = new int[storyPages];

    //separate each page's data
    for(int i=0; i<storyPages; i++)
    {
        storyData[i] = NULL;
        storyPageSize[i] = 0;

        tokenize(tempData[i], ',', "\"\"", storyData[i], storyPageSize[i], true, true);
    }

    //delete temp variable
    delTok(tempData, storyPages);

}

void text::setVariables(int location)
{
    location = location - 1;

    if (location < 0)
        location = 0;
    else if (location > storyPages)
        location = storyPages - 1;



    storyText =              storyData[location][0];
    option1Text =            storyData[location][1];
    option2Text =            storyData[location][2];
    option3Text =            storyData[location][3];
    option1location =   atoi(storyData[location][4]);
    option2location =   atoi(storyData[location][5]);
    option3location =   atoi(storyData[location][6]);
    healthEffect =      atoi(storyData[location][7]);
    imageNumber =       atoi(storyData[location][8]);
}

void text::clear()
{
    for (int i=0; i<storyPages; i++)
        delTok(storyData[i], storyPageSize[i]);

    if (storyData)
        delete[] storyData;

    if (storyPageSize)
        delete[] storyPageSize;

    storyData = NULL;
    storyPages = 0;
    storyPageSize = NULL;
}

text::text()
{
    storyData = NULL;
    storyPages = 0;
    storyPageSize = NULL;
}

text::~text()
{
    clear();
}
