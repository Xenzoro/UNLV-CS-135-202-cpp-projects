#include <string>
#include "attackMove.h"

#ifndef POKEMON_H
#define POKEMON_H

class pokemon
{
public:
    //set values to 0 from the creation
    // single : is in heritance while :: is member access op
    pokemon() : hp(0), defense(0), amtMoves(0) {}
    pokemon(int h, int d) : hp(h), defense(d), amtMoves(0) {}
    // adds an attackmove OBJECT into the moves array and increments
    // the amtMoves counter
    bool addMove(attackMove);
    //subtracts amt from the hp field, if neg set =0
    void decrementHp(int);
    void moveUsed(int);
    bool moveUseable(int);

    int getHp() const;
    int getDefense() const;
    void displayHUD() const;
    attackMove getMove(int) const;
private:
    static const int MAX_MOVES = 4;
    int hp;
    int defense; //amt reduces dmg taken when hurt
    int amtMoves; //amt of moves
    attackMove moves[MAX_MOVES]; //array of attks
};

#endif