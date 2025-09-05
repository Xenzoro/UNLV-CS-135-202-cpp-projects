/*
    * Name: Jacob Martinez, NSHE_ID_500755340, 1003 ASSIGNMENT_4
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
//#include "pokemon.cpp"
#include "pikachu.h"
//#include "pikachu.cpp"
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
        infile1.close();
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
        infile2.close();

        int index = 0;
        int playerX = 1;
        char hitChar = 'M';
    do{
        // condition if player 1 is playing
        switch (playerX){
        case 1:

            cout << "Player 1" << endl;
            p1.displayHUD();
            cout << "\nEnter move index: ";
            cin >> index;
            cout << index;
            index--;
            hitChar = p1.attackPikachu(p2, index);
            playerX = 2;
            break;

        case 2:
            cout << "Player 2" << endl;
            p2.displayHUD();
            cout << "\nEnter move index: ";
            cin >> index;
            cout << index;
            index--;
            hitChar = p2.attackPikachu(p1, index);
            playerX = 1;
            break;

        default:
            cout << "Error\n";
            break;
        }
            if(hitChar == 'U')
            {
                cout << "\n\nMove not available\n\n";
            //not sure if this is correct. im supposed to go back
            // to step1
            // not sure if this new method is the correct one either
                if(playerX == 1){
                    playerX = 2;
                }else {
                    playerX = 1;
                }
                continue;
            }
            else if(hitChar == 'M')
            {
                cout << "\n\nAttack Missed\n\n";
            // not sure if this is correct
            //alternate x from 1 to 2 or 2 to 1..
            // what does this mean?
                continue;
            }
            else if(hitChar == 'H')
            {
                cout << "\n\nAttack Hit\n\n";
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
// for the entirety of this assignment I was at tutoring/or
// receiving help.(library)  on tuesday Feb 6 11:30 am - 12:40 pm,
// same on thursday Feb 8. I also received help from the Engineering
// tutor on thursday Feb 8 from 4-5pm I received help periodically in
// the discord server from ramon, and dillon.
}