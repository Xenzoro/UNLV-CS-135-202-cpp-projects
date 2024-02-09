/* * Name: Jacob Martinez,5007553403, 1008, Lab8B
    * Description: ask a user to input a radius which is then read in.
    * The program will then use user made functions to execute code outside
    * the main.
    * It will calculate both the circumference and the area
    * using radius, cmath, and a global variable.
    * If for whatever reason there is an iput error, the program will then output an
    * error and ask the user again.
    * Input: radius
    * number
    * Output: radius
    * circumference
    * and area.
    *
    * an example of code...
 Enter a circle radius between 0.500000 and 20.500000
**test

Error: Invalid radius!
 Enter a circle radius between 0.500000 and 20.500000
**error

Error: Invalid radius!
 Enter a circle radius between 0.500000 and 20.500000
**15

Radius: 15.00
Circumference: 94.25
Area: 706.86
*/
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
//global const
const double pi = 3.141592;
// Function prototypes
double getDoubleInput (string, double, double);
bool checkFailure(double, double, double);
double circumference(double);
double area(double);
int main() {
    const double MIN = 0.500000;
    const double MAX = 20.500000;
    string prompt1 = "Enter a circle radius between " +
                     to_string(MIN) + " and " +
                     to_string(MAX) + "\n**";

    double radius = getDoubleInput (prompt1, MIN, MAX);
    cout << setprecision(2)<<fixed<< "\nRadius: "<< radius << endl;
    // calculate circumference
    double num2 = circumference(radius);
    cout << setprecision(2) <<fixed  << "Circumference: " << num2 << endl;
    //calculate area
    double ar = area(radius);
    cout <<setprecision(2)<< fixed <<"Area: " << ar;
    return 0;
}
// Function definitions
bool checkFailure (double radius, double min , double max){
    if(radius >= 0.500000 && radius <=20.500000){
        return true;
    }
    cin.clear();
    cin.ignore(100,'\n');
    cout <<"\nError: Invalid radius!\n";
    return false;
}
double getDoubleInput (string prompt, double min, double max){
    double radius = 0;
    bool tF = true;
    do{
        cout << prompt;
        cin >> radius;
        tF = checkFailure (radius, min, max);
        if(tF){
            break;
        }
    }while (true);
    return radius;
}
double circumference(double radius){
    double  circumference = 2 * pi * radius;
    return circumference;
}
double area(double radius){
    double area = pi * pow(radius, 2);
    return area;
}