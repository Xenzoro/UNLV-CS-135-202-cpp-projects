/*
    * Name: Jacob Martinez, 5007553403, 1003, ASSIGNMENT_8
    * Description: The main() function serves as the entry point
    * for the program. The program reads student data from a
    file named "studentsData.txt" and inserts it into a linked list
    using the insertStudentFromFile() function
    of the CalculateGrade class. The program also includes some
    hard-coded sample student data, which is inserted into the linked
    list using the insertStudentFromSample() function of the
    CalculateGrade class.
    * Input: number
    * Output: le grades ;)
*/
#include <iostream>
#include <fstream>
#include "CalculateGrade.h"

using namespace std;

CalculateGrade::CalculateGrade()
{
    headFromFile = nullptr;
    tailFromFile = nullptr;
    headFromSample = nullptr;
    tailFromSample = nullptr;
}
// this function will read the student data from the file
bool sortByAge(const Student* a, const Student* b)
{
    if(a->age > b->age)
    {
        return true;
    }
        return false;
}
// this function will read the student data from the file
bool sortByGrade(const Student* a, const Student* b)
{
    if(a->grade < b->grade)
    {
        return true;
    }
        return false;
}
// this function will read the student data from the file
void CalculateGrade::calculateGrade(Student* student)
{
    int tScore = (student->midterm1 + student->midterm2 + student->finalExam) / 3;

    if(tScore >= 90)
    {
        student->grade = 'A';
    }
    else if(tScore >= 80)
    {
        student->grade = 'B';
    }
    else if(tScore >= 70)
    {
        student->grade = 'C';
    }
    else
    {
        student->grade = 'F';
    }
}
// this function will read the student data from the file
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
 // this function will read the student data from the file
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
    insertStudent(headFromFile, tailFromFile, newStudent);
}
// MAD CONFUSED why write the same function twice?
// seems redundant... i guess cause
// one is for the file and the other is for the sample data?
// this function will read the student data from the file
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
// this function will read the student data from the file
void CalculateGrade::printStudents()
{
    Student *current = headFromFile;
    int stuNum = 1;

    //prints the students from the file
    cout << "Students from file:" << endl;


    //while the current student is not nullptr bc. if it was nullptr it would be the end of the list
    while(current != nullptr)
    {
        cout << "Student " << stuNum << " details" << endl
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
        cout << "Student " << stuNum << " details" << endl
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
// this function will read the student data from the file
void CalculateGrade::sortDataFromFile(std::string sortCriteria)
{
    vector<Student*> students;
    Student* current = headFromFile;

    //this will popluate the vector with the students from the file
    while(current != nullptr)
    {
        //this adds the value of head into the vector
        //then it moves to the next student in the LL
        // and adds that to the vector
        students.push_back(current);
        current = current->next;
    }

    //sorts based on criteria
    //these if statements are extremely confusing to me
    //they do something then get flipped to do something else if
    //the criteria is not met...
    for(int i = 0; i < students.size() - 1; i++)
    {
        for(int j = 0; j < students.size() - i - 1; j++)
        {
            if(sortCriteria == "age" && students[j]->age < students[j + 1]->age)
            {
                swap(students[j], students[j + 1]);
            }
            else if(sortCriteria == "grade" && students[j]->grade > students[j + 1]->grade)
            {
                swap(students[j], students[j + 1]);
            }
            else if(sortCriteria != "age" && sortCriteria != "grade")
            {
                if(students[j]->grade < students[j + 1]->grade)
                {
                    swap(students[j], students[j + 1]);
                }
                else if(students[j]->grade == students[j + 1]->grade)
                {
                    if(students[j]->age > students[j + 1]->age)
                    {
                        swap(students[j], students[j + 1]);
                    }
                    else if(students[j]->age == students[j + 1]->age && students[j]->name > students[j + 1]->name)
                    {
                        swap(students[j], students[j + 1]);
                    }
                }
            }
        }
    }
    //this will write the sorted data to the file
    ofstream outFile("sortedFileData.txt");

    int stuNum = 1;
    //output required by pdf
    cout << "Student Size: " << students.size() << endl;

    //this will write the sorted data to the file
    for(int i = 0; i < students.size(); i++)
    {
        //had to do it this way because the output was not matching
        // the pdf
        if(i == 0)
        {
            outFile << "Student " << stuNum << " details:" << endl
                    << "Name: " << students[i]->name << endl
                    << "Age: " << students[i]->age << endl
                    << "Midterm1: " << students[i]->midterm1
                    << " Midterm2: " << students[i]->midterm2
                    << " FinalExam: " << students[i]->finalExam
                    << " Total: " << students[i]->midterm1 +
                    students[i]->midterm2 + students[i]->finalExam
                    << "Grade: " << students[i]->grade << endl;
        }else
        {
            outFile << "Student " << stuNum << " details:"
                    << " Name: " << students[i]->name
                    << " Age: " << students[i]->age
                    << " Midterm1: " << students[i]->midterm1
                    << " Midterm2: " << students[i]->midterm2
                    << " FinalExam: " << students[i]->finalExam
                    << " Total: " << students[i]->midterm1 +
                                     students[i]->midterm2 +
                                     students[i]->finalExam
                    << " Grade: " << students[i]->grade << endl;
        }
        stuNum++;
    }

    outFile.close();
    cout << "Result written to file sortedFileData.txt" << endl;
}
//  this function will populate the vector
//  with the students from the sample data and sort them
//  based on the criteria
void CalculateGrade::sortDataFromSample(std::string sortCriteria)
{
    vector<Student*> students;
    Student* current = headFromSample;

    //populate the vector with the students from the sample data
    while(current != nullptr)
    {
        students.push_back(current);
        current = current->next;
    }
    //sorts based on criteria
    //these if statements are extremely confusing to me
    ///they do something then get flipped to do something else.

    for(int i = 0; i < students.size() - 1; i++)
    {
        for(int j = 0; j < students.size() - i - 1; j++)
        {
            if(sortCriteria == "age" && students[j]->age < students[j + 1]->age)
            {
                swap(students[j], students[j + 1]);
            }
            else if(sortCriteria == "grade" && students[j]->grade > students[j + 1]->grade)
            {
                swap(students[j], students[j + 1]);
            }
            else if(sortCriteria != "age" && sortCriteria != "grade")
            {
                if(students[j]->grade < students[j + 1]->grade)
                {
                    swap(students[j], students[j + 1]);
                }
                else if(students[j]->grade == students[j + 1]->grade)
                {
                    if(students[j]->age > students[j + 1]->age)
                    {
                        swap(students[j], students[j + 1]);
                    }
                    else if(students[j]->age == students[j + 1]->age && students[j]->name > students[j + 1]->name)
                    {
                        swap(students[j], students[j + 1]);
                    }
                }
            }
        }

    /*for(int i = 0; i < students.size() - 1; i++)
    {
        for(int j = 0; j < students.size() - i - 1; j++)
        {
            if(sortCriteria == "age")
            {

                //sorts in ascending order
                if(!sortByAge(students[j], students[j + 1]))
                {
                    swap(students[j], students[j + 1]);
                }
            }
            else if(sortCriteria == "grade")
            {
                //sorts in descending order
                if(!sortByGrade(students[j], students[j + 1]))
                {
                    swap(students[j], students[j + 1]);
                }
            }
            else
            {
                //sorts in ascending order of grade
                if(students[j]->name < students[j + 1]->name)
                {
                    swap(students[j], students[j + 1]);
                }

            }
        }

*/
    /*for(int i = 0; i < students.size() - 1; i++)
    {
        for(int j = 0; j < students.size() - i - 1; j++)
        {
            if(sortCriteria == "age")
            {
                //sorts in ascending order
                if(students[j]->age > students[j + 1]->age)
                {
                    swap(students[j], students[j + 1]);
                }
            }else if(sortCriteria == "grade")
            {
                //sorts in descending order
                if(students[j]->grade < students[j + 1]->grade)
                {
                    swap(students[j], students[j + 1]);
                }
            }else
            {
                if(sortCriteria != "age" || sortCriteria != "grade")
                {
                    //sorts in descending order
                    if(students[j]->grade < students[j + 1]->grade)
                    {
                        swap(students[j], students[j + 1]);
                    }
                    if(students[j]->age > students[j + 1]->age)
                    {
                        //sorts in ascending order
                        swap(students[j], students[j + 1]);
                    }
                    if(students[j]->name > students[j + 1]->name)
                    {
                        //sorts in ascending order
                        swap(students[j], students[j + 1]);
                    }
                }
            }
*/
            /*if(sortCriteria == "grade" && students[j]->grade < students[j + 1]->grade)
            {
                swap(students[j], students[j + 1]);
            }
            else if(sortCriteria == "age" && students[j]->age > students[j + 1]->age)
            {
                swap(students[j], students[j + 1]);
            }
            else if(sortCriteria != "age" && sortCriteria != "grade")
            {
                if(students[j]->grade < students[j + 1]->grade)
                {
                    swap(students[j], students[j + 1]);
                }
                else if(students[j]->grade == students[j + 1]->grade)
                {
                    if(students[j]->age > students[j + 1]->age)
                    {
                        swap(students[j], students[j + 1]);
                    }
                    else if(students[j]->age == students[j + 1]->age && students[j]->name > students[j + 1]->name)
                    {
                        swap(students[j], students[j + 1]);
                    }
                }
            }*/
        //}
    }
    ofstream outFile("sortedSampleData.txt");

    int stuNum = 1;

    cout << "Student Size: " << students.size() << endl;

    //this will write the sorted data to the file
    for(int i = 0; i < students.size(); i++)
    {
        if(i == 0)
        {
            outFile << "Student " << stuNum << " details:" << endl
                    << "Name: " << students[i]->name << endl
                    << "Age: " << students[i]->age << endl
                    << "Midterm1: " << students[i]->midterm1
                    << " Midterm2: " << students[i]->midterm2
                    << " FinalExam: " << students[i]->finalExam
                    << " Total: " << students[i]->midterm1 +
                                     students[i]->midterm2 + students[i]->finalExam
                    << "Grade: " << students[i]->grade << endl;
        }else
        {
            outFile << "Student " << stuNum << " details:"
                    << " Name: " << students[i]->name
                    << " Age: " << students[i]->age
                    << " Midterm1: " << students[i]->midterm1
                    << " Midterm2: " << students[i]->midterm2
                    << " FinalExam: " << students[i]->finalExam
                    << " Total: " << students[i]->midterm1 +
                                     students[i]->midterm2 +
                                     students[i]->finalExam
                    << " Grade: " << students[i]->grade << endl;
        }
        stuNum++;
    }
    outFile.close();

    cout << "Students from Sample:" << endl;
}

// this function will compute and print the grades for all students
void CalculateGrade::computeAndPrintGrades()
{
    ofstream outFile("studentsData_OutputFile.txt");

    // this iterates through the LL starting from the headFromFile pointer
    Student* current = headFromFile;
    int stuNum = 1;

    while(current != nullptr)
    {
        calculateGrade(current);
    if(stuNum == 1)
    {
        outFile << "**************************************" << endl
                << "Student " << stuNum << ":" << endl;
    }else
    {
       outFile << "Student " << stuNum << ":" << endl;
    }
    //this will write the student data to the file
    outFile << "Name: " << current->name << endl
            << "Age: " << current->age
            << " Midterm 1: " << current->midterm1
            << " Midterm 2: " << current->midterm2 << endl
            << " Final Exam: " << current->finalExam << endl
            << " Total: " << current->midterm1 + current->midterm2 + current->finalExam << endl
            << " Grade: " << current->grade << endl
            << "**************************************";

    //move to the next student
    current = current->next;
    stuNum++;
    }
    outFile.close();
}
// this function will update the student data to the file
void CalculateGrade::updateStudentToFile()
{
    // prompts the user to enter details
    string name;
    int age, midterm1, midterm2, finalExam;
    cout << "Enter the student's name: ";
    cin >> name;
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

    //use ios::app given in CS Discord

    ofstream outFile("studentsData.txt",ios::app);

    //write the student data to the file
    outFile << name << " " << age << " " << midterm1 << " " << midterm2 << " " << finalExam << endl;

    //close the file
    outFile.close();

    //print message
    cout << "The student details have been updated in the 'StudentData.txt' file" << endl;
}
 //destructor to delete the students from the file
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