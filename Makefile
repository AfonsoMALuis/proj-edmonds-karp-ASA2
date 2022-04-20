# Makefile, versao 1
# Analise e Sintese de Algoritmos

CC   = g++
LD   = g++
CFLAGS =-std=c++11 -O3 -Wall
LDFLAGS=-lm

# A phony target is one that is not really the name of a file
# https://www.gnu.org/software/make/manual/html_node/Phony-Targets.html
.PHONY: all clean run

all: main average getV+E

main: main.o
	$(LD) $(CFLAGS) $(LDFLAGS) -o main main.o

average: average.o
	$(CC) $(CFLAGS) $(LDFLAGS) -o average average.o

getV+E: getV+E.o
	$(CC) $(CFLAGS) $(LDFLAGS) -o getV+E getV+E.o

#fs/state.o: fs/state.c fs/state.h tecnicofs-api-constants.h
#	$(CC) $(CFLAGS) -o fs/state.o -c fs/state.c

#fs/operations.o: fs/operations.c fs/operations.h fs/state.h tecnicofs-api-constants.h
#	$(CC) $(CFLAGS) -o fs/operations.o -c fs/operations.c

main.o: main.cpp
	$(CC) $(CFLAGS) -o main.o -c main.cpp

average.o: average.cpp
	$(CC) $(CFLAGS) -o average.o -c average.cpp

getV+E.o: getV+E.cpp
	$(CC) $(CFLAGS) -o getV+E.o -c getV+E.cpp

clean:
	@echo Cleaning...
	rm -f *.o *.txt *.out main average getV+E

run: main
	./main
