#include "cmdParser.h"

#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>


void Parser::parserCommand(char* str, char * params[])
{
	int i=0;
	params[i] = strtok(str, " ");
	while( params[i] != NULL )
	{
		i++;
		params[i] = strtok(NULL, " ");
	}
	params[++i] = NULL;
}




