#include "logger.h"

Logger::Logger(const std::string &customType)
	:
	customType(customType)
{
}

void Logger::Log(const std::string &message, Type type)
{

	switch (type)
	{
	case Type::Info:
		std::cout << message << std::endl;
		break;

	case Type::Warning:
		std::cout << "[Warning] " << message << std::endl;
		break;

	case Type::Error:
		std::cout << "[Error] " << message << std::endl;
		break;

	case Type::Custom:
		std::cout << "[" << customType << "] " << message << std::endl;
		break;
	}

}

void Logger::NewLines(int nLines, const std::string& filling)
{
	for (int n = 0; n < nLines; n++)
	{
		std::cout << filling << std::endl;
	}
}

void Logger::NewLines(int nLines)
{
	NewLines(nLines, "");
}

void Logger::ChangeCustomType(const std::string& newTypeName)
{
	customType = newTypeName;
}
