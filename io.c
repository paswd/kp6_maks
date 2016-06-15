#include <stdlib.h>

#include "comp.h"
#include "io.h"

void comp_print(Computer *computer) 
{
	printf("%s\n", computer->name_comp);
	printf("--%s\n", computer->name_os);
	printf("--%d\n", computer->ram);
	printf("--%s\n", computer->cpu.name_cpu);
	printf("--%d\n", computer->cpu.freq);
	printf("--%d\n", computer->hdd_cap);
	printf("--%s\n", computer->gpu.name_va);
	printf("--%d\n", computer->gpu.memory);
	printf("\n");
}

int comp_read_txt(Computer *comp, FILE *in) 
{
	fscanf(in, "%s", comp->name_comp);
	fscanf(in, "%s", comp->name_os);
	fscanf(in, "%d", &comp->ram);
	fscanf(in, "%s", comp->cpu.name_cpu);
	fscanf(in, "%d", &comp->cpu.freq);
	fscanf(in, "%d", &comp->hdd_cap);
	fscanf(in, "%s", comp->gpu.name_va);
	fscanf(in, "%d", &comp->gpu.memory);
	return !feof(in);
}

int comp_read_bin(Computer *comp, FILE *in)
{
	fread(comp->name_comp, sizeof(char), STR_SIZE, in);
	fread(comp->name_os, sizeof(char), STR_SIZE, in);
	fread(&comp->ram, sizeof(uint32_t), 1, in);
	fread(comp->cpu.name_cpu, sizeof(char), STR_SIZE, in);
	fread(&comp->cpu.freq, sizeof(uint32_t), 1, in);
	fread(&comp->hdd_cap, sizeof(uint32_t), 1, in);
	fread(comp->gpu.name_va, sizeof(char), STR_SIZE, in);
	fread(&comp->gpu.memory, sizeof(uint32_t), 1, in);
	return !feof(in);
}



void comp_write_bin(Computer *comp, FILE *out)
{
	uint32_t tmp = 0;
	fwrite(comp->name_comp, sizeof(char), STR_SIZE, out);
	fwrite(comp->name_os, sizeof(char), STR_SIZE, out);
	tmp = (uint32_t) comp->ram;
	fwrite(&tmp, sizeof(tmp), 1, out);
	fwrite(comp->cpu.name_cpu, sizeof(char), STR_SIZE, out);
	tmp = (uint32_t) comp->cpu.freq;
	fwrite(&tmp, sizeof(tmp), 1, out);
	tmp = (uint32_t) comp->hdd_cap;
	fwrite(&tmp, sizeof(tmp), 1, out);
	fwrite(comp->gpu.name_va, sizeof(char), STR_SIZE, out);
	tmp = (uint32_t) comp->gpu.memory;
	fwrite(&tmp, sizeof(tmp), 1, out);
}