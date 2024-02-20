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