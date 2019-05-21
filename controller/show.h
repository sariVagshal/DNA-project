#ifndef __SHOWCOMMAND_H__
#define __SHOWCOMMAND_H__

#include <sstream> //convert string to int
#include "iCmd.h"
#include "../model/data.h"
#include "factory.h"

class Show: public ICmd
{
public:
	std::string action(Data * data, char ** params);
private:
	static bool reg;
};


bool Show::reg = Factory::registerCmd("show", new Show);

inline std::string Show::action(Data * data, char ** params)
{	
	string filterBy = "" + std::string(params[0]);
	filterBy = filterBy.substr(1);
	
	if (params[0][0] == '#')
	{
		int i;
		std::istringstream(filterBy) >> i;
		return data->getById(i);
	}
	
	else
		if (params[0][0] == '@')
			return data->getByName(filterBy);
		
		else
			return "errorHandling";
		
	return "";
}


#endif //__SHOWCOMMAND_H__
