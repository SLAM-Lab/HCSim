
include ../../Makefile.macros

DEFINES	= -DNDEBUG -DSC_INCLUDE_DYNAMIC_PROCESSES

CFLAGS = -g -O2 -Wall $(DEFINES) -I. -I$(HCSIM)/include -I$(SYSTEMC_DIR)/include
LFLAGS = -L$(SYSTEMC_DIR)/lib-linux64 -lsystemc -L$(HCSIM)/lib -lhcsim \
	 -Wl,-rpath,$(SYSTEMC_DIR)/lib-linux64 


all: main

test: main
	-$(TIME) ./main

main: main.o  
	$(CC) $(CFLAGS) $^ -o $@ $(LFLAGS)

main.o:  
	$(CC) $(CFLAGS) -c main.cpp

clean:
	-$(RM) *.o main *~ dump*
