#include "Position.h"

Position::Position(int index, int ln, int col, std::string& file_name, std::string& ftxt)
	: m_index(index), m_ln(ln), m_col(col), m_fileName(file_name), m_fileText(ftxt)
{
}

Position::Position(int index, int ln, int col, std::string&& file_name, std::string&& ftxt)
	: m_index(index), m_ln(ln), m_col(col), m_fileName(file_name), m_fileText(ftxt)
{
}

Position& Position::advance(char current_char)
{
	m_index += 1;
	m_col += 1;

	if (current_char == '\n')
	{
		m_ln += 1;
		m_col = 0;
	}

	return *this;
}
