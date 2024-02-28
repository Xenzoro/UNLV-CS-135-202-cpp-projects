//
// Created by BEN CISNEROS.
//

#ifndef move_hpp
#define move_hpp

#include <string>

class Move
{
public:
  Move();
  Move(std::string, int, int, int);
  std::string getName() const;
  int getCost() const;
  void decrementCost(int);
  int getDamage() const;
  int getAccuracy() const;
  std::string toString() const;
private:
  std::string name_;
  int cost_;
  int damage_;
  int acc_;
};

#endif // move_hpp
