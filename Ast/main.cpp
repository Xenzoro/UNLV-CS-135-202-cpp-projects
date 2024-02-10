#include "pokemon.h"
#include "pokemon.cpp"
#include "pikachu.h"
#include "pikachu.cpp"
#include "attackMove.h"
//#include "rnd.h" // not being used!
#include <iostream>
#include <fstream>
using namespace std;

int main(int args, char * argv[])
{


    ifstream infile1;
    ifstream infile2;
    if(args <3){
        cout << "error need more args\n";
        return 0;
    }
        attackMove tmp;
        int d, s = 0;
        //opens pikachu01.txt
        infile1.open(argv[1]);
        //reads in defense and seed
        infile1 >> d >> s;
        //creates pikachu object with inilizaized values
        pikachu p1 (50,d ,s);
        //reads in the moves from the file
    for(int i=0; i < 4; i++){
                    //name     // move amt //move pwr // move acc
        infile1 >> tmp.name >> tmp.amount >> tmp.power >> tmp.acc;
         p1.addMove(tmp);
    }
        //opens pikachu02.txt
        infile2.open(argv[2]);
        //same as above but for pikachu 2
        infile2 >> d >> s;
        //creates pikachu object 2 with inilizaized values
        pikachu p2(50, d, s);
        //reads in the moves from the file
    for(int i = 0; i < 4 ; i++){
                     //name     // move amt //move pwr // move acc
        infile2 >> tmp.name >> tmp.amount >> tmp.power >> tmp.acc;
        p2.addMove(tmp);
    }

        int index = 0;
        int playerX = 1;
        char hitChar;
    do{
        // condition if player 1 is playing
        switch (playerX){
        case 1:
            playerX = 2;
            cout << "Player 1" << endl;
            p1.displayHUD();
            cout << "Enter move index: ";
            cin >> index;
            index--;
            hitChar = p1.attackPikachu(p2, index);
            break;
        case 2:
            playerX = 1;
            cout << "Player 2" << endl;
            p2.displayHUD();
            cout << "Enter move index: ";
            cin >> index;
            index--;
            hitChar = p2.attackPikachu(p1, index);
            break;
        default:
            cout << "Error\n";
            break;
        }
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
                cout << "Attack Hit\n\n";
            //alternate 1 to 2 or vice versa again... how?
                continue;
            }
                cout << "Winner is " << "TEST \n";
        }while( p1.getHp() > 0 && p2.getHp() > 0);

        if(p1.getHp() == 0){
            cout << "Player 2 wins\n";
        }
        else if(p2.getHp() == 0){
            cout << "Player 1 wins\n";
        }
                return 0;
}