# Make file for Calculate Grade program

OBJS	= main.o CalculateGradeImp.o
CC		= g++
CCFLAGS	= -Wall -Wextra -pedantic -std=c++11 -g
DEPS	= CalculateGrade.h

all: main

main: $(OBJS)
	$(CC) $(CCFLAGS) -o main $(OBJS)

main.o:	main.cpp $(DEPS)
	$(CC) $(CCFLAGS) -c main.cpp

CalculateGrade.o: CalculateGradeImp.cpp $(DEPS)
	$(CC) $(CCFLAGS) -c CalculateGradeImp.cpp

# -----
# clean by removing object files.

clean:
	rm $(OBJS)

