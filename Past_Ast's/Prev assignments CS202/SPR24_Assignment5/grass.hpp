//
// Created by BEN CISNEROS.
//

#ifndef grass_hpp
#define grass_hpp

#include "species.hpp"

class Grass : public virtual Species
{
public:
  Grass();
  Grass(const Species&);
  Grass& operator=(const Species&);
  virtual bool isGrass() const;
};

#endif // grass_hpp
