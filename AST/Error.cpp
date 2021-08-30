#include "Error.h"

Error::Error()
{
}

Error::Error(std::string error_name, std::string details)
	: m_errorName(error_name), m_details(details)
{}

std::string Error::as_string()
{
	return m_errorName + ": " + m_details;
}

IllegalCharError::IllegalCharError(std::string details)
{
	m_errorName = "Illegal Character";
	m_details = details;
}

IllegalCharError::IllegalCharError(char details)
{
	m_errorName = "Illegal Character";
	m_details = details;
}
