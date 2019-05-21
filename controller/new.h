#ifndef __NEW_H__
#define __NEW_H__

#include "iCmd.h"
#include "../model/data.h"//!!!!!!!!!!!!!!!!!
#include "factory.h"

class NewSeq: public ICmd
{
public:
	std::string action(Data * data, char ** params);
private:
	static bool reg;
};


bool NewSeq::reg = Factory::registerCmd("new", new NewSeq);


inline std::string NewSeq::action(Data * data, char ** params)
{
	string message = "";
	
	if (params[1])
	{
		if (params[1][0] != '@')
		{
			return "please enter correct input.\ntype 'help' to get help";
		}
		
		string newName = "" + std::string(params[1]);
		newName = newName.substr(1);
		message = data->insertNewDna(params[0], newName);
	}
	else
		message = data->insertNewDna(params[0]);
		
	return message;
}


#endif //__NEW_H__
