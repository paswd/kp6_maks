#ifndef _DATA_H
#define _DATA_H

#include "comp.h"

#define STR_SIZE 30

typedef struct compstatistic_{
	int avg;
	char name_comp[STR_SIZE];
}CompStatistic;

typedef struct data_{
	CompStatistic *data_elem;
	int avail;
	int occup;
}Data;

void init(CompStatistic *comp);
Data *create();
void insert(Data *data, Computer *computer, int avg);
void print(Data *data);
void destroy(Data *data);

#endif