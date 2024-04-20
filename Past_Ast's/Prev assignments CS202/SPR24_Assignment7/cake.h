#ifndef CAKE_H
#define CAKE_H

#include <iostream>

const int CAKE_WIDTH = 33;

//Individual layer of the Cake. Multiple will be stacked on top of each other to make the whole cake
class CakeLayer
{
	int width; //Width of this layer
	int height; //Height of the layer
	char drawChar; //Character for drawing this layer
	static int count; //Count of how many layers there are

public:
	CakeLayer* layerAbove;

	void printLayer();
	static int getCount() { return count; }

	CakeLayer(int width = 1, int height = 1, char drawChar = '#');
	~CakeLayer();
};

//Class representing a Cake consisting of layers stacked on top of each other.
//Each layer will point to the layer above it and the cake will keep track of the bottom layer
class Cake
{
	CakeLayer* bottom;
	void printCake(CakeLayer* current_layer);
	void addNewLayerToTop(CakeLayer* base_layer, CakeLayer* new_layer);
public:
	void addBase(CakeLayer* bottom);
	void addNewLayerToTop(CakeLayer* new_layer);
	void printCake();

	Cake() { bottom = nullptr; }
	~Cake();
};

#endif
