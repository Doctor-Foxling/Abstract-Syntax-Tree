#pragma once

#include <string>

#include "TokenType.h"


class Token
{
public:
	union tk_data_type
	{
		int tk_int;
		float tk_float;
		char tk_char;
	} tk_data;
	Token(TT type) : m_Type(type) {}
	virtual ~Token() {}

	TT getType() { return m_Type; }
	virtual tk_data_type getData() = 0;

	virtual std::string repr() = 0;
protected:
	TT m_Type;
};

template<typename dataType>
class TypedToken : public Token
{
public:
	TypedToken(TT type, dataType value) : Token(type) {
		if (type == TT::INT)
			tk_data.tk_int = (int)value;
		else if (type == TT::FLOAT)
			tk_data.tk_float = (float)value;
		else
			tk_data.tk_char = (char)value;
	}
	TypedToken(TT type) : Token(type) {
		if (type == TT::INT)
			tk_data.tk_int = (int)0;
		else if (type == TT::FLOAT)
			tk_data.tk_float = (float)0;
		else
			tk_data.tk_char = (char)0;
	}

	virtual tk_data_type getData() override { 
		if (m_Type == TT::INT)
		{
			tk_data.tk_int;
			return tk_data;
		}
		else if (m_Type == TT::FLOAT)
		{
			tk_data.tk_float;
			return tk_data;
		}
		else
		{
			tk_data.tk_char;
			return tk_data;
		}
	}

	virtual std::string repr() override
	{
		if (m_Type == TT::INT)
			return TT_to_string(m_Type) + ": " + std::to_string(tk_data.tk_int);
		else if (m_Type == TT::FLOAT)
			return TT_to_string(m_Type) + ": " + std::to_string(tk_data.tk_float);
		else
			return TT_to_string(m_Type) + ": " + "None";
	}
};