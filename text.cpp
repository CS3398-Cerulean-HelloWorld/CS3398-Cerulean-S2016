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


    story2d = NULL;
    storySize = 0;

    tokenize(contents, ",\n", "\"\"", story2d, storySize, true);
}

void text::setVariables(int location)
{
    if (location < 1)
        location = 1;
    else if (location*dataPerLine > storySize)
        location = 1;

    location = location - 1;

    storyText = story2d[location*dataPerLine + 0];
    option1Text = story2d[location*dataPerLine + 1];
    option2Text =story2d[location*dataPerLine + 2];
    option3Text = story2d[location*dataPerLine + 3];
    option1location = atoi(story2d[location*dataPerLine + 4]);
    option2location = atoi(story2d[location*dataPerLine + 5]);
    option3location = atoi(story2d[location*dataPerLine + 6]);
    healthEffect = atoi(story2d[location*dataPerLine + 7]);
    imageNumber = atoi(story2d[location*dataPerLine + 8]);
}

text::~text()
{
    delTok(story2d, storySize);
}
