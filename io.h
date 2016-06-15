#ifndef _IO_H_
#define _IO_H_
#include <stdio.h>
#include "comp.h"

void comp_print(Computer *computer);
int comp_read_txt(Computer *comp, FILE *in);
int comp_read_bin(Computer *comp, FILE *in);
void comp_write_txt(Computer *comp, FILE *out);
void comp_write_bin(Computer *comp, FILE *out);

#endif