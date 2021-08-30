#pragma once

#include <string>
#include <iostream>
#include <typeinfo>

class Error
{
public:
	Error(); // default  constructor
	Error(std::string error_name, std::string details);

	std::string as_string();
	bool operator==(const Error* other) const
	{
		if (!initialized || (typeid(*this) != typeid(*other)))
			return false;
		else if (this->m_errorName == other->m_errorName)
			return true;
		return false;
	}
	bool operator!=(const Error* other) const { return !(operator==(other)); }
	bool isInitialized() { return initialized; }
protected:
	std::string m_errorName;
	std::string m_details;
	bool initialized = false;
};


class IllegalCharError : public Error
{
public:
	IllegalCharError(std::string details);
	IllegalCharError(char details);
};