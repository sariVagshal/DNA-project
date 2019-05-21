#ifndef __PAIRCMD_H__
#define __PAIRCMD_H__

#include "iCmd.h"
#include "../model/data.h"
#include "factory.h"
#include <sstream> //convert string to int
#include "pair.h"
#include <string.h>

class PairCmd: public ICmd
{
public:
	string action(Data * data, char ** params);
private:
	static bool reg;
};


bool PairCmd::reg = Factory::registerCmd("pair", new PairCmd);

inline string PairCmd::action(Data * data, char ** params)
{
	string filterBy = "" + std::string(params[0]);
	filterBy = filterBy.substr(1);
	
	SharedPtr<MetaData> mt;
	
	if (params[0][0] == '#')
	{
		int i;
		std::istringstream(filterBy) >> i;
		mt = data->getDataById(i);
	}
	
	else
		if (params[0][0] == '@')
			mt = data->getDataByName(filterBy);
		else
			return "errorHandling";
			
	std::string newName = std::string(params[2]); // _ : _
	if (strcmp(params[2],"@@") == 0)
	{
		newName = mt->m_name;
		newName += std::string("_p");
	}
	
	Pair p(mt->m_seq);
	string str = "";
	for (size_t i = 0; i < mt->m_seq->getLen(); ++i)
		str += (*mt->m_seq)[i];
	return str;
	
	
	return "errorHandling";
}






#endif //__PAIRCMD_H__
