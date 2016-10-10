#ifndef TEXT_H_INCLUDED
#define TEXT_H_INCLUDED

#include<string>
using namespace std;

#define dataPerLine 9

class text
{
private:
    char*** storyData;
    int storyPages;
    int* storyPageSize;

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

     void clear();

     text();
     ~text();
};

#endif // TEXT_H_INCLUDED
