//
// Created by BEN CISNEROS.
//

#ifndef item_hpp
#define item_hpp

#include <string>

#include "myException.hpp"

class Pokedex;
class Pokeball;
class Medicine;

class Item
{
public:
//  virtual Item& operator=(const Item&) = 0;
  Item& operator=(const Item&);
  virtual ~Item();
  virtual Item* clone() const = 0; //Uses the copy constructor
  virtual Item* create() const = 0; //Uses the default constructor
  virtual bool isPokedex() const;
  virtual bool isPokeball() const;
  virtual bool isMedicine() const;
  virtual Pokedex& asPokedex() throw(myException) = 0;
  virtual Pokeball& asPokeball() throw(myException) = 0;
  virtual Medicine& asMedicine() throw(myException) = 0;
  virtual int compare(const Item&) = 0;
  virtual bool equals(const Item&) = 0;
  virtual std::string toString() const = 0;
};

#endif // item_hpp
