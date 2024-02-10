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
    if(!pokemon::moveUseable(moveIndex)){
        // checks if the move is not usable
            return 'U';
    }
    // checks if index is out of bounds!
    if(moveIndex > 3||moveIndex < 0){
            return 'U';
    }
    //condition if the move is usable
    else if (pokemon::getMove(moveIndex).amount > 0)
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

           double test = getMove(moveIndex).power -(getMove(moveIndex)
                   .power*(opponent.getDefense()/100.00));
            opponent.decrementHp(test);
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