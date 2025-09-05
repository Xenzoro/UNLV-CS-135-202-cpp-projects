//
// Created by BEN CISNEROS.
//

#ifndef ultraball_hpp
#define ultraball_hpp

#include "pokeball.hpp"

class Ultrabrall : public Pokeball
{
public:
  Ultrabrall(int);
  Ultrabrall(const Ultrabrall&);
  Ultrabrall& operator=(const Item&);
  Ultrabrall* clone() const; //Uses the copy constructor
  Ultrabrall* create() const; //Uses the default constructor
  bool isUltraball() const;
  Greatball& asGreatball() throw(myException);
  Ultrabrall& asUltraball() throw(myException);
  Masterball& asMasterball() throw(myException);
  int compare(const Item&);
  bool equals(const Item&);
};

#endif // ultraball_hpp
