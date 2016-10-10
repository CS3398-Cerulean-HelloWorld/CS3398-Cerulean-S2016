#include "story.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

void story::inputText(const char* fileName)
{
    storyData.load(fileName);
}

void story::setVariables(int location)
{
    if (storyData.good())
    {
        if (location > 0)
            location--;

        storyText =              storyData.getCell(location, 0);
        option1Text =            storyData.getCell(location, 1);
        option2Text =            storyData.getCell(location, 2);
        option3Text =            storyData.getCell(location, 3);
        option1location =   atoi(storyData.getCell(location, 4));
        option2location =   atoi(storyData.getCell(location, 5));
        option3location =   atoi(storyData.getCell(location, 6));
        healthEffect =      atoi(storyData.getCell(location, 7));
        imageNumber =       atoi(storyData.getCell(location, 8));
    }
    else
    {
        cout << "ERROR: Trying to access non-existant page in story.\n";
    }
}

void story::clear()
{
    storyData.clear();
}

story::story()
{
    storyText =         "";
    option1Text =       "";
    option2Text =       "";
    option3Text =       "";
    option1location =   0;
    option2location =   0;
    option3location =   0;
    healthEffect =      0;
    imageNumber =       0;
}
