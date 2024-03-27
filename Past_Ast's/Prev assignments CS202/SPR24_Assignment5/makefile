CCFLAGS	= -Wall -Wextra -pedantic -std=c++11 -g

all: main

main: main1 main2

main1: main1.o pokedex.o myException.o move.o item.o pokemon.o entries.o
	g++ $(CCFLAGS) -o main1 main1.o pokedex.o myException.o move.o item.o pokemon.o entries.o

main1.o: main1.cpp
	g++ $(CCFLAGS) -c main1.cpp -o main1.o

main2: main2.o pokedex.o myException.o move.o item.o pokemon.o entries.o pokebag.o medicine.o
	g++ $(CCFLAGS) -o main2 main2.o pokedex.o myException.o move.o item.o pokemon.o entries.o pokebag.o medicine.o

main2.o: main2.cpp
	g++ $(CCFLAGS) -c main2.cpp -o main2.o

main3: main3.o pokedex.o myException.o move.o item.o pokemon.o entries.o pokebag.o medicine.o pokeball.o ultraball.o greatball.o masterball.o
	g++ $(CCFLAGS) -o main3 main3.o pokedex.o myException.o move.o item.o pokemon.o entries.o pokebag.o medicine.o pokeball.o ultraball.o greatball.o masterball.o

main3.o: main3.cpp
	g++ $(CCFLAGS) -c main3.cpp -o main3.o

main4: main4.o pokedex.o myException.o move.o item.o pokemon.o entries.o pokebag.o medicine.o pokeball.o ultraball.o greatball.o masterball.o fire.o water.o grass.o electric.o none.o species.o
	g++ $(CCFLAGS) -o main4 main4.o pokedex.o myException.o move.o item.o pokemon.o entries.o pokebag.o medicine.o pokeball.o ultraball.o greatball.o masterball.o fire.o water.o grass.o electric.o none.o species.o

main4.o: main4.cpp
	g++ $(CCFLAGS) -c main4.cpp -o main4.o

# -----
# compiled class files

entries.o: entries.cpp
	g++ $(CCFLAGS) -c entries.cpp -o entries.o

pokemon.o: pokemon.cpp
	g++ $(CCFLAGS) -c pokemon.cpp -o pokemon.o

pokedex.o: pokedex.cpp
	g++ $(CCFLAGS) -c pokedex.cpp -o pokedex.o

move.o: move.cpp
	g++ $(CCFLAGS) -c move.cpp -o move.o

item.o: item.cpp
	g++ $(CCFLAGS) -c item.cpp -o item.o

medicine.o: medicine.cpp
	g++ $(CCFLAGS) -c medicine.cpp -o medicine.o

myException.o: myException.cpp
	g++ $(CCFLAGS) -c myException.cpp -o myException.o

pokeball.o: pokeball.cpp
	g++ $(CCFLAGS) -c pokeball.cpp -o pokeball.o

greatball.o: greatball.cpp
	g++ $(CCFLAGS) -c greatball.cpp -o greatball.o

ultraball.o: ultraball.cpp
	g++ $(CCFLAGS) -c ultraball.cpp -o ultraball.o

masterball.o: masterball.cpp
	g++ $(CCFLAGS) -c masterball.cpp -o masterball.o

species.o: species.cpp
	g++ $(CCFLAGS) -c species.cpp -o species.o

fire.o: fire.cpp
	g++ $(CCFLAGS) -c fire.cpp -o fire.o

water.o: water.cpp
	g++ $(CCFLAGS) -c water.cpp -o water.o

electric.o: electric.cpp
	g++ $(CCFLAGS) -c electric.cpp -o electric.o

grass.o: grass.cpp
	g++ $(CCFLAGS) -c grass.cpp -o grass.o

none.o: none.cpp
	g++ $(CCFLAGS) -c none.cpp -o none.o

pokebag.o: pokebag.cpp
	g++ $(CCFLAGS) -c pokebag.cpp -o pokebag.o

# -----
# clean by removing object files.

clean:
	rm *.o
	rm main1
	rm main2
	rm main3