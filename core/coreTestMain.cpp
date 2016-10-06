#include "CTextButton.h"
#include <iostream>

int main()
{
	CCore::CTextButton button ("Some string");

	std::cout << button.getText() << std::endl;

	return 0;
}