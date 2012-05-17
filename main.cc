#if defined(_WIN32) || defined(WIN32) || defined(__WINDOWS__) || defined(_WIN64)
#define WINDOWS
#elif defined (__linux)
#define LINUX
#include "linux.h"
#endif
#include "system.h"
#include "data.h"

#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

void usage(char * program)
{
	fprintf(stderr,"Uso: %s. Despliega los dispositivos.\n",program);
	fprintf(stderr,"\t-ayuda: despliega la ayuda\n");
}

int main(int argc, char * argv[])
{
	struct system sys; 

	if (argc > 2)
	{
		usage(argv[0]);
		exit(1);
	}
		
	
	get_memory_info(sys);
	get_os_data(sys);
	
	if (argc == 1)
	{
		print_data(sys);
	}

	else if (argc == 2 && strcmp(argv[1], "-ayuda") == 0)
	{
		usage(argv[0]);
		exit(0);
	}

	
	return 0;
}
