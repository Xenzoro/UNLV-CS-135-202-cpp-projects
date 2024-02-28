/*
    * Name: Jacob Martinez, NSHE_ID_500755340, 1003 ASSIGNMENT_4
    * Description: This assignment is a home builder
    * using either user input or a file, we will be able to build a home using
    * pointers. With pointers, we will allocate memory and deallocate memory
    * pointers allows us to play with the sizes of 2D arrays more.
    * For example we can have different rooms with different width/ and heights.
    * We will be using that in this assignment allowing us to make a room
    * in the method we see fit.
    * overview from pdf...
    * The new keyword can be used to dynamically allocate space in C++.
    * There are two things that can be
    *  created with new: objects and arrays. To construct a House, we will create several classes and then dynamically
    *  allocate them to match the specifications of the House. You will be asked to handle the creation
    *  of space, while the Furniture and specifications will be taken care of by your contractor (the skeleton code).
    *  Each house will contain a variable number of floors, and each floor will be a rectangle with variable width
    *  and height. Alongside the house itself, we will keep track of the names of people living within it.
    *  The floors of the house are 2D grids and will need to be allocated as 2D arrays. The house contains some
    *  number of floors, and will have an array containing all of the floors. The residents within the home
    *  is unknown until we are given each of their names. In each of these scenarios that require arrays, the size
    *  of the array is not known ahead of time and will change between houses. As such, static arrays
    *  are inappropriate, since the sizes of each array may vary across different runs of the program
    *  . Dynamic array allocation allows the size of an array to be specified during the run of the program
    *
    * Input: numbers from input txt files/ or user input
    * Output: a visual representation of rooms
*/
#include "floor.h"
#include <iomanip>

using namespace std;

/*  */
Floor::Floor(int width, int height)
{
	//Set the width and height members to the corresponding parameters
	//Then allocate the floorTiles array to be a height x width 2D array of furniture
	//Start by allocating an array of size height and then populate that array with pointers to arrays of size width

	//TODO: Finish the function
    // or is this done automatically because it's called width/height in the function parameters and declaration

    this->width = width;
    this->height =height;

    floorTiles = new Furniture*[this->height];

    for(int i=0; i< height; i++){
        floorTiles[i] = new Furniture[width];
    }

}

/*  */
Floor::~Floor()
{
	//Deallocate the 2D floorTiles array that was allocated in the constructor
	//Deallocate each of the width arrays followed by deallocating the height array
	//The contents of the array are not pointers and do not need to be deallocated

	//TODO: Finish the function

    for(int i =0; i < height; i++ ){
    delete [] floorTiles[i];

    floorTiles[i] = nullptr;
    }

    delete [] floorTiles;
    floorTiles = nullptr;
}

/* Puts the piece of furniture at the given x, y position in the */
void Floor::addFurniture(Furniture piece, int x, int y)
{
	floorTiles[y][x] = piece;
}

/* Prints all of the furniture on a floor */
void Floor::printFloor()
{
	int i, j, k;

	//Print top wall
	cout << setw(IMAGE_SIZE * width + 4) << setfill('-') << "" << setfill(' ') << endl;

	for (i = 0; i < height; i++)
	{
		for (k = 0; k < IMAGE_SIZE; k++)
		{
			cout << "| "; //Print left wall
			for (j = 0; j < width; j++)
				floorTiles[i][j].printLine(k);

			cout << " |" << endl; //Print right wall
		}
	}

	//Print bottom wall
	cout << setw(IMAGE_SIZE * width + 4) << setfill('-') << "" << setfill(' ') << endl;
}

//Tells whether the given (x, y) position is within the bounds of the floor
bool Floor::isInBounds(int x, int y)
{
	return x >= 0 && x < width && y >= 0 && y < height;
}