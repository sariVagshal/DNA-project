#ifndef __LISTCOMMAND_H__
#define __LISTCOMMAND_H__


#include <sstream> //convert string to int
#include "iCmd.h"
#include "../model/data.h"
#include "factory.h"

class List: public ICmd
{
public:
	string action(Data * data, char ** params);
private:
	static bool reg;
};


bool List::reg = Factory::registerCmd("list", new List);

inline string List::action(Data * data, char ** params)
{
	size_t i = 99;
	
	if(*params)
		std::istringstream(*params) >> i;

	return data->showData(i);
}


#endif //__LISTCOMMAND_H__
