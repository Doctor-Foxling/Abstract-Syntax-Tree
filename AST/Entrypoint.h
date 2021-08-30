#pragma once

#include <iostream>
#include <typeinfo>

#include "Utility.h"
#include "Token.h"
#include "TreeNode.h"
#include "Lexer.h"



int main()
{
	//Token<int>* tok = new Token<int>(TT::INT, 5);

	Lexer* lexer = new Lexer("(3.45 + 4 / 5.67)");

	std::shared_ptr<token_list> tk_list = lexer->make_tokens();

	for (auto elem_tk : *tk_list)
	{
		std::cout << "Before: ";
		std::cout << elem_tk->repr() << std::endl;
	}
	//std::cout << tok->repr() << std::endl;

	for (char i : " \t")
	{
		std::cout << "Bob: ";
		std::cout << i;
		std::cout << "Builder" << std::endl;
	}
}