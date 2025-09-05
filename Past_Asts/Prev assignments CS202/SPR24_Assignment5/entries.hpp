//
// Created by BEN CISNEROS.
//

#ifndef entries_hpp
#define entries_hpp

#include <string>

#include "pokemon.hpp"

class Entries
{
public:
  Entries();
  Entries(const Entries&);
  Entries& operator=(const Entries&);
  ~Entries();
  Pokemon* getList();
  int count() const;
  void add(const Pokemon&);
  bool find(const Pokemon&);
  Pokemon* find(std::string name);
  std::string toString() const;
private:
  static const int MAX_SIZE = 4;
  Pokemon* list_;
  int count_;
};

#endif // entries_hpp
