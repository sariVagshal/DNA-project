#include "factory.h"
#include "new.h"
#include "show.h"
#include "list.h"
#include "pairCmd.h"



Factory * Factory::getInstance()
{
	static Factory * instance = new Factory();
	return instance;
}

bool Factory::registerCmd(string str, ICmd * cmd)
{
	Factory::getMap()[str] = cmd;//.insert(std::make_pair<std::string, ICmd*>(str, cmd)); //!!!!!!!!!!!!!!!!!
	return true;
}

ICmd * Factory::getICmd(string str)
{
	return getMap()[str];
}


std::map<string, ICmd *>& Factory::getMap()
{
	static std::map<string, ICmd *> actionMap;
	return actionMap;
}


















