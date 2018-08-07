#include <iostream>
#include "LightSystem.h"

LightSystem::LightSystem(){

	counterTime = 1;
}

//returns the value of the current state of the counter
int LightSystem::getCounter(){
	return counterTime;
}

void LightSystem::addBackPos(int back){
	backPos.push_back(back);
}

void LightSystem::deleteBackPos(int back){
	for (int i = 0; i < backPos.size(); i++){
		if (back == backPos[i]){
			backPos.erase(backPos.begin() + i);
			//backPos.clear();
		}
	}
}

bool LightSystem::detectCar(int pos){
	for (int i = 0; i < backPos.size(); i++){
		if (pos == backPos[i]){
			return true;
		}
	}
	return false;
}

/***
this function sets the light cycles for the north-south and east-west traffic lights, 
this is based upon the user input at the beggining of the code.
***/
void LightSystem::setLightCycle(int greenH, int greenV){

	//yellow light receives a time of intersection size + largest vehicle size
	int yellowV = 24 + 4;
	int redV = greenV + yellowV;
	
	//Creates a pointer to the North-South Traffic Light
	northSouth = new TrafficLight(greenV, redV, yellowV, 'V');

	//sets yellow/red light cycles for northbound - southbound lights
	int yellowH = 14 + 4;
	int redH = greenH + yellowH;
	
	//Create a pointer to the East-West traffic Light
	eastWest = new TrafficLight(greenH, redH, yellowH, 'H');

	//calls the function to set the light cycle durations
	eastWest->setLightCycleDuration(greenH, redH, yellowH);
	northSouth->setLightCycleDuration(greenV, redV, yellowV);

	setSystemTime(greenH + redH + yellowH, greenV + redV + yellowV);
}

/***
This function is used to initlaized the system time
***/
void LightSystem::setSystemTime(int sysH, int sysV){
	systemTimeH = sysH;
	systemTimeV = sysV;
}

/***
this function updates the traffic light states after a certain amount of time has passed, the time is based upon the user input
***/
int LightSystem::getSystemTime(){
		return systemTime;
}

//starts the traffic light system which by default east-west light is green
//and north-south light is red
void LightSystem::startSystem(){
	//allow traffic to flow from eastbound/westbound
	eastWest->turnGreen();
	northSouth->turnRed();
	currentCycle = 'H';
}

/***
this will increase the counter time of the light
***/
void LightSystem::increaseCounter(){
	counterTime++;
}

//updates the traffic light states after the a certain time has passed
void LightSystem::checkLightUpdate(){

	if (currentCycle == 'H'){
		if (counterTime == eastWest->getGreenTime()){
			eastWest->turnYellow();
		}
		else if (counterTime == eastWest->getGreenTime() + eastWest->getYellowTime()){
			eastWest->turnRed();
			northSouth->turnGreen();
			counterTime = 1;
			currentCycle = 'V';
		}
	}

	if (currentCycle == 'V'){
		if (counterTime == northSouth->getGreenTime()){
			northSouth->turnYellow();
		}
		else if (counterTime == northSouth->getGreenTime() + northSouth->getYellowTime()){
			northSouth->turnRed();
			eastWest->turnGreen();
			counterTime = 1;
			currentCycle = 'H';
		}
	}
}

/***
this function returns a pointer to the eastWest traffic light
***/
TrafficLight * LightSystem::getEastWestLight(){
	return eastWest;
}

/***
this function returns the NorthSouth traffic light
***/
TrafficLight * LightSystem::getNorthSouthLight(){
	return northSouth;
}

LightSystem::~LightSystem(){
}

 