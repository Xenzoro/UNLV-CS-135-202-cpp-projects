#ifndef PACMAZE_H
#define PACMAZE_H

#include <iostream>
#include <string>

using namespace std;

//Struct representing the position in 2D space. Used for keeping track of positions in the maze
struct Position {
	int x, y;

	//Compares two Positions
	bool operator == (const Position& other) 
	{
		return this->x == other.x && this->y == other.y;
	}

	//Assignment operator overload
	Position& operator = (const Position& other)
	{
		this->x = other.x;
		this->y = other.y;
		return *this;
	}

	//Addition
	Position operator + (const Position& other) { return Position(x + other.x, y + other. y); }

	//Subtraction
	Position operator - (const Position& other) { return Position(x - other.x, y - other. y); }

	//Adds individual components to the x and y of the Position and returns a resulting Position
	Position addOffset(int delta_x, int delta_y) { return Position(x + delta_x, y + delta_y); }

	//Saturates this position to be within the given bounds with wrap around
	void saturateBounds(const int& right, const int& bottom)
	{
		if (x < 0) //Wrap around left
			x += right; //Probably safer as (right - ((right - x) % right)), but this should work for the assignment
		if (y < 0) //Wrap around top
			y += bottom;
		x %= right; //wrap around right
		y %= bottom; //Wrap around bottom
	}

	//Formats the Position into a string
	string toString() { return "(" + to_string(x) + ", " + to_string(y) + ")"; }

	//Constructors
	Position(int x, int y) { this->x = x; this->y = y; }
	Position() {}
};

//Constants for commonly used directions
const Position RIGHT = Position(1, 0); //1 space to the right
const Position DOWN = Position(0, 1); //1 space down

//Class representing our automated game of Pacman
class PacMaze
{
	char* maze; //Pointer to a linearized version of the array
	int width, height; //Width and height of the maze

	const char smallPellet = 'o'; //Character for displaying a normal pellet
	const char powerPellet = '@'; //Character for displaying the power pellet

	bool isSolid(const Position& pos);
	bool isEmpty(const Position& pos);
	char getCharAtPos(const Position& pos);
	void placePellet(const Position& pos, char pellet);
public:
	PacMaze(int width, int height, char* maze);

	void drawMaze();
	void populateMaze(Position current_pos);
};

#endif