# Make file for twenty-six game program.

OBJS	= main.o CUserImp.o  COrderImp.o CFirmImp.o CFileImp.o
CC		= g++
CCFLAGS	= -Wall -Wextra -pedantic -std=c++11 -g
DEPS	= CUser.h COrder.h CFirm.h CFile.h

all: main

main: $(OBJS)
	$(CC) $(CCFLAGS) -o main $(OBJS)

main.o:	main.cpp $(DEPS)
	$(CC) $(CCFLAGS) -c main.cpp

CUserImp.o: CUserImp.cpp $(DEPS)
	$(CC) $(CCFLAGS) -c CUserImp.cpp

COrderImp.o: COrderImp.cpp $(DEPS)
	$(CC) $(CCFLAGS) -c COrderImp.cpp

CFirmImp.o: CFirmImp.cpp $(DEPS)
	$(CC) $(CCFLAGS) -c CFirmImp.cpp
	
CFileImp.o: CFileImp.cpp $(DEPS)
	$(CC) $(CCFLAGS) -c CFileImp.cpp

# -----
# clean by removing object files.

clean:
	rm $(OBJS)

