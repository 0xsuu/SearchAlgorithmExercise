
CC=g++

EXECNAME    = search

NODE        = Node.o
FRINGE      = Fringe.o
STATE       = State.o
SEARCHTREE  = SearchTree.o
MAIN        = main.o

all:    search
		@echo "Build finished"

search: $(NODE) $(FRINGE) $(STATE) $(SEARCHTREE) $(MAIN)
	$(CC) -o $(EXECNAME) $(NODE) $(FRINGE) $(STATE) $(SEARCHTREE) $(MAIN)

Node:   $(NODE)
	$(CC) -c Node.cpp

Fringe:   $(FRINGE)
	$(CC) -c Fringe.cpp

State:   $(STATE)
	$(CC) -c State.cpp

SearchTree:   $(NODE)
	$(CC) -c SearchTree.cpp

main:   $(MAIN)
	$(CC) -c main.cpp

clean:
	rm -f *.o
	rm -f $(EXECNAME)
