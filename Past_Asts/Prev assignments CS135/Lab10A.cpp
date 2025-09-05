/* * Name: Jacob Martinez,5007553403, 1011, Lab10A
    * Description: I will use structs and functions
    * to ask the user for several inputs...
    * with those inputs I will check for input failure
    * for the grade. then using another function...
    * I will input grade into a letter grade...
    * Finally i will output the entire struct in a neat format...
    * Input: two strings and a int
    * Output: a structs made to symbolize a student.
    *
    * an example of code...
    Enter a first name
**John
Enter a last name
**Smith
Enter a grade
**test

Error: Invalid grade
Enter a grade
**error

Error: Invalid grade
Enter a grade
**29

Error: Invalid grade
Enter a grade
**1

Data Entered
student.firstName   = John
student.lastName    = Smith
student.grade       = 1
student.letterGrade = D
*/

#include <iostream>
using namespace std;
// Create a struct to hold information on students
struct studentType {
// Struct members (attributes, features, elements)
    string firstName;
    string lastName;
    int grade;
    char letterGrade;
};
//function using structs...
void getStudentData (studentType& student);
//function to print struct...
void printStudentData (studentType student);
//function to get student letterGrade...
void getLetterGrade (studentType& student);
int main () {
    //declairing the instance of the struct...
    struct studentType user;
    getStudentData(user);
    getLetterGrade(user);
    printStudentData(user);
}
//function to get data from user for user struct
void getStudentData(studentType& temp){
    // used to enter first and last names
        cout << "Enter a first name\n**\n";
        cin >> temp.firstName;
        cout << "Enter a last name\n**\n";
        cin >> temp.lastName;
        // using a do while loop to enter grade...
        //checking for input error.
        temp.grade = 1;
    do{
        if(cin.fail()||temp.grade < 0|| temp.grade > 4){
            cin.clear();
            cin.ignore(256,'\n');
            cout << "\nError: Invalid grade\n";
        }
        cout << "Enter a grade\n**";
        cin >> temp.grade;

    }while(cin.fail()||temp.grade < 0|| temp.grade > 4);
}
void getLetterGrade (studentType& user){
    switch (user.grade){
        case 0:
            user.letterGrade = 'F';
            break;
        case 1:
            user.letterGrade = 'D';
            break;
        case 2:
            user.letterGrade = 'C';
            break;
        case 3:
            user.letterGrade = 'B';
            break;
        case 4:
            user.letterGrade = 'A';
        default:
            break;
    }
}
void printStudentData(studentType user){
    cout << "\nData Entered\n"
         << "  student.firstName   = " << user.firstName
 << endl << "  student.lastName    = " << user.lastName
 << endl << "  student.grade       = " << user.grade
 << endl << "  student.letterGrade = " << user.letterGrade;
}