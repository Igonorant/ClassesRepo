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
	Logger(const std::string& customType, bool setCustomToDefault = true);

	// log for string
	void Log(const std::string& message, Type type);
	void Log(const std::string& message);
	
	// log for any type supported by to_string
	template <class anyType>
	void Log(const anyType& message, Type type)
	{
		Log(std::to_string(message), type);
	}
	template <class anyType>
	void Log(const anyType& message)
	{
		Log(std::to_string(message));
	}


	void NewLines(int nLines, const std::string& filling);
	void NewLines(int nLines);
	void NewLine()
	{
		NewLines(1);
	}

	void ChangeCustomType(const std::string& newTypeName);

private:
	std::string customType = "Custom";
	bool customIsDefault = false;

};