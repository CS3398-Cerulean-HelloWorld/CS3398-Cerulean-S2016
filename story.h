#ifndef STORY_H_INCLUDED
#define STORY_H_INCLUDED

#include<string>
#include "readCSV.h"

using namespace std;

class story
{
private:
    csvData storyData;

public:
    string storyText;
    string option1Text;
    string option2Text;
    string option3Text;
    int option1location;
    int option2location;
    int option3location;
    int healthEffect;
    int imageNumber;

    void inputText(const char*);
    void setVariables(int);

    story();
    void clear();
};

#endif // STORY_H_INCLUDED
