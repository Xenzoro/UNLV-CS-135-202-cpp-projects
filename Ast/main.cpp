#include "pokemon.h"
#include "pokemon.cpp"
#include "pikachu.h"
#include "pikachu.cpp"
#include "attackMove.h"
#include <iostream>
#include <fstream>
using namespace std;

int main(int args, char * argv[])
{
    if(args <3){
        cout << "error need more args\n";
        return 0;
    }
    ifstream infile1;
    ifstream infile2;

    infile1.open(argv[1]);
    //checks for user error
    if(!infile1.is_open()) {
        cout << "error: Input file " << argv[1] <<" NOT detected"  << endl;
        return 0;
    }

    attackMove tmp;
    int d, s = 0;
    infile1 >> d >> s;
    pikachu p1 (100,d ,s);
    for(int i=0; i < 4; i++){
                    //name     // move amt //move pwr // move acc
        infile1 >> tmp.name >> tmp.amount >> tmp.power >> tmp.acc;
         p1.addMove(tmp);
    }

    infile2.open(argv[2]);
    if(!infile1.is_open()){
        cout << "error: Input file " << argv[2] <<" NOT detected" << endl;
        return 0;
    }
    infile2 >> d >> s;
    pikachu p2(100, d, s);
    for(int i = 0; i < 4 ; i++){
        infile2 >> tmp.name >> tmp.amount >> tmp.power >> tmp.acc;
        p2.addMove(tmp);
    }
    int index = 0;
    int playerX = 0;
    while( p1.getHp() > 0 && p2.getHp() > 0){
        // condition if player 1 is playing
        if(playerX %2 == 0)
        {
            playerX++;
            cout << "Player 1" << endl;
            p1.displayHUD();
            cout << "Enter move index: ";
            cin >> index;
            char hitChar;
            hitChar = p1.attackPikachu(p2, index);
            cout << "test1\n";
        if(hitChar == 'U')
        {
            cout << "Move not available\n";
            //not sure if this is correct. im supposed to go back to step1
            //continue I mean.
            continue;
        }
        else if(hitChar == 'M')
        {
            cout << "Attack Missed\n";
            // not sure if this is correct
            //alternate x from 1 to 2 or 2 to 1..
            // what does this mean?
            continue;
        }
        else if(hitChar == 'H')
        {
            cout << "Attack Hit\n";
            //alternate 1 to 2 or vice versa again... how?
            continue;
        }
        cout << "Winner is " << "TEST \n";
        }
        else if(playerX %2 == 1){
            playerX++;
            cout << "player 2" << endl;
            p2.displayHUD();
            cout << "Enter move index: ";
            cin >> index;
            char hitChar = p2.attackPikachu(p1, index);

            if(hitChar == 'U'){
                cout << "Move not available\n";
                //not sure if this is correct. im supposed to go back to step1
                //continue I mean.
                continue;
            }else if(hitChar == 'M'){
                cout << "Attack Missed\n";
                // not sure if this is correct
                //alternate x from 1 to 2 or 2 to 1..
                // what does this mean?
                continue;
            }else if(hitChar == 'H'){
                cout << "Attack Hit\n";
                //alternate 1 to 2 or vice versa again... how?
                continue;
            }
        }
    }

    return 0;
}