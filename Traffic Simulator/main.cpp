/************
HEADER:

Author: 
Amil Shah - 100484737 
Ali Karwani – 100555810
Haziq Khilji – 100555455

Date: April 11, 2015

PURPOSE: The purpose of this program is to generate a simulation of a
4 way lane intersection which provide maps of the entrie intersection
which then further is used to examine the current traffic situations
such as number of cars enter the system and leaving the system. The
program allows users to adjust light cycles to see how to maximize 
traffic efficience.
*************/

#include "Place.h"
#include <string>
#include "Car.h"
#include "functions.h"
#include <Windows.h>
#include "LightSystem.h"
#include "Vehicle.h"
#include <vector>
#include <iostream>
#include <stdio.h>
#include <random>
#include "LowMemoryException.h"
#include "UserInputException.h"
#include "ProbabilityZeroException.h"
#include "Truck.h"
#include <exception>
using namespace std;

//helper functions used to help drive the main method
void createVehicles(int);
void deleteVehicles();
void moveCars();
void showCount();

int east = 0;
int west = 0;
int north = 0;
int south = 0;

//this is the container that stores the value of the containers (globally defined)
vector<Vehicle *> vehicles;

//created an istance of the lightSystem created which handle the entire 
//all the traffic light changes for the simulation
LightSystem *traffic = new LightSystem();

int main(){
	Place place;

	//allow user to define traffic simulation parameters
	/**************************/
	int greenTimeH;
	int greenTimeV;
	cout << "Welcome to Traffic Simulationn \n \n";
	cout << "Please enter duration of green light for eastbound - westbound traffic light (please enter a positive integer) \n";

		cin >> greenTimeH;
		if (greenTimeH <= 0){

			//EXCEPTION THROWN: Occurs when user input value is less than or equal to 0
			throw UserInputException(); //terminate program
			exit(1);
		}
	
	cout << "Please enter duration of green light for the northbound - southbound traffic light (please enter a positive integer)\n";
	cin >> greenTimeV;
	if (greenTimeV <= 0){
		
		//EXCEPTION THROWN: Occurs when user input value is greater than or equal to 0
		throw UserInputException(); //terminate the program
		exit(1);
	}
	traffic->setLightCycle(greenTimeH, greenTimeV);
	/**************************/
	
	//enter traffic probability
	/**************************/
	int probaility;
	cout << "Please enter probability of vehicles entering the system (please enter an integer value that is not 0\n";
	cin >> probaility;
	if (probaility == 0){
		throw ProbabilityZeroException(); //terminate the program
		exit(1);
	}
	system("cls");
	/**************************/

	place.setGrass();
	place.setLights();
	
	traffic->startSystem();
	createVehicles(probaility);

	/***
	This for loops runs the entire traffic simulation set to a 
	default duration of 1000 units, pause implmented (1 tenth of a second)
	***/
	showCount();
	for (int i = 0; i < 1000; i++){
		
		traffic->checkLightUpdate();
		
		moveCars();

		Sleep(100);

		traffic->increaseCounter();
		
		//if (vehicles.size() < 50){
		createVehicles(probaility);
		//}

		gotoxy(78, 5);
		coutc(6, vehicles.size());

		gotoxy(78, 29);
		coutc(6, i);

		showCount();
	}
	gotoxy(78, 5);
	coutc(6, vehicles.size());
	system("pause");
	return 0;
}

/***
creates new instances of vehicles to enter the system and are appeneded
to the vehicle container
***/
void createVehicles(int prob){

	//generates random variable
	double randNumb = (double)rand() / (double)RAND_MAX;
	if (randNumb <= (double)1 / prob){

		//****EXCEPTION****:
		//Tries Catch used to see if not enough memory is available
		//to create new Car objects or within the vector of vehicles itself
		try{
			Truck *car1 = new Truck('E', traffic);
			Truck *car2 = new Truck('W', traffic);
			Car *car3 = new Car('N', traffic);
			Car *car4 = new Car('S', traffic);
			vehicles.push_back(car1);
			vehicles.push_back(car2);
			vehicles.push_back(car3);
			vehicles.push_back(car4);
		}
		catch (LowMemoryException &lowMemoryException){
			cout << "Exception Occured: " << lowMemoryException.what() << endl;
		}
	}
}

/***
tells each vehicle to move one unit ahead if its clear to go within the simulation
***/
void moveCars(){
	for (unsigned int i = 0; i < vehicles.size(); i++){
		Vehicle *currentCar = dynamic_cast<Vehicle *>(vehicles[i]);
		//string sClass = typeid(*currentCar).name();
		string sClass = typeid(vehicles[i]).name();
		if (sClass == "class Car"){
			currentCar = dynamic_cast<Car *>(vehicles[i]);
		}
		else if (sClass == "class Truck"){
			currentCar = dynamic_cast<Truck *>(vehicles[i]);
		}
			if ((currentCar->getDirection() == 'E' && currentCar->getBack() == 83) || 
				(currentCar->getDirection() == 'W' && currentCar->getBack() == -1)){
				north++;
				south++;
				vehicles.erase(vehicles.begin() + i);


			}
			else if ((currentCar->getDirection() == 'N' && currentCar->getBack() == -1) ||
				(currentCar->getDirection() == 'S' && currentCar->getBack() == 35)){
				east++;
				west++;
				vehicles.erase(vehicles.begin() + i);
			
			}
			else{
				currentCar->move();
			
		}
	}
}

void showCount(){
	gotoxy(80, 4);
	coutc(6, east);

	gotoxy(80, 5);
	coutc(6, west);

	gotoxy(80, 6);
	coutc(6, north);
	
	gotoxy(80, 7);
	coutc(6, south);
}