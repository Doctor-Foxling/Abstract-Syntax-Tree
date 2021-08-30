#pragma once

#include <string>

class Error
{
public:
	Error(); // default  constructor
	Error(std::string error_name, std::string details);

	std::string as_string();
protected:
	std::string m_errorName;
	std::string m_details;
};


class IllegalCharError : public Error
{
public:
	IllegalCharError(std::string details);
	IllegalCharError(char details);
};