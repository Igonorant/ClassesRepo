#include "logger.h"

Logger::Logger(const std::string& customType, bool setCustomToDefault)
	:
	customType(customType),
	customIsDefault(setCustomToDefault)
{
}

void Logger::NewLines(int nLines)
{
	NewLines(nLines, "");
}

void Logger::ChangeCustomType(const std::string& newTypeName)
{
	customType = newTypeName;
}
