#include "general_recursion.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include "pacmaze.h"
#include "cake.h"

using namespace std;

//Static initializers
int CakeLayer::count = 0;
const int PACMAZE_WIDTH = 24;
const int PACMAZE_HEIGHT = 12;

//Function prototypes
int readInteger(istream& in);

//Variables for testing search
const int ARR_SIZE1 = 17;
int arr1[ARR_SIZE1]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17 };
const int ARR_SIZE2 = 8;
int arr2[ARR_SIZE2]{ -3, 0, 4, 5, 8, 9, 11, 200 };

//Maze array
char mazeArr[PACMAZE_HEIGHT*PACMAZE_WIDTH] = 
{
'+', ' ', '+', '-', '-', '-', '-', '-', '-', '+', ' ', '+', '-', '-', '-', '+', ' ', '+', '-', '-', '+', ' ', '+','-',
'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|',' ',
'|', ' ', '+', '-', '-', '+', ' ', '+', '-', '+', ' ', '+', '-', '+', ' ', '+', '-', '+', ' ', '+', '+', ' ', '|',' ',
'+', ' ', '|', ' ', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', '|', ' ', '+','-',
' ', ' ', '|', ' ', ' ', '|', ' ', '|', ' ', '|', ' ', '+', '-', '+', ' ', '|', ' ', '|', ' ', '|', '|', ' ', ' ',' ',
'+', ' ', '+', '-', '-', '+', ' ', '+', '-', '+', ' ', ' ', ' ', ' ', ' ', '|', ' ', '|', ' ', '|', '|', ' ', '+','-',
'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '+', '-', '+', ' ', '+', '-', '-', ' ', '+', '+', ' ', '|',' ',
'|', ' ', '+', '-', '-', '+', ' ', '+', '-', '+', ' ', '|', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|',' ',
'|', ' ', '|', ' ', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '+', '-', '+', ' ', '+', '+', ' ', '|',' ',
'|', ' ', '+', '-', '-', '+', ' ', '+', '-', '+', ' ', '+', '-', '+', ' ', '+', '-', '+', ' ', '+', '+', ' ', '|',' ',
'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|',' ',
'|', ' ', '+', '-', '-', '-', '-', '-', '-', '+', ' ', '+', '-', '-', '-', '+', ' ', '+', '-', '-', '+', ' ', '|',' '
};

int main()
{
	//Print a message about what functions are available to test
	cout << "Please select a function to test:" << endl;
	cout << "(0) findSum" << endl;
	cout << "(1) intLog" << endl;
	cout << "(2) printReverse" << endl;
	cout << "(3) isValueInArray" << endl;
	cout << "(4) PacMaze class" << endl;
	cout << "(5) Cake class" << endl;

	//Variables (Here because switch is being strange?
	string testString;
	PacMaze* maze;
	Cake* cake;

	//Test cases for the functions
	switch (readInteger(cin))
	{
		case 0: //Testing findSum
			cout << "Sum of 1 to 10: " << findSum(10) << endl;
			cout << "Sum of 1 to 400: " << findSum(400) << endl;
			break;	
		case 1: //Testing intLog
			cout << "log2(16) = " << intLog(2, 16) << endl;
			cout << "log10(100000) = " << intLog(10, 100000) << endl;
			cout << "log478(1) = " << intLog(478, 1) << endl;
			break;
		case 2: //Testing printReverse
			testString = "Hello World";
			cout << "\"" << testString << "\"" << " reversed is: ";
			printReverse(testString, testString.length());
			cout << endl;

			testString = "dlroW eybdooG";
			cout << "\"" << testString << "\" reversed is: ";
			printReverse(testString, testString.length());
			cout << endl;

			break;
		case 3: //Testing isValueInArray
			int i;
			cout << "Array 1: { ";
			for (i = 0; i < ARR_SIZE1 - 1; i++)
				cout << arr1[i] << ", ";
			cout << arr1[ARR_SIZE1 - 1] << " }" << endl << endl;

			cout << "Is 13 in the array? ";
			cout << (isValueInArray(arr1, 0, ARR_SIZE1, 13) ? "Yes" : "No") << endl;

			cout << "Is 1 in the array? ";
			cout << (isValueInArray(arr1, 0, ARR_SIZE1, 1) ? "Yes" : "No") << endl;

			cout << "Is 4 in the array? ";
			cout << (isValueInArray(arr1, 0, ARR_SIZE1, 4) ? "Yes" : "No") << endl;

			cout << "Is 20 in the array? ";
			cout << (isValueInArray(arr1, 0, ARR_SIZE1, 20) ? "Yes" : "No") << endl;

			cout << endl << "Array 2: { ";
			for (i = 0; i < ARR_SIZE2 - 1; i++)
				cout << arr2[i] << ", ";
			cout << arr2[ARR_SIZE2 - 1] << " }" << endl << endl;

			cout << "Is 200 in the array? ";
			cout << (isValueInArray(arr2, 0, ARR_SIZE2, 200) ? "Yes" : "No") << endl;

			cout << "Is -4 in the array? ";
			cout << (isValueInArray(arr2, 0, ARR_SIZE2, -4) ? "Yes" : "No") << endl;
			break;	
		case 4: //Testing the PacMaze class
			maze = new PacMaze(PACMAZE_WIDTH, PACMAZE_HEIGHT, mazeArr);
			cout << "Initial Maze: " << endl;
			maze->drawMaze();

			cout << "Inserting pellets starting from position (1, 0)..." << endl;
			maze->populateMaze(Position(1, 0));
			cout << "Done inserting!" << endl;
			maze->drawMaze();

			delete maze;
			break;	
		case 5: //Testing the Cake and CakeLayer classes
			cake = new Cake();
			cout << "Adding the plate..." << endl;
			cake->addBase(new CakeLayer(33, 1, '-'));
			cout << "Adding pound cake..." << endl;
			cake->addNewLayerToTop(new CakeLayer(29, 3, '`'));
			cout << "And cream..." << endl;
			cake->addNewLayerToTop(new CakeLayer(29, 1, '~'));
			cout << "And more pound cake..." << endl;
			cake->addNewLayerToTop(new CakeLayer(29, 3, '`'));

			cout << "How's it looking?" << endl << endl;
			cake->printCake();
			cout << endl << "Pretty good, but we can add more" << endl;

			cout << "Adding chocolate cake..." << endl;
			cake->addNewLayerToTop(new CakeLayer(21, 2, '#'));
			cout << "And chocolate cream..." << endl;
			cake->addNewLayerToTop(new CakeLayer(21, 1, '~'));
			cout << "And more chocolate cake..." << endl;
			cake->addNewLayerToTop(new CakeLayer(21, 2, '#'));

			cout << "Adding the finishing touch..." << endl;
			cake->addNewLayerToTop(new CakeLayer(11, 1, '`'));
			cake->addNewLayerToTop(new CakeLayer(11, 1, '~'));
			cake->addNewLayerToTop(new CakeLayer(11, 2, '#'));

			cout << "The cake is complete! Displaying..." << endl;
			cake->printCake();

			cout << "And finally, time to eat (calling destructor)" << endl;
			delete cake;

			break;
	}

	return 0;
}


//Helper function to read a positive integer from a stream with error checking
int readInteger(istream& in)
{
	int value;
	cin >> value;
	while (cin.fail() || value < 0)
	{
		cout << "Error, please enter a non-negative integer" << endl;
		in.ignore(1024);
		in.clear();
		in >> value;
	}

	return value;
}
