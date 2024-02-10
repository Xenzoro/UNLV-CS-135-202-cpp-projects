#include "pokemon.h"
#include <iostream>
#include <iomanip>
#include <iomanip>
using namespace std;

//default constructor that initializes values to the instance
bool pokemon::addMove(attackMove m)
{
    for(int i = 0; i < MAX_MOVES; i++){
    if( moves[i].name.empty()){
        moves[i].name = m.name;
        moves[i].amount = m.amount;
        moves[i].power = m.power;
        moves[i].acc = m.acc;
        amtMoves++;
        return true;
        }
    }
    return false;
}
//subtracts amt from the hp field, if neg set =0
void pokemon::decrementHp(int amount)
{
    hp = getHp() - amount;
    if(hp < 0){
        hp = 0;
    }
}
//decrements the amount of moves from player X
void pokemon::moveUsed(int moveIndex)
{
    moves[moveIndex].amount--; // instead of using -1?
    if(moves[moveIndex].amount < 0){
        moves[moveIndex].amount = 0;
    }
}
//checks if the move is usable
bool pokemon::moveUseable(int moveIndex)
{
    if(moves[moveIndex].amount > 0){
        return true;
    }

    return false;
}
//getter for hp
int pokemon::getHp() const
{
    return hp;
}
//getter for defense
int pokemon::getDefense() const
{
    return defense;
}
//getter for the move
attackMove pokemon::getMove(int moveIndex) const
{
    return moves[moveIndex];
}
//displays the HUD
void pokemon::displayHUD() const{
// 13 spc
// setw() is the "width" of the phrase,string etc after it...
// ie. setw(5) << "i"... 5 bc it includes the "I" as well...
    cout << left
         << setw(5)  << "i" // includes the "i"
         << setw(17) << "Name" // includes "Name"
         << setw(5)  << "Amt" // includes "Amt"
         << setw(5)  << "Pwr" // includes "Pwr"
         << "Acc" << endl
         << "-----------------------------------" << endl;
        for(int i = 0; i < MAX_MOVES; i++){
    cout << left
         << setw(5)  << i + 1
         << setw(17) << this->getMove(i).name
         << right
         << setw(3)  << this->getMove(i).amount
         << setw(5)  << this->getMove(i).power
         << setw (5) << this->getMove(i).acc << endl;
    }
}