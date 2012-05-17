#ifndef _SYSTEM_H_
#define _SYSTEM_H_

#include <string>


struct system{
		int 	screens;
		int 	disks;
		int 	net_interface_number;
	std::string 	proc_use;
	std::string 	mem_use;
	std::string 	cpu_type;
	std::string 	disks_free_size;
	std::string 	net_interface_ips;
	std::string 	operating_system;
	std::string 	operating_system_version;
	std::string 	screens_resolution;
};

#endif
