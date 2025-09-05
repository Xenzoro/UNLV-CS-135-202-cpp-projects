/*
    * Name: Jacob Martinez,
    * NSHE ID_#5007553403, 1011,
    * ASSIGNMENT_# Lab2B.
    * Description: use iostream to make a chart
    * and plugin values.
    * Input: values for arithmetic.
    * Output: values after arithmetic.
*/
#include <iostream>
#include <cmath>
#include <iomanip>
double const pi = 3.141592;using namespace std;
int main(){

  double radius (0);
  double circumference(0);
  double area (0);
  string separator = "+--------+---------------+---------+";
  string h1 = "radius", h2 = "circumference", h3 = "area   ";
  string headers = "| " + h1 + " | " + h2 + " | " + h3 + " |\n";
   cout << "Enter the radius of a circle\n" << "**";
   cin >> radius; cout << endl;
   circumference = 2 * pi *radius;
   area = pi * pow(radius,2);
   cout << separator << endl << headers
   << separator << endl << left
   << "| " << setw(6)<< fixed << setprecision(2)<<radius
   << " | " << setw(13)<< circumference
   << " | " <<  setw(7)<< area << " |\n"
   << separator;
    return 0;
}