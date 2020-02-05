#include "logger.h"

Logger::Logger(const std::string& customType, bool setCustomToDefault)
	:
	customType(customType),
	customIsDefault(setCustomToDefault)
{
}

void Logger::Log(const std::string& message, Type type)
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

void Logger::Log(const std::string& message)
{
	if (customIsDefault)
	{
		Log(message, Type::Custom);
	}
	else
	{
		Log(message, Type::Info);
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
