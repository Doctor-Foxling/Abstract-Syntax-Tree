#include "Error.h"

Error::Error()
{
}

Error::Error(std::shared_ptr<Position>& pos_start, std::shared_ptr<Position>& pos_end, std::string error_name, std::string details)
	: m_posStart(pos_start), m_posEnd(pos_end),
	m_errorName(error_name), m_details(details), initialized(true)
{}

std::string Error::as_string()
{
	std::string ret_val = m_errorName + ": " + "'" + m_details + "'  |";
	ret_val += "File " + m_posStart->getFileName() + ", line " + std::to_string(m_posStart->getLine());
	return ret_val;
}

IllegalCharError::IllegalCharError(std::shared_ptr<Position>& pos_start, std::shared_ptr<Position>& pos_end, std::string details)
{
	m_errorName = "Illegal Character";
	m_details = details;
}

IllegalCharError::IllegalCharError(std::shared_ptr<Position>& pos_start, std::shared_ptr<Position>& pos_end, char details)
{
	m_errorName = "Illegal Character";
	m_details = details;
	m_posStart = pos_start;
	m_posEnd = pos_end;
}