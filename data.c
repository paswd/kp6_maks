#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "data.h"
#include "comp.h"

#define DATA_INTIAL_SIZE 200

#define STR_SIZE 30

void init(CompStatistic *comp)
{
	comp = (CompStatistic *) malloc(sizeof(CompStatistic));
	comp->avg = 0;
	comp->name_comp[0] = '\0';
}


Data *create()
{
	Data *data = (Data *) malloc(sizeof(Data));
	if (data == NULL)
		return NULL;
	data->avail = DATA_INTIAL_SIZE;
	data->occup = 0;
	data->data_elem = (CompStatistic *) malloc(sizeof(CompStatistic) * data->avail);
	return data;
}

void insert(Data *data, Computer *computer, int avg)
{
	if (data->avail == data->occup) {
		data->avail *= 2;
		data->data_elem = (CompStatistic *) realloc(data->data_elem, sizeof(CompStatistic) * data->avail);
	}
	++data->occup;
	data->data_elem[data->occup - 1].avg = avg;
	strcpy(data->data_elem[data->occup - 1].name_comp, computer->name_comp);
}

void print(Data *data)
{
	for (int i = 0; i < data->occup; i++) {
		printf("%s  ", data->data_elem[i].name_comp);
		printf("--  %d\n", data->data_elem[i].avg);
		printf("\n");
	}
}

void destroy(Data *data)
{
	free(data->data_elem);
	free(data);
}