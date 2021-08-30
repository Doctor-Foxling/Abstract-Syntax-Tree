#pragma once

#include <string>

class Position
{
public:
	Position(int index, int ln, int col, std::string& file_name, std::string& ftxt);
	Position(int index, int ln, int col, std::string&& file_name, std::string&& ftxt);

	~Position() {}

	Position& advance(char current_char);

	int getIndex() {return m_index; }
	int getLine() { return m_ln; }
	int getCol() {  return m_col; }
	const std::string& getFileName() const { return m_fileName; }
	const std::string& getFileText() const { return m_fileText; }
private:
	int m_index;
	int m_ln;
	int m_col;
	std::string m_fileName;
	std::string m_fileText;
};