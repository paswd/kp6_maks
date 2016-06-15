#include <stdio.h>
#include <stdlib.h>

#include "comp.h"
#include "io.h"

int main(int argc, char *argv[])
{
	if (argc != 3) {
		fprintf(stdin, "Usage:\n\t./generate FILE_FROM FILE_TO\n");
		exit(0);
	}

	FILE *in = fopen(argv[1], "r");
	FILE *out = fopen(argv[2], "w");
	if (!in || !out) {
		fprintf(stderr, "ERROR: can't open file\n");
		exit(1);
	}
	Computer comp;
	memset(&comp, 0, sizeof(comp));
	while (comp_read_txt(&comp, in)) {
		comp_write_bin(&comp, out);
	}
	fclose(in);
	fclose(out);
	return 0;
}