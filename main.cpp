#include <Windows.h>
#include <iostream>
#include "logger.h"

void main()
{

	Logger logger("Aviso");

	logger.Log(std::string("Hello World!"),Logger::Type::Custom);
	
	logger.Log("Type the new custom name:");
	
	std::string newName;
	std::cin >> newName;

	logger.ChangeCustomType(newName);

	logger.Log("This is the new custom type name " + newName, Logger::Type::Custom);


	logger.NewLines(3);
	logger.Log("Press space to exit...");
	while (!GetAsyncKeyState(VK_SPACE))
	{
	}


}