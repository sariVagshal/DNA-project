#ifndef __CLI_H__
#define __CLI_H__

#include "cmdParser.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
using std::cout;


class InOut
{
public:
	char ** runCmd();
	void print(std::string message);
	void errorInput();
	
private:
	void readCommand();
	char ** run();
	
	Parser m_parser;
	char ** params;
	int status;
	char str[512];
};

inline void InOut::print(std::string message)
{
	std::cout << message << std::endl;
}

inline void InOut::readCommand()
{
	cout << "\n> cmd >>> ";

	scanf("%[^\n]s",str);
	getchar();
}

inline void InOut::errorInput()
{
	std::cout << "please enter correct input." << std::endl << "type 'help' to get help" << std::endl;
}


#endif //__CLI_H__
