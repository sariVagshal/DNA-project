#ifndef __FACTORY_H__
#define __FACTORY_H__

#include "iCmd.h"
#include <map> //for the hashmap
#include <string> 
using std::string;

class Factory
{
public:
	static Factory * getInstance();
	
	static bool registerCmd(std::string str, ICmd * cmd);
	static ICmd * getICmd(string);
	static std::map<string, ICmd *>& getMap();
private:
	Factory();
};


inline Factory::Factory()
{}


#endif //__FACTORY_H__

