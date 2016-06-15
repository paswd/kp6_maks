#ifndef _COMP_H_
#define _COMP_H_
#include <stdint.h>

#define STR_SIZE 30


typedef struct {
	char name_cpu[STR_SIZE];
	int freq;
} CPU;

typedef struct {
	char name_va[STR_SIZE];
	int memory;
} GPU;

typedef struct {
	char name_comp[STR_SIZE];
	char name_os[STR_SIZE];
	int ram;
	CPU cpu;
	int hdd_cap;
	GPU gpu;
} Computer;

void computer_init(Computer *computer);
#endif