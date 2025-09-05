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

#include "cake.h"
#include <iostream>
#include <iomanip>

using namespace std;

//-------------------------------- Cake functions --------------------------------

/* TODO: Finish the function and replace this description */
void Cake::addNewLayerToTop(CakeLayer* base_layer, CakeLayer* new_layer)
{
	/*This function should add new_layer to the top of the Cake whose bottom layer is the base_layer.
	(HINT: Think about your reduction operation, if you want to reduce the cake to an "easier" cake,
	what kind of cake would be the most trivial to place the new_layer on top of and how would you transform
	any other cake to that cake?)
	*/

    //base case 01
    if (base_layer->layerAbove == nullptr)
    {
        base_layer->layerAbove = new_layer;
    }else
    {
    //recursive case 01
    addNewLayerToTop(base_layer->layerAbove, new_layer);
    }

}

/* TODO: Finish the function and replace this description */
void Cake::printCake(CakeLayer* current_layer)
{

	/* This function should recursively print the entire cake by printing the current layer
	and the rest of the cake. For a base case, think about what kind of layer is trivial to print
	(HINT: Think about the reduction operator and what it's approaching. What happens when you
	reach that base case?)

	This function should be very short (roughly 4 lines) but requires some thought.
	Consider the information you are given when working through the solution.
	(HINT: You are given the current layer which only has access to the layer above it. 
	If the cake is printed top down in the terminal, when does the layer above the current 
	one need printed with respect to the current layer?) */


    //base case 01
    if (current_layer == nullptr)
    {
        return;
    }
    // recursive case 01
    printCake(current_layer->layerAbove);
    {
        current_layer->printLayer();
    }
}

//Initializes the bottom of the cake (this is done so everything else can be recursive)
void Cake::addBase(CakeLayer* bottom)
{
	if (this->bottom != nullptr)
		cout << "Memory leak... The cake is ruined :(" << endl;

	this->bottom = bottom;
}

//Wrapper function to add a new layer to the cake starting from the bottom.
void Cake::addNewLayerToTop(CakeLayer* new_layer)
{
	addNewLayerToTop(bottom, new_layer); //Add the new layer starting from the bottom
}

/* Wrapper function which starts the recursive calls for printing the Cake
Wrapper functions are functions which do a small amount of work before calling another
function to do the majority. They're nice for doing an initial call to a recursive function
with a starting value without forcing a programmer using it to know how the recursion works
and the initial arguments. */
void Cake::printCake()
{
	//Print the icing on top :)
	cout << setw((CAKE_WIDTH - 1) / 2) << "" << "^" << endl;
	cout << setw((CAKE_WIDTH - 3) / 2) << "" << "(/)" << endl;

	printCake(bottom); //Print the cake starting from the bottom
}

//Deallocates the entire cake, starting from the bottom
Cake::~Cake()
{
	delete bottom;
}

//-------------------------------- CakeLayer functions --------------------------------

/* TODO: Finish the function and replace this description */
CakeLayer::~CakeLayer()
{
	//Write the destructor to deallocate all layers above this one (HINT: This is only two lines. No for/while loops!)
    delete layerAbove;
}

//Prints the layer to cout
void CakeLayer::printLayer()
{
	int leftEdge = (CAKE_WIDTH - width) / 2;

	//Print each line of the layer
	for(int i = 0; i < height; i++)
		cout << setw(leftEdge) << setfill(' ') << "" << setw(width) << setfill(drawChar) << "" << endl;

	cout << setfill(' '); //Set fill back to spaces
}

//Initializes the width and character for drawing the layer before.
//Sets there to be no layer above this one by marking the layerAbove as null
CakeLayer::CakeLayer(int width, int height, char drawChar)
{
	this->height = height;
	this->width = width;
	this->drawChar = drawChar;
	layerAbove = nullptr;
}