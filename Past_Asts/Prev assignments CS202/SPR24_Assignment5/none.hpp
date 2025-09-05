//
// Created by BEN CISNEROS.
//

#ifndef none_hpp
#define none_hpp

#include "species.hpp"

class None : public virtual Species
{
public:
  None();
  None(const Species&);
  None& operator=(const Species&);
  virtual bool isNone() const;
};

#endif // none_hpp
