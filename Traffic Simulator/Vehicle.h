#ifndef VEHICLE_H
#define VEHICLE_H
#include <string>
#include "LightSystem.h"
#include <vector>

class Vehicle{

public:
	Vehicle(char, LightSystem*);
	~Vehicle();
	
	
	virtual void shiftPos() = 0;

	virtual void East() = 0;
	virtual void West() = 0;
	virtual void North() = 0;
	virtual void South() = 0;

	virtual void setEast() = 0;
	virtual void setWest() = 0;
	virtual void setSouth() = 0;
	virtual void setNorth() = 0;

	virtual void setDefaultPos() = 0;
	virtual void move() = 0;

	int getColour();
	char getDirection();
	
	//this is a virtual function because each vehicle has 
	virtual void setDimensions(int, int); 
	
	int getHeight() const;
	int getWidth() const;

	void setSystem(LightSystem *);
	
	int getBack();
	void setBack();

	void showCount();

private:
	int colour;
	char direction;
	//dimensions
	int height;
	int width;

//allows child/derived classes access base class member variables
protected:
	LightSystem *system;

	int *back;
	int *front;
	
	int interEast = 29;
	int interWest = 55;
	int interNorth = 24;
	int interSouth = 9;

	int east, west, north, south = 0;
};
#endif