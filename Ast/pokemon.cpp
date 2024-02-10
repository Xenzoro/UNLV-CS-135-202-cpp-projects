/*
    * Name: Jacob Martinez, NSHE_ID_500755340, 1003 ASSIGNMENT_3
    * Description: Pok ́emon Yellow Version: Special Pikachu Edition is
    * a role-playing video game developed by Game Freak and published
    * by Nintendo for the Game Boy. In any Pok ́emon game, there are
    * situations where you need to battle other trainers
    * (where you battle their Pok ́emon) or random wild Pok ́emon.
    * They consist of turn based battles where you and your opponent
    * take turns, each pok ́emon have up to 4 moves and each move
    * can be used a finite amount of times. In all of the Pok ́emon
    * games, the matches are strategic and you try to play against
    * your opponent’s weaknesses, but we will have a simple battle
    * between two Pikachu characters. You will implement a 2 player
    * turn based battle game between two Pikachus with slightly
    * different move sets and different defense values. The next few
    * sections describes the classes you will use and in some cases,
    * you will need to implement
    * test2
    * Input: numbers from input txt files
    * Output: a hud of the players hit
*/
#include "pokemon.h"
#include "attackMove.h"
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