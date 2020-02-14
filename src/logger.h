#pragma once
#include "pch.h"
// iostream, string

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


	template <class anyType>
	void Log(const anyType& message, Type type)
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
	template <class anyType>
	void Log(const anyType& message)
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

	template <class anyType>
	void NewLines(int nLines, const anyType& filling = "")
	{
		for (int n = 0; n < nLines; n++)
		{
			std::cout << filling << std::endl;
		}
	}
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