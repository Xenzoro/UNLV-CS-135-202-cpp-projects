/* * Name: Jacob Martinez,5007553403, 1008, Lab7B
    * Description: ask a user to input a number between 2 and 20.
    * Then take that number and ask for a character to be used as
    * a upside down triangle and rightside up triangle.
    * If input error exists, ask again.
    * Input: num and character.
    * Output: upsidedowntrianlge and rightside up triangle.
      an example of the code..
      Enter a count between 2 and 20
**9824756
Error: Invalid entry, please retry
Enter a count between 2 and 20
**85276
Error: Invalid entry, please retry
Enter a count between 2 and 20
**8
Enter a character
////////
///////
//////
/////
////
///
//
// <-- added extra /
// <-- added extra /
//
///
////
/////
//////
///////
////////
*/
#include <iostream>
using namespace std;
// Function prototypes
int getIntegerInput (string, int, int);
char getCharacterInput (string);
void writeUpsideDownTriangle (int, char);
void writeRightsideUpTriangle (int, char);

int main() {
    // Minimums/maximums
    const int MIN = 2;
    const int MAX = 20;
    // Prompt for integer input
    string prompt1 = "Enter a count between " +
                     to_string(MIN) + " and " +
                     to_string(MAX) + "\n**";
    // Prompt for character input
    string prompt2 = "\nEnter a character\n**";

    // Get size of triangle
    int size = getIntegerInput(prompt1, MIN, MAX);
    // Get character to use when printing triangle
    char character = getCharacterInput(prompt2);

    // Write both triangles
    writeUpsideDownTriangle(size, character);
    writeRightsideUpTriangle(size, character);
    cout << endl;

    // Terminate the program
    return 0;
}
// Function definitions
int getIntegerInput(string prompt ,int min ,int max){
    int num = 0;
    do {
        cout << prompt;
        cin >> num;
        if(num >= 2 && num <=20) {
            break;
        }
        {
            cin.clear();
            cin.ignore(100,'\n');
            cout << "\nError: Invalid input!\n";
        }
    }while(!cin.fail());
    return num;
}
char getCharacterInput(string prompt){
    char character = ' ';
    cout << prompt;
    cin >> character;
    return  character;
}
void writeUpsideDownTriangle (int size, char character){
    cout << endl;
    for (int i = size; i >= 1; i--){
        for (int j = 0; j < i; j++)
        {
            cout << character;
        }
        cout << endl;
    }
}
void writeRightsideUpTriangle(int size, char character){
    for (int i= 1; i <= size; i++){
        for (int j = 0; j < i; j++)
        {
            cout << character;
        }
        cout << endl;
    }
}
