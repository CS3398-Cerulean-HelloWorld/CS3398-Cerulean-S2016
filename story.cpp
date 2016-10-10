#include "story.h"
#include <iostream>
#include <stdlib.h>

#ifndef HEALTH_MAX
#define HEALTH_MAX 100
#endif // HEALTH_MAX

#ifndef HEALTH_INIT
#define HEALTH_INIT HEALTH_MAX
#endif // HEALTH_INIT

using namespace std;

void story::inputText(const char* fileName)
{
    if (!storyData.load(fileName))
        cout << "ERROR: Unable to load '" << fileName << "'\n";
}

void story::setVariables(int location)
{
    if (storyData.good())
    {
        healthEffect = 0;

        bool allValid = true;
        for (int i=1; i<10; i++)
            if (!storyData.isValidCell(location, i))
                allValid = false;

        if (allValid)
        {
            storyText = storyData.getCell(location, 1);
            option1Text = storyData.getCell(location, 2);
            option2Text = storyData.getCell(location, 3);
            option3Text = storyData.getCell(location, 4);
            option1location = atoi(storyData.getCell(location, 5));
            option2location = atoi(storyData.getCell(location, 6));
            option3location = atoi(storyData.getCell(location, 7));
            healthEffect = atoi(storyData.getCell(location, 8));
            imageNumber =  atoi(storyData.getCell(location, 9));


            currentPage = location;

            if (healthEffect < 0)
            {
                health += healthEffect;

                if (health < 0)
                    health = 0;
            }
            else if ((health + healthEffect) <= HEALTH_MAX)
            {
                health += healthEffect;
            }
        }
        else
        {
            cout << "Story  ROW=[" << location << "] is missing data.\n";
        }

    }
    else
    {
        cout << "ERROR: Unable to load story.\n";
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

    currentPage = 0;
    health = HEALTH_INIT;
}
