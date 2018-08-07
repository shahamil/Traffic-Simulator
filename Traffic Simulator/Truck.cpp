#include "Truck.h"
#include "functions.h"

using namespace std;

Truck::Truck(char dir, LightSystem* newSystem)
	:Vehicle(dir, newSystem){
	setDimensions(2, 4);
	setDefaultPos();
}

/***
shifts the posions of the truck to next unit which can
then be utilize to print output based on the specified x or y coordinate
***/
void Truck::shiftPos(){

	//system->deleteBackPos(*back);
	for (int i = 0; i < getWidth(); i++){
		for (int j = 0; j < getHeight(); j++){
			if (getDirection() == 'E' || getDirection() == 'S'){
				mapPos[j][i]++;
			}
			else if (getDirection() == 'W' || getDirection() == 'N'){
				mapPos[j][i]--;
			}
		}
	}
	//system->addBackPos(*back);
}

/***
sets the default positions of the car so it can be ready
to enter the traffic system when called upon on
***/
void Truck::setDefaultPos(){
	switch (getDirection()){
	case 'E':
		setEast();
		front = &mapPos[0][3] - 1;
		back = &mapPos[0][0] - 1;
		//system->addBackPos(*back);
		break;
	case 'W':
		setWest();
		front = &mapPos[0][0] + 1;
		back = &mapPos[0][3] + 5;
		//system->addBackPos(*back);
		break;
	case 'N':
		setNorth();
		front = &mapPos[1][3] - 1;
		back = &mapPos[1][0] + 3;
		//system->addBackPos(*back);
		break;
	case 'S':
		setSouth();
		front = &mapPos[1][0] + 1;
		back = &mapPos[1][3] + 1;
		//system->addBackPos(*back);
		break;
	}
}

/***
sets default position for the truck when needed to tavel in the
east direction
***/
void Truck::setEast(){
	mapPos[0][3] = -1;
	mapPos[1][3] = -1;
	
	mapPos[0][2] = -2;
	mapPos[1][2] = -2;

	mapPos[0][1] = -3;
	mapPos[1][1] = -3;

	mapPos[0][0] = -4;
	mapPos[1][0] = -4;	
}

/***
sets default position for the truck when needed to tavel in the
west direction
***/
void Truck::setWest(){
	mapPos[0][3] = 88;
	mapPos[1][3] = 88;

	mapPos[0][2] = 87;
	mapPos[1][2] = 87;

	mapPos[0][1] = 86;
	mapPos[1][1] = 86;

	mapPos[0][0] = 85;
	mapPos[1][0] = 85;
}

/***
sets default position for the truck when needed to tavel in the
north direction
***/
void Truck::setNorth(){

	mapPos[1][3] = 35;
	mapPos[0][3] = 35;
	
	mapPos[1][2] = 36;
	mapPos[0][2] = 36;

	mapPos[1][1] = 37;
	mapPos[0][1] = 37;

	mapPos[1][0] = 38;
	mapPos[0][0] = 38;

}

/***
sets default position for the car when needed to tavel in the
south direction
***/
void Truck::setSouth(){
	mapPos[1][0] = -1;
	mapPos[0][0] = -1;

	mapPos[1][1] = -2;
	mapPos[0][1] = -2;

	mapPos[1][2] = -3;
	mapPos[0][2] = -3;

	mapPos[1][3] = -4;
	mapPos[0][3] = -4;
}

/***
prints the truck going in east direction based on it's current location of the map as well
assits in retain the grey road as its being moved up during the simulation
***/
void Truck::East(){
	//one
	//system->deleteBackPos(*back);
	if (mapPos[0][3] >= 0 && mapPos[0][3] < 85){
		gotoxy(mapPos[0][3], 20);
		coutchar(getColour(), 219);
		gotoxy(mapPos[1][3], 21);
		coutchar(getColour(), 219);
	}
	if (mapPos[0][2] >= 0 && mapPos[0][2] < 85){
		gotoxy(mapPos[0][2], 20);
		coutchar(getColour(), 219);
		gotoxy(mapPos[1][2], 21);
		coutchar(getColour(), 219);
	}
	if (mapPos[0][1] >= 0 && mapPos[0][1] < 85){
		//two
		gotoxy(mapPos[0][1], 20);
		coutchar(getColour(), 219);
		gotoxy(mapPos[1][1], 21);
		coutchar(getColour(), 219);
	}
	if (mapPos[0][0] >= 0 && mapPos[0][0] < 85){
		//three
		gotoxy(mapPos[0][0], 20);
		coutchar(getColour(), 219);
		gotoxy(mapPos[1][0], 21);
		coutchar(getColour(), 219);
	}

	if (mapPos[0][0] > 0 && mapPos[0][0] <= 85){
		//retain road colour
		gotoxy(mapPos[0][0] - 1, 20);
		coutchar(8, 219);
		gotoxy(mapPos[1][0] - 1, 21);
		coutchar(8, 219);
	}
	shiftPos();
	//system->addBackPos(*back);
}

/***
prints the truck going in west direction based on it's current location of the map as well
assits in retain the grey road as its being moved up during the simulation
***/
void Truck::West(){

	if (mapPos[0][0] <= 84 && mapPos[0][0] > -1){
		gotoxy(mapPos[0][0], 13);
		coutchar(getColour(), 219);
		gotoxy(mapPos[1][0], 14);
		coutchar(getColour(), 219);
	}
	if (mapPos[0][1] <= 84 && mapPos[0][1] > -1){
		//two
		gotoxy(mapPos[0][1], 13);
		coutchar(getColour(), 219);
		gotoxy(mapPos[1][1], 14);
		coutchar(getColour(), 219);
	}

	//one
	if (mapPos[0][2] <= 84 && mapPos[0][2] > -1){
		gotoxy(mapPos[0][2], 13);
		coutchar(getColour(), 219);
		gotoxy(mapPos[1][2], 14);
		coutchar(getColour(), 219);
	}

	if (mapPos[0][3] <= 84 && mapPos[0][3] > -1){
		gotoxy(mapPos[0][3], 13);
		coutchar(getColour(), 219);
		gotoxy(mapPos[1][3], 14);
		coutchar(getColour(), 219);
	}

	if (mapPos[0][3] < 84 && mapPos[0][3] >= -1){
		//retain road colour
		gotoxy(mapPos[0][3] + 1, 13);
		coutchar(8, 219);
		gotoxy(mapPos[1][3] + 1, 14);
		coutchar(8, 219);
	}

	shiftPos();

}

/***
prints the truck going in north direction based on it's current location of the map as well
assits in retain the grey road as its being moved up during the simulation
***/
void Truck::North(){

	if (mapPos[1][3] <= 34 && mapPos[1][3] > -1){
		gotoxy(45, mapPos[1][3]);
		coutchar(getColour(), 219);
		gotoxy(46, mapPos[0][3]);
		coutchar(getColour(), 219);
	}

	if (mapPos[1][1] <= 34  && mapPos[1][2] > -1){
		gotoxy(45, mapPos[1][2]);
		coutchar(getColour(), 219);
		gotoxy(46, mapPos[0][2]);
		coutchar(getColour(), 219);
	}

	if (mapPos[1][1] <= 34 && mapPos[1][1] > -1){
		gotoxy(45, mapPos[1][1]);
		coutchar(getColour(), 219);
		gotoxy(46, mapPos[0][1]);
		coutchar(getColour(), 219);
	}

	if (mapPos[1][0] <= 34 && mapPos[1][0] > -1){
		gotoxy(45, mapPos[1][0]);
		coutchar(getColour(), 219);
		gotoxy(46, mapPos[0][0]);
		coutchar(getColour(), 219);
	}

	if (mapPos[1][0] < 34 && mapPos[1][0] >= -1){
		gotoxy(45, mapPos[1][0] + 1);
		coutchar(8, 219);
		gotoxy(46, mapPos[0][0] + 1);
		coutchar(8, 219);
	}

	shiftPos();
}

/***
prints the truck going in sout direction based on it's current location of the map as well
assits in retain the grey road as its being moved up during the simulation
***/
void Truck::South(){
	//south bound car traffic 

	if (mapPos[1][0] >= 0 && mapPos[1][0] < 35){
		gotoxy(35, mapPos[1][0]);
		coutchar(getColour(), 219);
		gotoxy(36, mapPos[0][0]);
		coutchar(getColour(), 219);
	}

	if (mapPos[1][1] >= 0 && mapPos[1][1] < 35){
		gotoxy(35, mapPos[1][1]);
		coutchar(getColour(), 219);
		gotoxy(36, mapPos[0][1]);
		coutchar(getColour(), 219);
	}

	if (mapPos[1][2] >= 0 && mapPos[1][2] < 35){
		gotoxy(35, mapPos[1][2]);
		coutchar(getColour(), 219);
		gotoxy(36, mapPos[0][2]);
		coutchar(getColour(), 219);
	}

	if (mapPos[1][3] >= 0 && mapPos[1][3] < 35){
		gotoxy(35, mapPos[1][3]);
		coutchar(getColour(), 219);
		gotoxy(36, mapPos[0][3]);
		coutchar(getColour(), 219);
	}

	if (mapPos[1][3] > 0 && mapPos[1][3] <= 35){
		//replace the road 
		gotoxy(35, mapPos[1][3] - 1);
		coutchar(8, 219);
		gotoxy(36, mapPos[0][3] - 1);
		coutchar(8, 219);
	}

	shiftPos();
}

/***
This function defines the movement of the car during each time unit within the simulation.
Helps the car make simple decisions wether to stop due to a traffic light scenrios (e.g red light)
***/
void Truck::move(){
	int remainTime;
	TrafficLight *eastWest = system->getEastWestLight();
	TrafficLight *northSouth = system->getNorthSouthLight();
	char direction = getDirection();
	switch (direction){
	case 'E':
		if (system->detectCar(*front + 1) == false){
			if (*front != interEast - 1){
				East();
			}
			else if (*front == interEast - 1){
				if (eastWest->getStateRed() != true){
					if (eastWest->getStateYellow() == true){
						remainTime = (eastWest->getGreenTime() + eastWest->getYellowTime() - system->getCounter());
						if (remainTime >= eastWest->getYellowTime()){
							East();
						}
					}
					else{
						East();
					}
				}
			}
		}
		break;
	case 'W':
		if (*front != interWest + 1){
			West();
		}
		else if (*front == interWest + 1){
			if (eastWest->getStateRed() != true){
				if (eastWest->getStateYellow() == true){
					remainTime = (eastWest->getGreenTime() + eastWest->getYellowTime() - system->getCounter());
					if (remainTime >= eastWest->getYellowTime()) {
						West();
					}
				}
				else{
					West();
				}
			}
		}
		break;
	case 'N':
		if (*front != interNorth + 1){
			North();
		}
		else if (*front == interNorth + 1){
			if (northSouth->getStateRed() != true){
				North();
				remainTime = (northSouth->getGreenTime() + northSouth->getYellowTime() - system->getCounter());
				if (remainTime >= northSouth->getYellowTime()){
					if (northSouth->getStateYellow() == true){
						North();
					}
				}
				else{
					North();
				}
			}
		}
		break;
	case 'S':
		if (*front != interSouth - 1){
			South();
		}
		else if (*front == interSouth - 1){
			if (northSouth->getStateRed() != true){
				South();
				remainTime = (northSouth->getGreenTime() + northSouth->getYellowTime() - system->getCounter());
				if (remainTime >= northSouth->getYellowTime()){
					if (northSouth->getStateYellow() == true){
						South();
					}
				}
				else{
					South();
				}
			}
		}
		break;

	}

}

Truck::~Truck(){


}