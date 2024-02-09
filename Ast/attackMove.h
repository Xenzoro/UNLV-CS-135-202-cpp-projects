#ifndef ATTACK_MOVE_H
#define ATTACK_MOVE_H
#include <string>
//maintains attributes for each of pikachu's moves
class attackMove
{
public:
    std::string name; //name of attack
    int amount; // amt of this particular attack
    int power; // strength of attk
    int acc; //acc of attk
};
#endif