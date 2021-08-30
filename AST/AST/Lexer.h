#pragma once
#include <iostream>
#include <vector>
#include <memory>

#include "Token.h"
#include "Utility/Utility.h"
#include "Position.h"
#include "Error.h"

static const std::string DIGITS = "0123456789";

//template<typename T>
//struct made_token_val
//{
//	std::deque<Token<T>> tokens;
//	Error* error;
//};

typedef std::vector<std::shared_ptr<Token>> token_list;

struct LexerVal
{
	std::shared_ptr<token_list> list;
	Error error;

	friend std::ostream& operator<<(std::ostream& os, LexerVal& val);
};

class Lexer
{
public:
	Lexer(std::string& fn, std::string& text);
	Lexer(std::string&& fn, std::string&& text);

	void advance();

	std::shared_ptr<token_list> make_tokens(Error* err = nullptr);
	std::string make_number(bool& is_int);

	static LexerVal Run(std::string& fn, std::string& text);
	static LexerVal Run(std::string&& fn, std::string& text);
	static LexerVal Run(std::string&& fn, std::string&& text);

private:
	std::string m_fileName;
	std::string m_Text;
	std::shared_ptr<Position> m_Pos;
	char m_currentChar;
};

