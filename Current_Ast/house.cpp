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
    // I think this is correct!
    residents[size]; //updates the class with the new size
    arraySize = size; // not using += because we are not adding, but replacing the value
    residentCount += 1; //added because each time we call the function we will add a "resident"
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
        arraySize = arraySize +1;
        tempStr = new string[arraySize];
        //copies data from parent arr into child arr
        for(int i =0; i< arraySize-1; i++){

            tempStr[i] = residents[i];
        }
        tempStr[arraySize-1] = resident_name;
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
    std::cout << "Resident " << i + 1 << ": " << residents[i] <<endl;
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

    Floor** amountFloors;
    amountFloors = new Floor*[num_floors];
    floors = amountFloors;

}

/*  */
House::~House()
{
    //Deallocate all Floors in the house, then deallocate the array that held them

    // TODO: Finish the function


    //ask if this is okay!

   // delete[] floors;
    //or
    for(int i = 0; i < floorCount; i++){
        delete floors[i];
    }
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