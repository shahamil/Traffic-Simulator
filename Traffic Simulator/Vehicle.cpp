#include "Vehicle.h"
#include<random>
#include"functions.h"

using namespace std;

Vehicle::Vehicle(char dir, LightSystem *newSystem){
	colour = rand() % 6;
	direction = dir;
	height = 0;
	width = 0;
	setSystem(newSystem);
}

void Vehicle::showCount(){
	
		gotoxy(80, 4);
		coutc(6, east);

		gotoxy(80, 5);
		coutc(6, west);

		gotoxy(80, 6);
		coutc(6, north);

		gotoxy(80, 7);
		coutc(6, south);
	
}

int Vehicle::getColour(){
	return colour;
}

int Vehicle::getBack(){
	return *back;
}

char Vehicle::getDirection(){
	return direction;
}

void Vehicle::setBack(){

}

void Vehicle::setDimensions(int h, int w){
	//if (direction == 'E'|| direction == 'W'){
		height = h;
		width = w;

	//}

	//else {
		//height = w;
		//width = h;

	//}
}

int Vehicle::getHeight() const{

	return height;
}


int Vehicle::getWidth() const{

	return width;
}

void Vehicle::setSystem(LightSystem *lightSystem){

	system = lightSystem;

}

Vehicle::~Vehicle(){


}