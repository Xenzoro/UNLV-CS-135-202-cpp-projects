//
// Created by origi on 2/27/2024.
//
#include "pokemon.hpp"
#include "entries.hpp"
#include "myException.hpp"
#ifndef EDU_CS_POKDEX_HPP
#define EDU_CS_POKDEX_HPP



class Pokedex
{
public:
/* initializes a Pok´edex object by setting up its attributes with some
   default values: count_ should be set to 0, size_ is set to DEFAULT_SIZE, and pokedex_
   should contain a reference to a dynamic array of size_ elements. (Hint: this dynamic array
will increase in size until the last entry in the database has been read.)*/
    Pokedex();
/* performs a memberwise copy, where
  each member is copied by its own copy assignment operator.
  This operator must clean up the
 * */
    Pokedex& operator =(const Pokedex&);
    ~Pokedex();
    void add(Pokemon*, int);
    bool contains(Pokemon*,int);
    int count() const;
    void clear();
    Entries** getEntries();
    Entries** listByType(PokemonType, int&);
    Entries** listByRange(int,int) throw(myException);
    Pokemon* searchByName(std::string);
    void wakeupProfessorJimi(std::string);
    std::string toString()const;
private:
    void resize();
private:
    static const int DEFAULT_SIZE = 16;
    Entries** pokedex_; // a dynamic array of pointers to Entries that contain a list of Pokemons
    int count_; // current number of pokemon in professor jimis database
    int size_; //max size of pokedex

};

#endif //EDU_CS_POKDEX_HPP