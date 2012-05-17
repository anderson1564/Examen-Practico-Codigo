#include "linux.h"
#include "conversion.h"
#include "system.h"
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <sys/utsname.h>

void get_memory_info(struct system & sys)
{
	//Definicion de constantes
	const long megabyte = 1024 * 1024;

	char buffer[1024];
	
	std::string mem_total, mem_free;

	//Apertura del archivo
	FILE * f = fopen("/proc/meminfo","r");
		
	if (f == NULL)
	{
		fprintf(stderr,"Error abriendo meminfo\n");
		exit(1);
	}

	while(fgets(buffer,1024,f) != NULL)
	{
		if (strstr(buffer,"MemTotal") != NULL)
			mem_total = buffer;
		else if (strstr(buffer,"MemFree") != NULL)
			mem_free = buffer;
	}
	

	int mem_totalI = from_str_to_int(mem_total);
	int mem_freeI = from_str_to_int(mem_free);
	double mem_totalD = (double)mem_totalI / (double)megabyte;
	double mem_freeD = (double)mem_freeI / (double)megabyte;
	double mem_use = ((double)(mem_totalI - mem_freeI) / (double)mem_totalI) * 100;
	
	sys.mem_use = "Memoria RAM:\n\tMemoria total: " + to_str(mem_totalD) + "GB.\n" + 				"\tMemoria libre: " + to_str(mem_freeD) + "GB.\n" +
			"\tPorcentaje de uso de la memoria: " + to_str(mem_use) + "%\n"; 

	fclose(f);
}

void get_os_data(struct system & sys)
{
	struct utsname uts;
	char buffer[1024];

        if(uname(&uts) < 0)
	{
		fprintf(stderr,"Error cargando datos del sistema operativo\n");
		exit(1);
	}
	

	
	/***************************************************/
	
	FILE * f = fopen("/proc/version_signature","r");

	if (f == NULL || fgets(buffer,1024,f) == NULL)
	{
		fprintf(stderr,"Error con version_signature\n");
		exit(1);
	}	
	
	fclose(f); 
	

	/*Se hacen las asignaciones*/
	sys.operating_system = "Tipo de sistema operativo:\n\t" + 
				to_str(uts.sysname) + "\n";

	sys.operating_system_version = "Version del sistema operativo:\n\t" + 
					to_str(buffer) + "\n";
}
