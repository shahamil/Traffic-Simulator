#include "TrafficLight.h"
#include <iostream>
#include "functions.h"
using namespace std;

TrafficLight::TrafficLight(int gTime, int rTime, int yTime, char direction){
	redLight = false;
	yellowLight = false;
	greenLight = false;
	
	//set the timings for the light cycles
	greenTime = gTime;
	redTime = rTime;
	
	//intersection + largestVehicle size
	yellowTime = yTime;
	dir = direction;
	totalTime = gTime + rTime + yTime;
}

/***
this returns the timer count corresponidng to the time the light is 
red, green or yellow
***/
int TrafficLight::getTimerCount() const{

	return timer;
}

/***
used to set the lights to green, red or yellow
***/
void TrafficLight::setLightCycleDuration(int green, int red, int yellow){
	greenTime = green;
	redTime = red;
	yellowTime = yellow;
}

/***
returns the time the green light will be on
***/
int TrafficLight::getGreenTime(){
	return greenTime;
}

/***
returns the time the red light will be on
***/
int TrafficLight::getRedTime(){
	return redTime;
}

/***
returns the time the yellow light will be on
***/
int TrafficLight::getYellowTime(){
	return yellowTime;
}

/***
sets the timer that specifies howl long the light stays
red, green or yellow
***/
void TrafficLight::setTimerCount(int cTime){

	timer = cTime;
}

/***
Returns a bool value to indicate if the green light 
is on or off
***/
bool TrafficLight::getStateGreen(){
	return greenLight;
}

/***
Returns a bool value to indicate if the red light
is on or off
***/
bool TrafficLight::getStateRed(){
	return redLight;
}
/***
Returns a bool value to indicate if the yellow light
is on or off
***/
bool TrafficLight::getStateYellow(){
	return yellowLight;
}

/***
unused function
***/
void TrafficLight::setLightPos(int greenX, int greenY, int yellowX, int yellowY, int redX, int redY){

	//set green coordinates
	x = greenX;
	y = greenY;

	//set yellow coordinates
	a = yellowX;
	b = yellowY;

	//set red coordinates
	g = redX;
	h = redY;


}

/***
prints the light in the given sections
***/
void TrafficLight::printLight(){

	if (greenLight == true){
		gotoxy(x, y);
		coutchar(2, 199);

	}

	else if (yellowLight == true){
		gotoxy(a, b);
		coutchar(2, 199);

	}
	
	else if (redLight == true){
		gotoxy(g, h);

	}

}

/***
turns the green traffic light on
***/
void TrafficLight::turnGreen(){
	//turn of red light before turning green
	redLight = false;
	greenLight = true;
	if (dir == 'H'){
		
		//show green light present on the map
		gotoxy(27, 17);
		coutchar(10, 127);
		
		//removes red light from west side traffic light of the map
		gotoxy(25, 17);
		coutchar(0, 127);


		gotoxy(57, 17);
		coutchar(10, 127);

		gotoxy(59, 17);
		coutchar(0, 127);

	}
	else if (dir == 'V'){
		
		//show green light on North side traffic light
		gotoxy(42, 7);
		coutchar(10, 127);
		
		//removes red light from north light
		gotoxy(42, 5);
		coutchar(0, 127);

		//show green kight on south light
		gotoxy(42, 26);
		coutchar(10, 127);

		//remove red light from south light
		gotoxy(42, 28);
		coutchar(0, 127);


	}

}

/***
turns the red traffic light on
***/
void TrafficLight::turnRed(){
	//turn of yellow light before going red
	yellowLight = false;
	redLight = true;

	if (dir == 'H'){
		
		//show red light on west light
		gotoxy(25, 17);
		coutchar(4, 127);
		
		//removes yellow light on west light
		gotoxy(26, 17);
		coutchar(0, 127);

		//show red light on east light
		gotoxy(59, 17);
		coutchar(4, 127);

		//remove  yellow light on east light
		gotoxy(58, 17);
		coutchar(0, 127);

	}
	else if (dir == 'V'){
		
		//show red light on North side traffic light
		gotoxy(42, 5);
		coutchar(4, 127);
		
		//removes yellow light from north light
		gotoxy(42, 6);
		coutchar(0, 127);

		//show red light on south light
		gotoxy(42, 28);
		coutchar(4, 127);

		//remove yellow light from south light
		gotoxy(42, 27);
		coutchar(0, 127);
	}
}

/***
turns the yellow traffic light on
***/
void TrafficLight::turnYellow(){
	//turn of yellow light before going red
	greenLight = false;
	yellowLight = true;

	if (dir == 'H'){

		//show yellow on west light
		gotoxy(26, 17);
		coutchar(6, 127);

		//removes green from west light
		gotoxy(27, 17);
		coutchar(0, 127);

		//show yellow on east light
		gotoxy(58, 17);
		coutchar(6, 127);

		//removes green from east light
		gotoxy(57, 17);
		coutchar(0, 127);

	}
	else if (dir == 'V'){

		//show yellow on north light
		gotoxy(42, 6);
		coutchar(6, 127);

		//removes green light from north light
		gotoxy(42, 7);
		coutchar(0, 127);

		//show yellow kight on south light
		gotoxy(42, 27);
		coutchar(6, 127);

		//remove green light from south light
		gotoxy(42, 26);
		coutchar(0, 127);


	}

}


TrafficLight::~TrafficLight(){


}

