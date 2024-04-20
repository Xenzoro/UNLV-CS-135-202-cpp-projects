# Make file for pointers assignment

OBJS	= main.o cake.o pacmaze.o
CC		= g++
CCFLAGS	= -Wall -Wextra -pedantic -std=c++11 -g

all: recursion 

recursion: $(OBJS)
	@echo "Compiling recursion program"
	$(CC) $(CCFLAGS) -o recursion $(OBJS)
	@echo "Done! Run with ./recursion"
	
main.o:
	@echo "Compiling main.cpp"
	$(CC) $(CCFLAGS) -c main.cpp

cake.o:
	@echo "Compiling cake.cpp"
	$(CC) $(CCFLAGS) -c cake.cpp
	
pacmaze.o:
	@echo "Compiling pacmaze.cpp"
	$(CC) $(CCFLAGS) -c pacmaze.cpp

# -----
# clean by removing object files.

clean:
	rm $(OBJS)
	rm recursion
