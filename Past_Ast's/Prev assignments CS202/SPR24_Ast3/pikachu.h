/*
    * Name: Jacob Martinez, NSHE_ID_500755340, 1003 ASSIGNMENT_3
    * Description:  test
    * Input:  test
    * Output:  test
*/
#include "pokemon.h"
#include "rnd.h"
#include "attackMove.h"
#include <string>

#ifndef PIKACHU_H
#define PIKACHU_H

class pikachu : pokemon
{
public:
    //default constructor that initializes values to the instance
    //vars
    pikachu() : pokemon(), random(0) {}

    //parameterized constructor that sets all the instance variables
    // with the parameterized values..
    pikachu(int hp, int defense, int seed) :
        pokemon(hp, defense), random(seed) {}

    bool addMove(attackMove);
    void decrementHp(int);
    char attackPikachu(pikachu&, int);

    int getDefense() const;
    int getHp() const;
    void displayHUD() const;
private:
    // random number generator that is used to determine if an attack
    // lands on the opponent
    // random is an object of rnd
    rnd random;
};

#endif