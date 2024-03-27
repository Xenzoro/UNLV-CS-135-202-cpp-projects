//
// Created by BEN CISNEROS.
//

#ifndef pokebag_hpp
#define pokebag_hpp

#include "item.hpp"

class Pokebag
{
public:
  Pokebag();
  Pokebag(const Pokebag&);
  Pokebag& operator=(const Pokebag&);
  ~Pokebag();
  bool add(Item*) throw(myException);
  bool add(Item*, int) throw(myException);
  Item* at(int) throw(myException);
  bool remove(int);
  int find(const Item&);
  int count() const;
private:
  static const int DEFAULT_SIZE = 7;
  Item** items_;
  int count_;
};

#endif // pokebag_hpp
