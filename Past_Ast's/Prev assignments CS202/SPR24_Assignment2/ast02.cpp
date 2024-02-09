/*
    * Name: Jacob Martinez, 5007553403, 1003, ASSIGNMENT_1
    * Description: CRACKING THE VAULT
    * Input: NOTHING
    * Output: OUTPUT OF FUNCTIONS RUNNING
*/
#ifndef A2_C
#define A2_C

#include "jackie.cpp"
#include<iostream>
using namespace std;

//Your code for hacker class
class hacker{
private:
    static int usage;
public:
  static int crackCode(lockcode&);
  static int crackMap(lockmap&);
  static int crackCode(lockcodeV2&);
};

int hacker::usage = 0;

//Your Code Here for hacker class functions
int hacker::crackCode(lockcode& v1){
for (int i=0; i < MAXCODESIZE; i++){
    cout << "Attempting: " << i << endl;
 if( v1.checkCode(i)){
     cout << "Code Cracked! " << '"' << i << '"' << endl;
     return 1;
        }
    }
    return 0;
}
    //why did i have to remove the static?!?! for all of the
    //::hacker class function def?.
 int hacker::crackMap(lockmap& l1){
// we have to create a loop that iterates through the m[10][10]
// array.... now... how?
// i is row, and j is col...

for(int i = 0; i < 10; i++){
        if (l1.check()) {
        cout << "Map Code Cracked!" << endl;
        return 1;
        }
    for(int j = 0 ; j < 10 ; j++){
        if(i%2 == 0) {
            l1.moveRight();
                cout << "Attempting Moving Right" << endl;
            }else{
            l1.moveLeft();
                cout << "Attempting Moving left" << endl;
                }
            if (l1.check()) {
            cout << "Map Code Cracked!" << endl;
            return 1;
            }

    }
            l1.moveDown();
                cout <<"Attempting Moving Down" << endl;
/*            if(l1.check()){
                cout << "Map Code Cracked!" << endl;
                return 1;

                }*/
}
        return 0;

    /*
    // this for loop needs to go right...
     then when it finishes increments j...

    // this loop moves down to the right 10 times!
    // then checks to see if "Map Cracked" each time.
    for(int j = 0; j < 10; j++){
        l1.moveRight();
            cout << "Attempting Moving Right" << endl;
        if(l1.check()){
            cout << "Map Code Cracked!" << endl;
            return 1;
            }
        }
    // after the previous for loop
    // we moveDown and check to is if the map
    // is "Cracked"
        l1.moveDown();
            cout << "Attempting Moving Down" << endl;
        if(l1.check()){
            cout << "Map Code Cracked!" << endl;
            return 1;
                }
    // this for loop iterates to the left
    // and calls moveLeft each time as well as
    // checking "Cracked"
        for(int k = 10 ; k > 0; k--){
            l1.moveLeft();
            cout << "Attempting Moving Left" << endl;
        if(l1.check()){
            cout << "Map Code Cracked!" << endl;
            return 1;
                }
            }
    // after for loop this moves down and checks
    // "Cracked" again!
            l1.moveDown();
            cout << "Attempting Moving Down" << endl;
        if(l1.check()){
            cout << "Map Code Cracked!" << endl;
            return 1;
        }*/
}

    int  hacker::crackCode(lockcodeV2& l2){
    for(int i=0; i < 10; i++){
        int guess = rand()%10;
            cout << "Attempting: " << guess << endl;

        if(l2.checkCode(guess)){
            cout << "Code Cracked! " << '"' << guess << '"' << endl;
            return 1;
                }
            }
        cout << "Failed to Crack it!" << endl;
        return 0;
        }

int ast02(){
    int i =0;
    cout << "Keycode Vault (1)" << endl;    //Vault 1:
    //Your Code here, create a lockcode object called c1
    lockcode c1;
    i += hacker::crackCode(c1);

    cout << "Map Vault (2)" << endl;    //Vault 2:
    lockmap m1;
    i += hacker::crackMap(m1);

    cout << "Keycode Vault V2 (3A)" << endl;    //Vault 3:
    lockcodeV2 x1;
    i += hacker::crackCode(x1);

    cout << "Another Keycode Vault V2 (3B)" << endl;    //Vault 4:
    lockcodeV2 x2; 
    i += hacker::crackCode(x2);
    if(i==4) cout << "\nMission ACCOMPLISHED!\n ggez" << endl;
    return 0;
}

#endif