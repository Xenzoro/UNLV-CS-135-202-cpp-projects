/* * Name: Jacob Martinez,5007553403, 1008, Lab9A
    * Description: ask the user for 4 different inputs, two being
    * integers that have been checked for input failure and two
    * seprate strings. The function will use these variables
    * to execute overloaded functions. I also used pass by
    * reference functions and extra functions to get more practice.
    * Input: two ints and two strings
    * Output: some math and strings with math.
    *
    * an example of code...
Enter an integer between 1 and 50
**40
Enter another integer between 1 and 50
**50
Enter a string
**test
Enter another string
**input
40 + 50 = 90
test + input = testinput
40 * 50 = 2000
test * 40 =
testtesttesttesttesttesttesttesttesttesttesttesttesttes
ttesttesttesttesttesttesttesttesttesttesttesttesttest
testtesttesttesttesttesttesttesttesttesttesttesttest

input * 50 = inputinputinputinputinputinputinput
inputinputinputinputinputinputinputinputinputinput
inputinputinputinputinputinputinputinputinputinput
inputinputinputinputinputinputinputinputinputinput
inputinputinputinputinputinputinputinputinputinput
inputinputinput
*/

#include <iostream>
using namespace std;

// Function prototypes
bool checkFailure (int, int, int);
int getIntInput (string,int,int);
int add(int, int);
int multiply(int, int);
void getIntInputs (int&, int&);
void getStringInputs(string&, string&);
string getStringInput (string);
string add(string, string);
string multiply(string, int);
//global consts
const int MIN = 1;
const int MAX = 50;
//main of the funcitons
int main() {
    //delcaired values for functions to start
    int num1 = 0, num2 = 0;
    string string1, string2;
    //gets the inputs for the ints...
    getIntInputs(num1,num2);
    //gets the inputs for the strings...
    getStringInputs(string1,string2);
    //starts the basic math...
    int sum = add(num1,num2);
    cout << sum << endl;
    // outputs the string math...
    string combo1 = add(string1,string2);
    cout << combo1 << endl;
    // outputs simple multiplication...
    int sum2 = multiply(num1,num2);
    cout << sum2 << endl;
    // starts the string math...
    string multiCombo = multiply(string1,num1);
    cout << multiCombo << endl;
    //outputs the string multiplication math...
    string  multiCombo2 = multiply(string2,num2);
    cout << multiCombo2;
    // after the functions are executed it
    //ends the main function.
    return 0;
}
// Function definitions

//first function checks both ints within itself...
void getIntInputs(int& num1, int& num2) {
    string prompt1 = "Enter an integer between " +
                     to_string(MIN) + " and " +
                     to_string(MAX) + "\n**";
    string prompt2 = "Enter another integer between " +
                     to_string(MIN) + " and " +
                     to_string(MAX) + "\n**";
    //stores these ints into variables and sends them back
    //using pass by reference
    int in1 = getIntInput(prompt1, MIN, MAX);
    cout << endl;
    int in2 = getIntInput(prompt2, MIN, MAX);
    num1 = in1;
    num2 = in2;
}
//this function checks strings without the bool check error funct
// because these strings can be anything...
void getStringInputs(string& string1, string& string2){
    string prompt3 = "\nEnter a string\n**";
    string prompt4 = "\nEnter another string\n**";
// also using pass by reference
    string s1 = getStringInput(prompt3);
    string s2 = getStringInput(prompt4);

    string1 = s1;
    string2 = s2;
}
//checks the int inputs to see if they fit within the range
int getIntInput (string prompt, int min, int max) {
    int num1 = 0;
    bool tF = true;
    do {
        cout << prompt;
        cin >> num1;
        // calls a bool funciton to check user error
        tF = checkFailure(num1, min, max);
        if (tF) {
            break;
        }
    } while (true);
    return num1;
}
//checks string input...
string getStringInput(string prompt){
    string txt;
        cout << prompt;
        cin >> txt;
    return txt;
}
//checks failure...
bool checkFailure (int radius, int min , int max) {
    if (radius >= min && radius <= max) {
        return true;
    }
    cin.clear();
    cin.ignore(100, '\n');
    cout << "\nError: Invalid input!\n";
    return false;
}
//does simple math
int add(int num1,int num2){
    cout << endl << num1 << " + " << num2 << " = ";
    int sum = num1 + num2;
    return sum;
}
//does simple string math
string add(string str1, string str2){
    cout << str1 << " + " << str2 << " = ";
    return str1 + str2;
}
//multiplies the nums
int multiply(int num1,int num2){
    cout << num1 << " * " << num2 << " = ";
    int sum = num1 * num2;
    return sum;
}
//multiplies the strings using a for loop
string multiply(string str1,int num){
    string out;
    cout << str1 << " * " << num << " = ";
    //for loop used to output vals.
    for(int i = 0; i < num; i++){
        out += str1;
    }
    return out;
}