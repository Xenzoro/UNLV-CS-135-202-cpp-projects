#include "pikachu.h"
#include "pokemon.h"
#include <iostream>
using namespace std;

bool pikachu::addMove(attackMove m)
{
    if(pokemon::addMove(m)){
        return true;
    }
    return false;
}

void pikachu::decrementHp(int hpAmount)
{
    pokemon::decrementHp(hpAmount);
}

char pikachu::attackPikachu(pikachu& opponent, int moveIndex)
{

    //checks if the move is usable with  player X
    if(!moveUseable(moveIndex)){
        // checks if the move is not usable
            return 'U';
    }
    //condition if the move is usable
    else if (getMove(moveIndex).amount > 0)
    {
            // condition if the move is usable
            //decrements the amount of moves from player X
            pokemon::moveUsed(moveIndex);

        // checks if the move lands on the opponent
        if(pokemon::getMove(moveIndex).acc >= random.
                                         generateRandomNumber() % 100)
        {
            //then the move lands on the opponent or HIT!!
            //spaced out for readability // codegrade
            opponent.decrementHp(pokemon::getMove(moveIndex).
                                   power - opponent.getDefense()/100);
            return 'H';
       }else{
            //the move missed the opponent
            return 'M';
        }
    }
            return 'U';
}

int pikachu::getDefense() const
{
   return pokemon::getDefense();
}

int pikachu::getHp() const
{
    return pokemon::getHp();
}

void pikachu::displayHUD() const
{
    cout << "Pikachu" << endl
         << "HP: " << pokemon::getHp()
         << endl << endl;
    return pokemon::displayHUD();
}