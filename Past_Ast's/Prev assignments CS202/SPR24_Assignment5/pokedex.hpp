/*
    * Name: Jacob Martinez, NSHE_ID_500755340, 1003 ASSIGNMENT_5
    * Description:The objective of this assignment is to utilize the outlined bullet points
    * to illustrate a segment of
      the game development process, specifically focusing on crafting a
      once-popular game (which may not enjoy the same level of popularity today,
      reflecting back to the era when Professor Jimi and I were considerably younger) using C++.
      Through this assignment, you will gain familiarity with the substantial workload typically
      associated with certain applications, as well as learn to implement a selection of popular
      design patterns tailored for them. Additionally, there is an opportunity for extra credit
      by extending certain classes to introduce new Pok´emon characters and arenas. It is important
      to note that while this portion of the assignment is optional, you may only proceed with
      it once your program functions correctly. Further details about the second assignment
      for extra credit can be found on Canvas.
    * Input: numbers from input txt files/ or user input
    * Output: a visual representation of rooms
*/
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