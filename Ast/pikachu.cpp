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
    cout << "test0\n";
    //returns attackMove
    if(pokemon::getMove(moveIndex).amount <= 0 ){
        cout << "test1\n";
        return 'U';

    }else if (pokemon::getMove(moveIndex).amount > 0){

        pokemon::getMove(moveIndex).amount - 1;
        // 70                                   rand#
        unsigned long out = random.generateRandomNumber();
        out % 100;
        cout << "test2\n";
        cout << pokemon::getMove(moveIndex).acc << endl << " ";
        cout << out;
       if(pokemon::getMove(moveIndex).acc >= random.generateRandomNumber() % 100 ){
            //then HIT!
           cout << "test3\n";
           int total = 0;
            total +=  pokemon::getMove(moveIndex).power - opponent.getDefense(); // Store as percentage?
            total /= 100;
            opponent.decrementHp(opponent.getHp() - total);
           cout << "test4\n";
            return 'H';
       }
    }
    cout << "test5\n";
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