#include "system.h"
#include <cstdio>
#include <string>

void print_data(struct system & sys)
{
	
	fprintf(stdout,"%s",sys.proc_use.c_str());
	fprintf(stdout,"%s",sys.mem_use.c_str());
	fprintf(stdout,"%s",sys.cpu_type.c_str());
	fprintf(stdout,"%s",sys.disks_free_size.c_str());
	fprintf(stdout,"%s",sys.net_interface_ips.c_str());
	fprintf(stdout,"%s",sys.operating_system.c_str());
	fprintf(stdout,"%s",sys.operating_system_version.c_str());
	fprintf(stdout,"%s",sys.screens_resolution.c_str());
}
