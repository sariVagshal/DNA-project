#include "dnaApp.h"
#include "../view/CLI.h"
#include <string.h>
#include <sstream> //convert string to int/!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

#include "iCmd.h"
#include "factory.h"


void DNA_App::exe()
{
	char ** exe;
	m_factory = Factory::getInstance();
	while(1)
	{
		try
		{
			exe = m_io.runCmd();
			if (exe == NULL)
				return;
			
			
			ICmd * cmd = m_factory->getICmd(std::string(exe[0]));
			if (cmd != NULL)
				m_io.print(cmd->action(&m_data, exe + 1));
			
			
			if (strcmp(exe[0],"load") == 0)
			{
				if(exe[2])
				{
					string newName = "" + std::string(exe[2]);
					newName = newName.substr(1);
					m_io.print(m_data.loadData(exe[1], newName));
				}
				else
					m_io.print(m_data.loadData(exe[1]));
			}
			
			if (strcmp(exe[0],"save") == 0)
			{
				string filterBy = "" + std::string(exe[1]);
				filterBy = filterBy.substr(1);
				
				string nameFile = "";
				if (exe[2])
					nameFile = std::string(exe[2]);
				
				if (exe[1][0] == '#')
				{
					int i;
					std::istringstream(filterBy) >> i;
					m_data.saveDataById(i, nameFile);
				}
				
				else
					if (exe[1][0] == '@')
						m_data.saveDataByName(filterBy, nameFile);
					
					else
						m_io.errorInput();
			}
			
			if (strcmp(exe[0],"len") == 0)
			{
				string filterBy = "" + std::string(exe[1]);
				filterBy = filterBy.substr(1);
				
				if (exe[1][0] == '#')
				{
					int i;
					std::istringstream(filterBy) >> i;
					m_io.print("length of sequence: " + m_data.LenOf(i));
				}
				else
					if (exe[1][0] == '@')
						m_io.print("length of sequence: " + m_data.LenOf(filterBy));
					
					else
						m_io.errorInput();
			}
		}
		catch (const char * err)
		{
			m_io.print(err);
		}
		
	}
	
}



