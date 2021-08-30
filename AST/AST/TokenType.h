#pragma once

#include <string>

#define TT_INT		= "TT_INT";
#define TT_FLOAT	= "TT_FLOAT";
#define TT_PLUS		= "TT_PLUS";
#define TT_MINUS	= "TT_MINUS";
#define TT_MUL		= "TT_MUL";
#define TT_DIV		= "TT_DIV";
#define TT_LPAREN	= "TT_LPAREN";
#define TT_RPAREN	= "TT_RPAREN";

enum class TT
{
	INT,
	FLOAT,
	PLUS,
	MINUS,
	MUL,
	DIV,
	LPAREN,
	RPAREN,
};

inline std::string TT_to_string(TT tokenType)
{
	switch (tokenType)
	{
	case TT::INT:
		return "TT_INT";
		break;

	case TT::FLOAT:
		return "TT_FLOAT";
		break;

	case TT::PLUS:
		return "TT_PLUS";
		break;

	case TT::MINUS:
		return "TT_MINUS";
		break;

	case TT::MUL:
		return "TT_MUL";
		break;
	case TT::DIV:
		return "TT_DIV";
		break;
	case TT::LPAREN:
		return "TT_LPAREN";
		break;
	case TT::RPAREN:
		return "TT_RPAREN";
		break;
	default:
		return "ERROR";
		break;
	}
}