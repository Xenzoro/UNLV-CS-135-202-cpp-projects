/*
    * Name: Jacob Martinez, 5007553403, 1003, ASSIGNMENT_1
    * Description: CRACKING THE VAULT
    * Input: NOTHING
    * Output: OUTPUT OF FUNCTIONS RUNNING
    * Attempting Moving Left
Attempting Moving Left
Attempting Moving Left
Attempting Moving Left
Attempting Moving Left
Attempting Moving Left
Attempting Moving Left
Attempting Moving Left
Attempting Moving Down
Attempting Moving Right
Attempting Moving Right
Attempting Moving Right
Attempting Moving Right
Attempting Moving Right
Attempting Moving Right
Attempting Moving Right
Attempting Moving Right
Attempting Moving Right
Attempting Moving Right
Attempting Moving Down
Attempting Moving Left
Attempting Moving Left
Attempting Moving Left
Attempting Moving Left
Attempting Moving Left
Attempting Moving Left
Attempting Moving Left
Attempting Moving Left
Attempting Moving Left
Attempting Moving Left
Attempting Moving Down
Attempting Moving Right
Attempting Moving Right
Attempting Moving Right
Attempting Moving Right
Attempting Moving Right
Attempting Moving Right
Attempting Moving Right
Attempting Moving Right
Attempting Moving Right
Attempting Moving Right
Attempting Moving Down
Attempting Moving Left
Attempting Moving Left
Attempting Moving Left
Attempting Moving Left
Attempting Moving Left
Attempting Moving Left
Attempting Moving Left
Attempting Moving Left
Attempting Moving Left
Attempting Moving Left
Attempting Moving Down
Attempting Moving Right
*/

#ifndef J_C
#define J_C

#include "jackie.h"
#include<iostream>
using namespace std;

bool lockmap::check() const{
    return m[index1][index2];
}
void lockmap::moveUp(){
    if (index1 > 0)
        index1--;
}
void lockmap::moveRight() {
    if(index2 < 9){
        index2++;
    }
}
void lockmap::moveDown() {
    if(index1 < 9){
        index1++;
    }
}
void lockmap::moveLeft() {
    if(index2 > 0){
        index2--;
    }
}
//Your Code Here
bool lockcode::checkCode(int var) const {
    if(code == var){
        return true;
    }
        return false;
}

bool lockcodeV2::checkCode(int c) {
    if(attemptsLeft > 0){
        if(c >= 0 and c < 10 and c == code){
            attemptsLeft = 3; //reset
            return true;            
        }
        attemptsLeft--;
    }
    return false;
}

#endif