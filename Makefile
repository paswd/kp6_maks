GENERATE = generate
PRINT = print
EXECUTE = execute
LIBRARY = library
CC = gcc
CFLAGS = -g -std=c99 -Wall -Werror -Wextra -pedantic -w -pipe -O3 
VGLAGS = --track-origins=yes  --leak-check=full -v
 
all: generate.c print.c execute.c interface io.c clean
	$(CC) $(CFLAGS) generate.c -L. -l$(LIBRARY) -Wl,-rpath,. -o $(GENERATE)
	$(CC) $(CFLAGS) print.c -L. -l$(LIBRARY) -Wl,-rpath,. -o $(PRINT)
	$(CC) $(CFLAGS) execute.c -L. -l$(LIBRARY) -Wl,-rpath,. -o $(EXECUTE)

interface: comp.h io.c io.h data.h data.c 
	$(CC) $(CFLAGS) -c -fPIC data.c
	$(CC) $(CFLAGS) -c -fPIC io.c
	$(CC) $(CFLAGS) -shared -o lib$(LIBRARY).so -Wl,-soname,lib$(LIBRARY).so data.o io.o 


vgenerate: generate
	valgrind $(VFLAGS) ./generate Base_file.txt base_bin

vprint: print
	valgrind $(VFLAGS) ./print base_bin

vexecute: execute
	valgrind $(VFLAGS) ./execute base_bin

clean:
	rm -f *.o
