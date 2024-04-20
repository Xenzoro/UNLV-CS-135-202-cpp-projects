/*
    * Name: Jacob Martinez, 5007553403, 1003, ASSIGNMENT_8
    * Description: Recursion is a powerful tool for problem solving.
    * While not always the most efficient, it allows us to reason
    * through problems that might otherwise be difficult to solve.
    * This assignment differs slightly from the others
    * in that it is not a cohesive program so much as a set
    * of problems. You will be asked to solve several problems
    * recursively
    * Input: number
    * Output: the selected function.
*/
#include <iostream>
#include <fstream>
#include "CalculateGrade.h"

using namespace std;

bool sortByAge(const Student* a, const Student* b)
{
    if(a->age > b->age)
    {
        return true;
    }
        return false;
}

bool sortByGrade(const Student* a, const Student* b)
{
    if(a->grade < b->grade)
    {
        return true;
    }
        return false;
}

void CalculateGrade::calculateGrade(Student* student)
{
    if(student->grade >= 90)
    {
        student->grade = 'A';
    }
    else if(student->grade >= 80)
    {
        student->grade = 'B';
    }
    else if(student->grade >= 70)
    {
        student->grade = 'C';
    }
    else
    {
        student->grade = 'F';
    }
}

void CalculateGrade::insertStudent(Student* &head, Student* &tail, Student* newStudent)
{
    //if the list is vacant or EMPTY
    if(head == nullptr)
    {
        head = newStudent;
        tail = newStudent;
    }
    else
    {
        //this then assumes that the list is not empty
        tail->next = newStudent;
        //this will UPDATE the tail pointer to point to the new student
        tail = newStudent;
    }
    newStudent->next = nullptr;
}

void CalculateGrade::insertStudentFromFile(string name, int age, int midterm1, int midterm2, int finalExam)
{
    //Creates a new student obj w/ the provided parameters
    Student* newStudent = new Student;
    //assigns name
    newStudent->name = name;
    //assigns age
    newStudent->age = age;
    //assigns midterm1
    newStudent->midterm1 = midterm1;
    //assigns midterm2
    newStudent->midterm2 = midterm2;
    //assigns finalExam
    newStudent->finalExam = finalExam;
    //assigns grade to le cero
    newStudent->grade = 0;
    //assigns next to nullptr
    newStudent->next = nullptr;

    //calls the calculateGrade function with the newStudent as a param
    calculateGrade(newStudent);

    //calls the insertStudent function with the headFromSample,
    //tailFromSample, and newStudent as params
    insertStudent(headFromSample, tailFromSample, newStudent);
}
// MAD CONFUSED why write the same function twice?
// seems redundant...
void CalculateGrade::insertStudentFromSample(std::string name, int age,int midterm1, int midterm2,int finalExam)
{
    //Creates a new student obj w/ the provided parameters
    Student* newStudent = new Student;
    //assigns name
    newStudent->name = name;
    //assigns age
    newStudent->age = age;
    //assigns midterm1
    newStudent->midterm1 = midterm1;
    //assigns midterm2
    newStudent->midterm2 = midterm2;
    //assigns finalExam
    newStudent->finalExam = finalExam;
    //assigns grade to le cero
    newStudent->grade = 0;
    //assigns next to nullptr
    newStudent->next = nullptr;

    //calls the calculateGrade function with the newStudent as a param
    calculateGrade(newStudent);

    //calls the insertStudent function with the headFromSample,
    //tailFromSample, and newStudent as params
    insertStudent(headFromSample, tailFromSample, newStudent);
}

void CalculateGrade::printStudents()
{
    Student *current = headFromFile;
    int stuNum = 1;

    //prints the students from the file
    cout << "Students from file:" << endl;
    current = headFromFile;

    //while the current student is not nullptr bc. if it was nullptr it would be the end of the list
    while(current != nullptr)
    {
        cout << "Student " << stuNum << "details" << endl
             << "Name: " << current->name << endl
             << "Age: " << current->age << endl
             << "Midterm 1: " << current->midterm1 << endl
             << "Midterm 2: " << current->midterm2 << endl
             << "Final Exam: " << current->finalExam << endl
             << "Total: " << current->midterm1 + current->midterm2 + current->finalExam << endl
             << "Grade: " << current->grade << endl << endl;
        current = current->next;
        stuNum++;
    }

    //prints the students from the sample data
    cout << "Students from sample data:" << endl;
    current = headFromSample;
    stuNum = 1;

    //while the current student is not nullptr bc. if it was nullptr it would be the end of the list
    while(current != nullptr)
    {
        cout << "Student " << stuNum << "details" << endl
             << "Name: " << current->name << endl
             << "Age: " << current->age << endl
             << "Midterm 1: " << current->midterm1 << endl
             << "Midterm 2: " << current->midterm2 << endl
             << "Final Exam: " << current->finalExam << endl
             << "Total: " << current->midterm1 + current->midterm2 + current->finalExam << endl
             << "Grade: " << current->grade << endl << endl;
        current = current->next;
        stuNum++;
    }
}

/*void CalculateGrade::sortDataFromFile(std::string sortCriteria)
{
    vector<Student*> students;
    Student* current = headFromFile;

    //this will popluate the vector with the students from the file
    while(current != nullptr)
    {
        students.push_back(current);
        current = current->next;
    }

    //this will sort the students based on the sortCriteria
    if(sortCriteria == "age")
    {
       for(int i = 0; i < students.size(); i++)
       {
           for(int j = 0; j < students.size() - 1; j++)
           {
               if(students[j]->age > students[j + 1]->age)
               {
                   swap(students[j], students[j + 1]);
               }
           }
       }
    }
    else if(sortCriteria == "grade")
    {
        sort(students.begin(), students.end(), sortByGrade);
    }
}*/

void CalculateGrade::computeAndPrintGrades()
{
    ofstream outFile("studentsData_OutputFile.txt");

    // this iterates through the LL starting from the headFromFile pointer
    Student* current = headFromFile;

    while(current != nullptr)
    {
        calculateGrade(current);

    //this will write the student data to the file
    outFile << "Name: " << current->name << endl
            << "Age: " << current->age << endl
            << "Midterm 1: " << current->midterm1 << endl
            << "Midterm 2: " << current->midterm2 << endl
            << "Final Exam: " << current->finalExam << endl
            << "Total: " << current->midterm1 + current->midterm2 + current->finalExam << endl
            << "Grade: " << current->grade << endl << endl;

    //move to the next student
    current = current->next;
    }
    outFile.close();
}

void CalculateGrade::updateStudentToFile()
{
    // prompts the user to enter details
    string name;
    int age, midterm1, midterm2, finalExam;
    cout << "Enter the student's name: ";
    getline(cin, name);
    cout << "Enter the student's age: ";
    cin >> age;
    cout << "Enter the student's midterm 1 score: ";
    cin >> midterm1;
    cout << "Enter the student's midterm 2 score: ";
    cin >> midterm2;
    cout << "Enter the student's final exam score: ";
    cin >> finalExam;

    //calls insertStudentFromFile with the provided parameters
    insertStudentFromFile(name, age, midterm1, midterm2, finalExam);

    //open the file in append mode


    //i am stuck here. how can I append data to the end of a txt file that already exists?

    ofstream outFile("studentsData.txt",


}

CalculateGrade::~CalculateGrade()
{
    Student* current = headFromFile;
    Student* next;


    //this will delete the students from the file
    while(current != nullptr)
    {
        next = current->next;
        delete current;
        current = next;
    }

    //this will delete nodes in LL from sample data
    current = headFromSample;

    while(current != nullptr)
    {
        next = current->next;
        delete current;
        current = next;
    }
}