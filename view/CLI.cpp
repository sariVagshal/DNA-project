#include "CLI.h"
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

char ** InOut::runCmd()
{
	char ** exe;
	
	exe = run();
	return exe;
}

char ** InOut::run()
{
	params = new char*[64];
	readCommand();
	m_parser.parserCommand(str, params);
	
	if (strcmp(params[0],"exit") == 0)
	{
		execvp(params[0], params);
		delete [] params;
		return NULL;
	}
	return params;
}

