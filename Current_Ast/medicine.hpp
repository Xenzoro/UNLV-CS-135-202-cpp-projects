//
// Created by BEN CISNEROS.
//

#ifndef medicine_hpp
#define medicine_hpp

#include "pokemon.hpp"
#include "item.hpp"

class Medicine : public Item
{
public:
  Medicine(int = 100);
  Medicine(Pokemon*, int = 100);
  Medicine(const Medicine&);
  Medicine& operator=(const Item&);
  ~Medicine();
  Medicine* clone() const; //Uses the copy constructor
  Medicine* create() const; //Uses the default constructor
  bool isMedicine() const;
  Pokedex& asPokedex() throw(myException);
  Pokeball& asPokeball() throw(myException);
  Medicine& asMedicine() throw(myException);
  void setPokemon(Pokemon*);
  Pokemon* getPokemon();
  int compare(const Item&);
  bool equals(const Item&);
  std::string toString() const;
public:
  Pokemon* pokemon_;
  int quantity_;
};

#endif // medicine_hpp
