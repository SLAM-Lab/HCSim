
include ../../Makefile.macros

EXAMPLE_DIR = $(HCSIM_DIR)/examples/simple_taskset

DEFINES	= -DNDEBUG -DSC_INCLUDE_DYNAMIC_PROCESSES

CFLAGS = -g -O2 -Wall $(DEFINES) -I. -I$(HCSIM_DIR)/include -I$(SYSTEMC_DIR)/include
LFLAGS = -L$(SYSTEMC_DIR)/lib-linux64 -lsystemc -L$(HCSIM_DIR)/lib -lhcsim

all: main

main: main.o  
	$(CC) $(CFLAGS) $^ -o $@ $(LFLAGS)
	
main.o:  
	$(CC) $(CFLAGS) -c main.cpp


clean:
	-rm *.o main *~ dump*
