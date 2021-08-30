#pragma once
#include <iostream>
#include <vector>
#include <memory>

#include "Token.h"
#include "Utility.h"
#include "Error.h"

static const std::string DIGITS = "0123456789";

//template<typename T>
//struct made_token_val
//{
//	std::deque<Token<T>> tokens;
//	Error* error;
//};

typedef std::vector<std::shared_ptr<Token>> token_list;

class Lexer
{
public:
	Lexer(std::string text);

	void advance();

	std::shared_ptr<token_list> make_tokens();
	std::string make_number(bool& is_int);
private:
	std::string m_Text;
	int m_Pos;
	char m_currentChar;
};

