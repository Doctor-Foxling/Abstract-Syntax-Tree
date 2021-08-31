#pragma once

#include <iostream>
#include <typeinfo>

#include "Utility/Utility.h"
#include "AST/Token.h"
#include "TreeNode.h"
#include "AST/Lexer.h"



int main()
{
	std::string some_text = "(1 + 2 + 3) I must've called you thousand times";

	LexerVal val = Lexer::Run("<myFile>",some_text);

	std::cout << val << std::endl;
}