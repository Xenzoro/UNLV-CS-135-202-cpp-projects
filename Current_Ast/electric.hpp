//
// Created by BEN CISNEROS.
//

#ifndef electric_hpp
#define electric_hpp

#include "species.hpp"

class Electric : public virtual Species
{
public:
  Electric();
  Electric(const Species&);
  Electric& operator=(const Species&);
  virtual bool isElectric() const;
};

#endif // electric_hpp
