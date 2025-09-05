/*
    * Name: Jacob Martinez,
    * NSHE ID_#5007553403, 1008,
    * ASSIGNMENT_# Lab2A.
    * Description: use input/output variables
    * and arithmetic.
    * Input: values for arithmetic.
    * Output: values after arithmetic.
*/
#include <iostream>
#include <cmath>
const double pi= 3.141592; using namespace std;
int main(){
    double degrees (0);
    double radians (0);
    cout << "Enter an angle value, in degrees\n" <<"**";
    cin >> degrees; cout << endl;
    radians = degrees * pi /180;
    cout << degrees << " degrees = " << radians
         << " radians"<< endl
         << "sin("<< degrees << ") = " << sin(radians)<< endl
         << "cos("<< degrees << ") = " << cos(radians)<< endl
         << "tan("<< degrees << ") = " << tan(radians)<< endl;
    return 0;
}