#include <string>
#include "Lexer.h"


Lexer::Lexer(std::string text)
	: m_Text(text), m_Pos(-1), m_currentChar((char)0)
{
	advance();
}

void Lexer::advance()
{
	m_Pos += 1;
	m_currentChar = (m_Pos < m_Text.size()) ? m_Text[m_Pos] : (char)0;
}


std::shared_ptr<token_list> Lexer::make_tokens(Error* err)
{
	std::shared_ptr<token_list> myTokenList = std::make_shared<token_list>();
	bool is_int;
		while (m_currentChar != (char)0)
		{
			for (char i : " \t")
				if (m_currentChar == i)
					advance();
			if (exists_in(DIGITS, m_currentChar))
			{
				std::string num_str = make_number(is_int);
				if (is_int)
					myTokenList->push_back(std::make_shared<TypedToken<int>>(TypedToken<int>(TT::INT, std::stoi(num_str))));
				else
					myTokenList->push_back(std::make_shared<TypedToken<float>>(TypedToken<float>(TT::FLOAT, std::stof(num_str))));
			}
			else if (m_currentChar == '+')
			{
				myTokenList->push_back(std::make_shared<TypedToken<char>>(TypedToken<char>(TT::PLUS)));
				advance();
			}
			else if (m_currentChar == '-')
			{
				myTokenList->push_back(std::make_shared<TypedToken<char>>(TypedToken<char>(TT::MINUS)));
				advance();
			}

			else if (m_currentChar == '*')
			{
				myTokenList->push_back(std::make_shared<TypedToken<char>>(TypedToken<char>(TT::MUL)));
				advance();
			}

			else if (m_currentChar == '/')
			{
				myTokenList->push_back(std::make_shared<TypedToken<char>>(TypedToken<char>(TT::DIV)));
				advance();
			}

			else if (m_currentChar == '(')
			{
				myTokenList->push_back(std::make_shared<TypedToken<char>>(TypedToken<char>(TT::LPAREN)));
				advance();
			}

			else if (m_currentChar == ')')
			{
				myTokenList->push_back(std::make_shared<TypedToken<char>>(TypedToken<char>(TT::RPAREN)));
				advance();
			}

			else {
				char temp_char = m_currentChar;
				advance();
				Error e = IllegalCharError(temp_char);
				*err = err ? e : *err;
				std::cout << e.as_string() << std::endl;
				return myTokenList;
			}
		}

	return myTokenList;
}


std::string Lexer::make_number(bool& is_int)
{
	std::string num_str = "";
	int dot_count = 0;

	while (m_currentChar != (char)0 && exists_in(DIGITS+'.', m_currentChar))
	{
		if (m_currentChar == '.')
		{
			if (dot_count == 1) break;
			dot_count += 1;
			num_str += '.';
			advance();
		}
		else
		{
			num_str += m_currentChar;
			advance();
		}
	}

	if (dot_count == 0)
	{
		is_int = true;
		return num_str;
	}
	else
	{
		is_int = false;
		return num_str;
	}
}

LexerVal Lexer::Run(std::string& text)
{
	Lexer lexer = Lexer(text);
	LexerVal LRV;
	LRV.list = lexer.make_tokens(&LRV.error);
	return LRV;
}

LexerVal Lexer::Run(std::string&& text)
{
	Lexer lexer = Lexer(text);
	LexerVal LRV;
	LRV.list = lexer.make_tokens(&LRV.error);
	return LRV;
}


//Overloaded operators
std::ostream& operator<<(std::ostream& os, LexerVal& val)
{
	if (val.error.isInitialized())
	{
		return std::cout << val.error.as_string();
	}

	std::string printed_val = "";
	for (std::shared_ptr<Token> tk_elem : *val.list)
	{
		printed_val += tk_elem->repr() + " ";
	}

	return std::cout << printed_val;
}
