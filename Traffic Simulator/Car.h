#ifndef CAR_H
#define CAR_H
#include "Vehicle.h"

class Car : public Vehicle{

public:
	Car(char, LightSystem*);
	~Car();
	virtual void shiftPos();
	
	virtual void East();
	virtual void West();
	virtual void North();
	virtual void South();
	
	virtual void setEast();
	virtual void setWest();
	virtual void setSouth();
	virtual void setNorth();
	
	virtual void setDefaultPos();

	//override and redefine the defenition of this fucntion
	virtual void move();
	
private:
	int mapPos[2][3];
	
};
#endif