#ifndef __DNA_APP_H__
#define __DNA_APP_H__

#include "DnaSequence.h"
#include "factory.h"
#include "../view/CLI.h"
#include "../model/data.h"

class DNA_App
{
public:
	void exe();
private:
	InOut m_io;
	Factory * m_factory; 
	Data m_data;
};

#endif //__DNA_APP_H__
