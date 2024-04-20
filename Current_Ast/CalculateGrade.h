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
#ifndef CALCULATE_GRADE_H
#define CALCULATE_GRADE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

// Represents a student with various attributes
struct Student {
    string name;       // Student's name
    int age;           // Student's age
    int midterm1;      // Student's first midterm score
    int midterm2;      // Student's second midterm score
    int finalExam;     // Student's final exam score
    char grade;        // Student's final grade
    Student* next;     // Pointer to the next student in the linked list
};

// Global functions for sorting students
bool sortByAge(const Student* a, const Student* b);
bool sortByGrade(const Student* a, const Student* b);

class CalculateGrade {
private:
    Student* headFromFile;  // Pointer to the head of the linked list 
                                //from the file
    Student* tailFromFile;  // Pointer to the tail of the linked list 
                                //from the file
    Student* headFromSample; // Pointer to the head of the linked list 
                                //from the sample data
    Student* tailFromSample; // Pointer to the tail of the linked list 
                                //from the sample data

    // Helper function to insert a new student into the 
    //specified linked list
    void insertStudent(Student*& head, Student*& tail, 
        Student* newStudent);

public:
    CalculateGrade();  // Default Constructor

    // Calculates the grade for the given student based on their scores
    void calculateGrade(Student* student);

    // Inserts a new student into the linked list read from the file
    void insertStudentFromFile(std::string name, int age, int midterm1,
     int midterm2, int finalExam);

    // Inserts a new student into the linked list of sample data
    void insertStudentFromSample(std::string name, int age, int midterm1,
     int midterm2, int finalExam);

    // Sorts the data in the linked list read from the file based 
    //on the given sort criteria
    void sortDataFromFile(std::string sortCriteria);

    // Sorts the data in the linked list of sample data based on the 
    //given sort criteria
    void sortDataFromSample(std::string sortCriteria);

    // Prints the student data from both the file and the sample data
    void printStudents();

    // Computes and prints the grades for all students
    void computeAndPrintGrades();

    // Updates the "studentsData.txt" file with the latest student data, 
    //including calculated grades
    void updateStudentToFile();

    // Destructor
    ~CalculateGrade();
};

#endif // CALCULATE_GRADE_H

