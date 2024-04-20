/*
Assignment 8 Description: In this assignment you will learn to use singly linked lists.
You have to code the implementation file that has multiple functions. 
This assignment includes various operations on student data, such as 
reading data from a file, inserting sample data, sorting the data based on
different criteria, taking user inputs, and updating the data file.    

The main() function serves as the entry point for the program. 
The program reads student data from a file named "studentsData.txt" and 
inserts it into a linked list using the insertStudentFromFile() function of 
the CalculateGrade class. The program also includes some hard-coded sample 
student data, which is inserted into the linked list using the 
insertStudentFromSample() function of the CalculateGrade class. 
Input file: studentsData.txt
OutputFiles: Generated when you run the code
sortedFileData.txt, sortedSampleData.txt, studentsData_OutputFile.txt
Note: You will upload only one implementation file "calculateGradeImp.cpp"
for this Assignment 8
*/

#include <iostream>
#include "CalculateGrade.h"
using namespace std;

int main() {
    CalculateGrade calculator;

    // Read data from file and insert into linked list for file data
    ifstream inputFile("studentsData.txt");
    string name;
    int age, midterm1, midterm2, finalExam;

    while (inputFile >> name >> age >> midterm1 >> midterm2 >> finalExam)
     {
        calculator.insertStudentFromFile(name, age, midterm1, midterm2, 
            finalExam);
    }

    // Hard-coded sample data
    calculator.insertStudentFromSample("Lisa", 21, 88, 99, 77);
    calculator.insertStudentFromSample("Kyle", 32, 78, 76, 75);
    calculator.insertStudentFromSample("Andy", 25, 92, 88, 95);
    calculator.insertStudentFromSample("Jason", 28, 65, 70, 68);
    calculator.insertStudentFromSample("Sarah", 22, 80, 85, 82);

    int choice;
    cout << "Menu:\n1. Sort data from file\n2. Sort sample data\n3."
    <<" Take 3 user inputs and sort\n";
    cout << "4. Insert a student to studentsData.txt\nEnter choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            {
                cout << "Sort data by:\n1. Age\n2. Grade (A to F)\n3."
                <<" Sort Low to High (F to A, if letter grade is the same, "
                <<"youngest age is at the top)"
                <<"\nEnter sorting criteria: ";
                int sortChoice;
                cin >> sortChoice;

                string sortCriteria;
                switch (sortChoice) {
                    case 1:
                        sortCriteria = "age";
                        break;
                    case 2:
                        sortCriteria = "grade";
                        break;
                    default:
                        sortCriteria = "sortLow";
                        break;
                }

                calculator.sortDataFromFile(sortCriteria);
            }
            break;
        case 2:     
            {
                cout << "Sort data by:\n1. Age\n2. Grade (A to F)\n3."
                <<" Sort Low to High (F to A, if letter grade is the same, "
                <<"youngest age is at the top)"
                <<"\nEnter sorting criteria: ";
                int sortChoice;
                cin >> sortChoice;

                string sortCriteria;
                switch (sortChoice) {
                    case 1:
                        sortCriteria = "age";
                        break;
                    case 2:
                        sortCriteria = "grade";
                        break;
                    default:
                        sortCriteria = "sortLow";
                        break;
                }

                calculator.sortDataFromSample(sortCriteria);
            }
            break;
        case 3:
            for (int i = 0; i < 3; ++i) {
                string stdName;
                int ag, m1, m2, fExam;
                cout << "Enter Student "<< i+1 <<" details" << endl;
                cout << "Enter name (stdName): ";
                cin >> stdName;
                cout << "Enter age (ag): ";
                cin >> ag;
                cout << "Enter Midterm1(m1): ";
                cin >> m1;
                cout << "Enter Midterm2(m2): ";
                cin >> m2;
                cout << "Enter finalExam(fExam): ";
                cin >> fExam;

                calculator.insertStudentFromSample(stdName, ag, m1, m2, 
                    fExam);
            }

            {
                cout << "Sort data by:\n1. Age\n2. Grade (A to F)\n3."
                <<"Sort Low to High (F to A, if letter grade is the same, "
                <<"youngest age is at the top)"
                <<"\nEnter sorting criteria: ";
                int sortChoice;
                cin >> sortChoice;

                string sortCriteria;
                switch (sortChoice) {
                    case 1:
                        sortCriteria = "age";
                        break;
                    case 2:
                        sortCriteria = "grade";
                        break;
                    default:
                        sortCriteria = "sortLow";
                        break;
                }

                calculator.sortDataFromSample(sortCriteria);
            }
            break;
        case 4:
            calculator.updateStudentToFile();
            break;
        default:
            cout << "Invalid choice\n";
            break;
    }

    calculator.computeAndPrintGrades();

    //calculator.printStudents() prints the data on console window
    //This prints the grades in the order that studentsData.txt file has
    //and also prints the hardcoded sample data in this main()
    calculator.printStudents();

    return 0;
}

