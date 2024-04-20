/*
    * Name: Jacob Martinez, 5007553403, 1003, ASSIGNMENT_7
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

#include "pacmaze.h"
#include <iostream>

using namespace std;

/* TODO: Finish the function and replace this description */
void PacMaze::populateMaze(Position current_pos)
{
	//This line keeps the position from going out of bounds (i.e. it does the PacMan wrap around effect)
	current_pos.saturateBounds(width, height); 

	/* This function should populate the entire PacMaze with pellets starting from the given Position.
	   Each spot should contain one of two types of pellets.
	   Pellets should only be placed in empty positions within the maze, that is, spots which do not already contain a pellet or a wall.
	   Please utilize existing class functions.

	   The best way to think of this function is that it should place exactly one pellet and then populate the rest of the maze.
	   Consider only what is necessary to place a pellet in the Position within the maze given as current_pos.
	   Afterwards, try to populate any adjacent spaces recursively.

	   There are two different kinds of pellets that can be placed: small pellets and power pellets. Each are represented using a char constant
	   defined within the PacMaze class. Power pellets should be placed at intersections in the maze where the spaces in each adjacent cardinal
	   direction is not a wall. As an example, where +, -, and | are used to denote walls, and x the position to insert a pellet at:

		No power pellet (3 open spots r, l, d):            Power pellet (4 open spots):
		+-+                                                + +
		 x                                                  x 
		+ +                                                + +

		That is, power pellets are placed in positions where the 4 spaces above, left, right, and below are open. It is fine if pellets already exist
		in the adjacent spaces, they just cannot be solid. The isSolid function will check for this if you provide it a position to check.

		An overview:
		-Check any base cases
		-Check which kind of pellet to place and place it
		-Try to place pellets in the positions adjacent to this one. You can optionally choose to check which directions to try depending
		on your implementation. Remember that Pacman mazes wrap around. The saturateBounds function (called above) can be used to wrap a position
		around to the other side of the maze vertically and horizontally.
	*/

    //base case 01
    if(!isEmpty(current_pos))
    {
        return;
    }
    //
    if (!isSolid(current_pos + DOWN) && !isSolid(current_pos - DOWN) &&
        !isSolid(current_pos + RIGHT) && !isSolid(current_pos - RIGHT))
    {
        //place power pellet if all adjacent spots are empty
        placePellet(current_pos, powerPellet);
    }else
    {
       //place reg pellet.
        placePellet(current_pos, smallPellet);
    }
    //recursive case 01
    populateMaze(current_pos + DOWN);
    //recursive case 02
    populateMaze(current_pos - DOWN);
    //recursive case 03
    populateMaze(current_pos + RIGHT);
    //recursive case 04
    populateMaze(current_pos - RIGHT);
}

//Tells whether the give position is empty in the maze (not a wall and has no pellet)
bool PacMaze::isEmpty(const Position& pos)
{
	return maze[pos.y * width + pos.x] == ' ';
}

//Tells whether the spot is solid (a wall)
bool PacMaze::isSolid(const Position& pos)
{
	char character = maze[pos.y * width + pos.x];
	return character == '|' || character == '+' || character == '-';
}

//Returns the character at a given position
char PacMaze::getCharAtPos(const Position& pos)
{
	return maze[pos.y * width + pos.x];
}

//Puts the pellet with the given char at the given position
void PacMaze::placePellet(const Position& pos, char pellet)
{
	maze[pos.y * width + pos.x] = pellet;
}

//Prints the maze to cout
void PacMaze::drawMaze()
{
	int i, j, counter = 0;
	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			//Print and use color
			cout << ((maze[counter] == smallPellet) ? "\u001b[37m" : 
				(maze[counter] == powerPellet ? "\u001b[33m" : "\u001b[34m"))
				<< maze[counter];
			counter++;
		}
		cout << endl;
	}
	cout << "\u001b[37m"; //Change text back to white
}

//Constructor to create the maze
PacMaze::PacMaze(int width, int height, char* maze)
{
	this->height = height;
	this->width = width;
	this->maze = maze;
}