/*
    * Name: Jacob Martinez, NSHE_ID_500755340, 1003 ASSIGNMENT_4
    * Description: Pok ́emon Yellow Version: Special Pikachu Edition is
    * a role-playing video game developed by Game Freak and published
    * by Nintendo for the Game Boy. In any Pok ́emon game, there are
    * situations where you need to battle other trainers
    * (where you battle their Pok ́emon) or random wild Pok ́emon.
    * They consist of turn based battles where you and your opponent
    * take turns, each pok ́emon have up to 4 moves and each move
    * can be used a finite amount of times. In all of the Pok ́emon
    * games, the matches are strategic and you try to play against
    * your opponent’s weaknesses, but we will have a simple battle
    * between two Pikachu characters. You will implement a 2 player
    * turn based battle game between two Pikachus with slightly
    * different move sets and different defense values. The next few
    * sections describes the classes you will use and in some cases,
    * you will need to implement
    * test2
    * Input: numbers from input txt files
    * Output: a hud of the players hit
*/
#include "house.h"
#include "furniture.h"
#include <iomanip>
#include <string>

using namespace std;

//------------------------------------- ResidentList functions -------------------------------------

/* Your description here */
ResidentList::ResidentList(int size)
{
	//Allocate a string array of the given size for the residents.
	//Remember to initialize the size and count for the list, as well

	//TODO: Finish the function

//        string* temp;
//        temp = new string[size];
    residents = new string[size]; //updates the class with the new size
    arraySize = size; // not using += because we are not adding, but replacing the value
    residentCount = 0;

}

/*  */
ResidentList::~ResidentList()
{
	//Deallocate the residents array if it has been allocated

	//TODO: Finish the function
    //think this is correct
    delete[] residents;
}

/*  */
void ResidentList::addResidentToList(string resident_name)
{
	/* Add the given resident's name to the end of the list of residents.
	This should put the name at the end of the residents array. If there is no more space
	for the string, allocate a bigger array, deep copy over the contents of the old array,
	then deallocate the old array. Remember that the residents pointer must point at the array
	reprenting the list. */

	//TODO: Finish the function

    if(residentCount == arraySize){
        //new string* that stores the old values into the new array
        string* tempStr;
        arraySize = arraySize + SIZE_INCREASE; // size increase == 3;
        tempStr = new string[arraySize];
        //copies data from parent arr into child arr
        for(int i = 0; i< arraySize-SIZE_INCREASE; i++){

            tempStr[i] = residents[i];
        }
        tempStr[arraySize-SIZE_INCREASE] = resident_name;
        residentCount++;
        //deletes old values
        delete[] residents;
        //residents now points to the value of tempStr arr
        residents = tempStr;
    }else {
        residents[residentCount] = resident_name;
        residentCount++;
    }
}

/*  */
void ResidentList::printResidents()
{
	//Print the names of the residents from the residents array to standard out
	//Each should be formatted as:
	//Resident n: name
	//See the rubric for an example of what this looks like
	
	//Print top part
	cout << setw(30) << setfill('#') << "" << setfill(' ') << endl;

	//TODO: Print all resident names in the form Resident n: <name>

    for(int i =0; i< residentCount; i++){
    std::cout << "Resident " << i << ": " << residents[i] <<endl;
    }
	//Print bottom part
	cout << setw(30) << setfill('#') << "" << setfill(' ') << endl;
}

//------------------------------------- House functions -------------------------------------
/*  */
House::House(int num_floors)
{
	//Allocate the floors array to contain the given number of floors. Remember that the array holds references
	//Make sure to initialize all members, although you don't need to make any actual Floors

	//TODO: Finish the function

    floorCount = num_floors;

    floors = new Floor*[num_floors];

}

/*  */
House::~House()
{
    //Deallocate all Floors in the house, then deallocate the array that held them

    // TODO: Finish the function


    //ask if this is okay!


    //or
    for(int i = 0; i < floorCount; i++){
        delete floors[i];
    }
        delete [] floors;
}

/*  Builds the floor on the given level of the house with the given width and height */
void House::buildFloor(int floor_num, int width, int height)
{
	floors[floor_num] = new Floor(width, height);
}

/*  Displays the House to cout, displaying all of the floors individually and their furniture.
Also displays all residents */
void House::displayHouse()
{
	int i;
	residentList.printResidents();
	cout << endl;
	for (i = floorCount - 1; i >= 0; i--) //Go through each floor
	{
		cout << "Floor " << i << endl;
		floors[i]->printFloor();
		cout << endl;
	}
}

/* Adds a resident with the given name to the list of residents living in the house */
void House::addResidentToHouse(string resident_name)
{
	residentList.addResidentToList(resident_name);
}

/* Adds the given piece of furniture to the given floor at the given position. 
Error checks and prints if anything is out of bounds */
void House::addFurniture(int floor_num, int x, int y, Furniture furniture)
{
	//If the floor number is out of bounds
	if (floor_num < 0 || floor_num >= floorCount)
	{
		cout << "Error, floor " << floor_num << " is invalid. Please enter a number from [0," << floorCount << ")" << endl;
		return;
	}

	//If the x position or y position is out of bounds
	if (!floors[floor_num]->isInBounds(x, y))
	{
		cout << "(" << x << ", " << y << ") is not in bounds for floor " << floor_num << " with dimensions ";
		floors[floor_num]->printDimensions();
		cout << endl;
		return;
	}

	//Otherwise, add the furniture
	floors[floor_num]->addFurniture(furniture, x, y);
}