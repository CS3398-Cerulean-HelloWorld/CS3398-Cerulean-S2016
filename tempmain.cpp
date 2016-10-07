#include<iostream>
#include "text.cpp"
#include "text.h"
using namespace std;

int main()
{

    int choice = 0;

    text object1;
    object1.inputText("gametext.csv");
    object1.setVariables(0);
    while(true)
    {
        cout<<object1.storyText<<endl<<object1.option1Text<< ' ' << object1.option1location
            <<endl<<object1.option2Text<< ' ' << object1.option2location
            <<endl<<object1.option3Text<< ' ' << object1.option3location<<endl
            <<"Enter Choice: ";
        cin>>choice;
        if(choice == 1)
            object1.setVariables(object1.option1location);
        else if (choice == 2)
            object1.setVariables(object1.option2location);
        else
            object1.setVariables(object1.option3location);
    }

    return 0;
}
