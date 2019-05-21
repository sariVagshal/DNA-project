#ifndef __ICMD_H__
#define __ICMD_H__

#include <string>
#include "../model/data.h"


class ICmd
{
public:
	virtual ~ICmd();
	
	virtual std::string action(Data * data, char ** params) = 0;
};


inline ICmd::~ICmd()
{}

#endif //__CMD_H__
