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
        cout << "test2\n";
       cout << "This is the value for both acc and rnd# : "
             << pokemon::getMove(moveIndex).acc << endl
             << " " << random.generateRandomNumber() % 100;
                                                // return num 0-99
       if(pokemon::getMove(moveIndex).acc >= random.generateRandomNumber() % 100){
           //commented out code ^ ... random.generateRandomNumber() % 100
            //then HIT!
           cout << "test3\n";
           double oppDef = 0;
           int total = 0;

           oppDef = opponent.getDefense();
           oppDef /= 100;
           cout << endl
                << "this is the attack you chose: " << pokemon::getMove(moveIndex).name << endl
                << "this is the value of p1 power: "
                << pokemon::getMove(moveIndex).power << endl
                << "this is the value of opp def: " <<  oppDef  << endl;


            total =  pokemon::getMove(moveIndex).power - opponent.getDefense() /100; // Store as percentage?
            cout <<"This is the value of total: " << total << endl << endl;

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