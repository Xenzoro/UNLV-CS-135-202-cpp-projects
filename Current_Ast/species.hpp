//
// Created by BEN CISNEROS.
//

#ifndef species_hpp
#define species_hpp

//#include "pokemon.hpp"

class Species
{
public:
  Species(int = 10);
  Species(const Species&);
  Species& operator=(const Species&);
  int getBoost() const;
  virtual bool isFire() const;
  virtual bool isWater() const;
  virtual bool isGrass() const;
  virtual bool isElectric() const;
  virtual bool isNone() const;
private:
  int boost_;
};

#endif // species_hpp
