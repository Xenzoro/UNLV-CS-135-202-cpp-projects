//
// Created by BEN CISNEROS.
//

#ifndef pokeball_hpp
#define pokeball_hpp

#include "pokemon.hpp"
#include "item.hpp"

class Greatball;
class Ultrabrall;
class Masterball;

class Pokeball : public Item
{
public:
  Pokeball(int);
  Pokeball(const Pokeball&);
  Pokeball& operator=(const Item&);
  virtual ~Pokeball();
  void decrementEnergy(int);
  int getEnergy() const;
  void catchPokemon(Pokemon*);
  Pokemon* goPokemon();
  bool isPokeball() const;
  Pokedex& asPokedex() throw(myException);
  Medicine& asMedicine() throw(myException);
  Pokeball& asPokeball() throw(myException);
  virtual bool isGreatball() const;
  virtual bool isUltraball() const;
  virtual bool isMasterball() const;
  virtual Greatball& asGreatball() = 0;
  virtual Ultrabrall& asUltraball() = 0;
  virtual Masterball& asMasterball() = 0;
  std::string toString() const;
protected:
  Pokemon* pokemon_;
  int energy_;
};

#endif // pokeball_hpp
