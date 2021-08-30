#pragma once

#include <string>
#include <iostream>
#include <typeinfo>

#include "Position.h"

class Error
{
public:
	Error(); // default  constructor
	Error(std::shared_ptr<Position>& pos_start, std::shared_ptr<Position>& pos_end, std::string error_name, std::string details);

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
	std::shared_ptr<Position> m_posStart;
	std::shared_ptr<Position> m_posEnd;
	std::string m_errorName;
	std::string m_details;
	bool initialized = false;
};


class IllegalCharError : public Error
{
public:
	IllegalCharError(std::shared_ptr<Position>& pos_start, std::shared_ptr<Position>& pos_end, std::string details);
	IllegalCharError(std::shared_ptr<Position>& pos_start, std::shared_ptr<Position>& pos_end, char details);
};