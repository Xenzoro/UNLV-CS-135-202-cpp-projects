/*
    * Name: Jacob Martinez, 5007553403, CS 135 1011, Lab 1B
    * Description: Practice outputting and inputting variables and constants with math.
    * Input: 12, 9
    * Output: ...
Enter an integer
**12
Enter another integer
**9
12 + 9 = 21
12 - 9 = 3
12 * 9 = 108
12 / 9 = 1
12 % 9 = 3
Enter a double
**6.8
Enter another double
**4.5
6.8 / 4.5 = 1.51111
*/

#include <iostream>

using namespace std;

int Lab1B(){

     long long int integer1 (0);
     long long int integer2 (0);

        cout << "Enter an integer\n";
        cout << "**\n";
        cin >>  integer1;
        cout << "Enter another integer\n";
        cout << "**\n";
        cin >> integer2;

            cout << integer1 << " + " << integer2 << " = " << integer1 + integer2 << "\n";
            cout << integer1 << " - " << integer2 << " = " << integer1 - integer2 << "\n";
            cout << integer1 << " * " << integer2 << " = " << integer1 * integer2 << "\n";
            cout << integer1 << " / " << integer2 << " = " << integer1 / integer2 << "\n";
            cout << integer1 << " % " << integer2 << " = " << integer1 % integer2 << "\n";
            cout << "\n";


    double double1 (0);
    double double2 (0);

        cout << "Enter a double\n";
        cout << "**\n";
        cin >> double1;
        cout << "Enter another double\n";
        cout << "**\n";
        cin >> double2;

            cout << double1 << " / " << double2 << " = " << double1 / double2 << "\n";

    return 0;
}