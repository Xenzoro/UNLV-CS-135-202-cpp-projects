#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main () {


    double area = 0.0;
    int radius = 0;

    cout << "Please enter the radius of a circle" << endl;

    cin >> radius;

    area = 3.14 * pow(radius,2);

    cout << "the area of the circle is " << area << endl;

}