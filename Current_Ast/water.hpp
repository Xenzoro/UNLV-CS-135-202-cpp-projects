//
// Created by BEN CISNEROS.
//

#ifndef water_hpp
#define water_hpp

#include "species.hpp"

class Water : public virtual Species
{
public:
  Water();
  Water(const Species&);
  Water& operator=(const Species&);
  virtual bool isWater() const;
};

#endif // water_hpp
