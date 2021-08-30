#pragma once

#include <iostream>
#include <typeinfo>

#include "Utility/Utility.h"
#include "AST/Token.h"
#include "TreeNode.h"
#include "AST/Lexer.h"



int main()
{
	//Token<int>* tok = new Token<int>(TT::INT, 5);

	LexerVal val = Lexer::Run("<myFile>","5.78 + 9.5 / (5 * 8)");

	std::cout << val;
	//std::cout << tok->repr() << std::endl;

	for (char i : " \t")
	{
		std::cout << "Bob: ";
		std::cout << i;
		std::cout << "Builder" << std::endl;
	}
}