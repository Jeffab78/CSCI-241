#PROGRAM: Assign4
#Author: Jeff Byerly
#ZID: Z1860060
#DATE DUE: 3/19/19

CCFLAGS = -Wall -std=c++11

assign4: assign4.o Matrix.o
	g++ $(CCFLAGS) -o assign4 assign4.o Matrix.o

assign4.o: assign4.cpp Matrix.h 
	g++ $(CCFLAGS) -c assign4.cpp 

Matrix.o: Matrix.cpp Matrix.h
	g++ $(CCFLAGS) -c Matrix.cpp

clean:
	-rm *.o assign4
