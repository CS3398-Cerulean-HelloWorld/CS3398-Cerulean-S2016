#include "CTextButton.h"
#include "CStaticTextBox.h"
#include <iostream>

int main()
{
	CCore::CStaticTextBox textBox (0,0, 300,100, "Some string");

	std::cout << textBox.getText() << std::endl;

	return 0;
}
