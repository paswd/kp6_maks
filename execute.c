#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"
#include "comp.h"
#include "io.h"



int computer_score(Computer *comp)
{
	int total_hdd_capacity = 0;
	return (comp->ram + comp->cpu.freq + comp->hdd_cap / 1000  + comp->gpu.memory) / 4; 
}

int compare(const void *val1, const void *val2) 
{
	int y1 = ((CompStatistic *)val1)->avg;
	int y2 = ((CompStatistic *)val2)->avg;

	if (y1 == y2) {
		return 0;
	} else if (y1 > y2) {
		return 1;
	} else return -1;
}

int main(int argc, char *argv[])
{
	if (argc != 3) {
		fprintf(stdin, "Usage:\n\t./execute BASE_NAME_FILE MINIMUM_SCORE\n");
		exit(0);
	}
	FILE *in = fopen(argv[1], "r");
	if (!in) {
		fprintf(stderr, "ERROR: can't open file\n");
		exit(1);
	}
	int score_mark = atoi(argv[2]);
	int avg = 0;
	int bad_comps = 0;
	Data *data = create();
	Computer computer;
	memset(&computer, 0, sizeof(computer));
	while (comp_read_bin(&computer, in)) {
		
		avg = computer_score(&computer);
		if (avg < score_mark) {
			insert(data, &computer, avg);
		}
	}	
	fclose(in);
	qsort(data->data_elem, data->occup, sizeof(CompStatistic), compare);
	print(data);
	destroy(data);
	return 0;
}