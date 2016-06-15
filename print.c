#include <stdio.h>
#include <stdlib.h>
#include "comp.h"
#include "io.h"

int main(int argc, char *argv[]) 
{
	FILE *in = fopen(argv[1], "r");
	if (argc != 2) {
		fprintf(stdin, "Usage:\n\t./print BASE_FILE\n");
		exit(0);
	}
	if (!in) {
		fprintf(stderr, "ERROR: can't open file.\n");
		exit(1);
	}
	Computer comp;
	memset(&comp, 0, sizeof(comp));
	while (comp_read_bin(&comp, in)) {
		comp_write_bin(&comp, stdout);
	}
	fclose(in);

	return 0;
}