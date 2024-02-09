/*
    * Name: Jacob Martinez,
    * NSHE ID_#5007553403, 1011,
    * ASSIGNMENT_# Lab4A.
    * Description: ask for 3 values then output
    * Input: values for increment and base values
    * Output: first start value
    * second, ending value
    * third, increment value
    * ie.
    * 0
    * 10
    * 1
    * 0 1 2 3 4 5 6 7 8 9 10
*/
#include <iostream>
using namespace std;
int main() {
    int startingNumber (0);
    int endingNumber (0);
    int increment (0);
    cout << "Enter a starting number\n**";
    cin >> startingNumber;
        if (cin.fail()) {
        cout << "\nError: Invalid entry.";
        return 0;
    }
    cout << "\nEnter an ending number\n**";
    cin >> endingNumber;
        if (cin.fail()) {
        cout << "\nError: Invalid entry.";
        return 0;
    }
        if (startingNumber >= endingNumber) {
        cout << "\nError: end must be greater than start.";
        return 0;
        }
    cout <<"\nEnter a value to increment by \n**\n";
    cin >> increment;
        if (cin.fail()) {
        cout << "Error: Invalid entry.";
        return 0;
    }
            while (startingNumber <= endingNumber) {
               cout << startingNumber << " ";
                startingNumber = startingNumber + increment;
                }
        return 0;
}




