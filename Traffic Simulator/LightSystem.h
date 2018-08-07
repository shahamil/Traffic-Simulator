#ifndef LightSystem_HEADER
#define LightSystem_HEADER
#include "TrafficLight.h"
#include <iostream>
#include <vector>
using namespace std;

class LightSystem{

public:
	LightSystem();
	~LightSystem();
	void setSystemTime(int, int);
	void startSystem();
	int getSystemTime();
	void increaseCounter();
	void checkLightUpdate();
	void setLightCycle(int, int);
	void addBackPos(int);
	void deleteBackPos(int);
	bool detectCar(int);
	TrafficLight *getEastWestLight();
	TrafficLight *getNorthSouthLight();
	int getCounter();
	


	
private:
	int systemTime;
	int counterTime;
	char currentCycle;
	int systemTimeH;
	int systemTimeV;

	vector<int> backPos;
	//manages the traffic light on the north and south bound directions
	TrafficLight *northSouth;

	//manages the traffic light on the east and west bound directions
	TrafficLight *eastWest;




};

#endif