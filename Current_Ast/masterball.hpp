//
// Created by BEN CISNEROS.
//

#ifndef masterball_hpp
#define masterball_hpp

#include "pokeball.hpp"

class Masterball : public Pokeball
{
public:
  Masterball(int);
  Masterball(const Masterball&);
  Masterball& operator=(const Item&);
  Masterball* clone() const; //Uses the copy constructor
  Masterball* create() const; //Uses the default constructor
  bool isMasterball() const;
  Greatball& asGreatball() throw(myException);
  Ultrabrall& asUltraball() throw(myException);
  Masterball& asMasterball() throw(myException);
  int compare(const Item&);
  bool equals(const Item&);
};

#endif // masterball_hpp
