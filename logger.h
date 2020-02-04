#pragma once

#include <iostream>
#include <string>

class Logger
{
public:
	enum class Type {
		Info = 0,
		Warning,
		Error,
		Custom
	};

public:
	Logger()
	{

	}
	Logger(const std::string &customType);

	void Log(const std::string &message, Type type);
	void Log(const std::string &message)
	{
		Log(message, Type::Info);
	}

	void NewLines(int nLines, const std::string& filling);
	void NewLines(int nLines);
	void NewLine()
	{
		NewLines(1);
	}

	void ChangeCustomType(const std::string &newTypeName);



private:
	std::string customType = "Custom";

};