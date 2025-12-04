CC = gcc
FLAGS = -Wall

LATEXFLAG = 0
VALGRIND = 1

ifeq ($(LATEXFLAG), 1)
	FLAGS += -DLATEX_OUT
endif

ifeq ($(VALGRIND), 1)
	FLAGS += -g
endif

pqSieve: pqSieve.c pqSieve.h eratosthenes.o
	$(CC) $(FLAGS) eratosthenes.o $@.c -o pqSieve -lm

pkSieve: pkSieve.c pkSieve.h eratosthenes.o
	$(CC) $(FLAGS) eratosthenes.o $@.c -o pkSieve -lm

nSieve: nSieve.c nSieve.h extendedEratosthenes.o eratosthenes.o
	$(CC) $(FLAGS) eratosthenes.o extendedEratosthenes.o $@.c -o nSieve -lm

eratosthenes.o: eratosthenes.c eratosthenes.h
	$(CC) $(FLAGS) -c eratosthenes.c

extendedEratosthenes.o: extendedEratosthenes.c eratosthenes.h
	$(CC) $(FLAGS) -c extendedEratosthenes.c
	



.PHONY clean:
	rm -f $(OBFILES)
