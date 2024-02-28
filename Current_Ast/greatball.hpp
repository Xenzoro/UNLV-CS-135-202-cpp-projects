//
// Created by BEN CISNEROS.
//

#ifndef greatball_hpp
#define greatball_hpp

#include "pokeball.hpp"

class Greatball : public Pokeball
{
public:
  Greatball(int);
  Greatball(const Greatball&);
  Greatball& operator=(const Item&);
  Greatball* clone() const; //Uses the copy constructor
  Greatball* create() const; //Uses the default constructor
  bool isGreatball() const;
  Greatball& asGreatball() throw(myException);
  Ultrabrall& asUltraball() throw(myException);
  Masterball& asMasterball() throw(myException);
  int compare(const Item&);
  bool equals(const Item&);
};

#endif // greatball_hpp
