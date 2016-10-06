#include "CTextButton.h"
#include <iostream>

int main()
{
	CCore::CTextButton button (0,0, 300,100, "Some string");

	std::cout << button.getText() << std::endl;

	return 0;
}