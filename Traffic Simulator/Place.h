#ifndef PLACE_H
#define PLACE_H
class Place{

public:
	Place();
	void setGrass();
	void setLights();
	~Place();

private:
	int mapArray[35][85];


};
#endif