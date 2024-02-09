/* * Name: Jacob Martinez,5007553403, 1008, Assignment 6
    * Description: make the game of life!
    * ask the user for input and take that input file and check
    * the value's living state.
    * if certain criteria are met a cell will live or die.
    * Input: file
    * name
    * Output: the new live or die
    * values
Enter a filename:as6in1.txt

Current State:
0 0 1 0 1 0 0 0 0
0 1 1 0 1 1 0 1 1
1 1 1 1 1 1 0 0 1
1 0 0 1 0 1 1 1 1
0 1 0 0 1 0 1 1 0
1 1 1 1 1 1 0 0 0
0 0 0 0 1 1 1 1 1
0 1 1 1 0 0 0 0 1
1 1 1 0 1 1 1 0 0

Next State:
0 1 1 0 1 1 0 0 0
1 0 0 0 0 0 1 1 1
1 0 0 0 0 0 0 0 0
1 0 0 0 0 0 0 0 1
0 0 0 0 0 0 0 0 1
1 1 1 0 0 0 0 0 1
1 0 0 0 0 0 1 1 1
1 0 0 0 0 0 0 0 1
1 0 0 0 1 1 0 0 0

 */
#include <iostream>
#include <fstream>
using namespace std;
//global var
const int r = 9, c = 9;
int gg[r][c];
int newGG[r][c];
//funct prototypes
int cLivN(int,int);
void nxtGG();
//start of main funct
int main(){
    ifstream iFile;
    string fName;
//checks filename input
    do {
        cout << "Enter a file name:";
        cin >> fName;
        iFile.open(fName);
        if(!iFile.is_open()){
            cout << " Error: Invalid filename\n";
        }
    }while (!iFile.is_open());
            //double for loops
            for (int i = 0; i < r; ++i) {
                for (int j = 0; j < c; ++j) {
                    //input from file to array incrementially
                    if (!(iFile >> gg[i][j])) {
                        cout << "error" << endl;
                        return -1;
                    }
                }
            }
            cout << "\nCurrent State:\n";
            for (int i = 0; i < r; ++i) {
                for (int j = 0; j < c; ++j) {
                    //output from file incrementially
                    cout << gg[i][j] << " ";
                }
                cout << endl;
            }
            //start update to game
            nxtGG();
            cout << "\nNext State:\n";
            for (int i = 0; i < r; ++i) {
                for (int j = 0; j < c; ++j) {
                    cout << newGG[i][j] << " ";
                }
                cout << endl;
            }
            return 0;
}
int cLivN(int x, int y) {
    int livN = 0;
    for (int i = x - 1; i <= x + 1; ++i) {
        for (int j = y - 1; j <= y + 1; ++j) {
            if (i >= 0 && j >= 0 && i < r &&
            j < c && !(i == x && j == y)){
                livN += gg[i][j];
            }
        }
    }
    return livN;
}
void nxtGG(){
    //double for loop...
    for (int i = 0; i < r; ++i){
        for (int j = 0; j < c; ++j){
            int livN = cLivN(i,j);

            if(gg[i][j] == 1){
                if (livN < 2 || livN > 3) {
                    //kills cell
                    newGG[i][j] = 0;
                }else{
                    //cell lives on
                    newGG[i][j] = 1;
                }
            }else{
                if( livN == 3){
                    //lives bc reproduction
                    newGG[i][j] = 1;
                }else{
                    //stays dead
                    newGG[i][j] = 0;
                }
            }
        }
    }
    //update val to gg[][]
    for(int i = 0; i < r; ++i){
        for(int j = 0; j < c; ++j){
            gg[i][j] = newGG[i][j];
        }
    }
}