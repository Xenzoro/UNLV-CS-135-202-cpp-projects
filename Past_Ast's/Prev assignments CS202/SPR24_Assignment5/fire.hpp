//
// Created by BEN CISNEROS.
//

#ifndef fire_hpp
#define fire_hpp

#include "species.hpp"

class Fire : public virtual Species
{
public:
  Fire();
  Fire(const Species&);
  Fire& operator=(const Species&);
  virtual bool isFire() const;
};

#endif // fire_hpp
